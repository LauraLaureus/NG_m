%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <vector>
    #include  <fstream>
    #include  <iostream>
    #include  <sstream>
    
    
    #include "ASTNodes.hpp"
    #include "SymbolTable.hpp"
    #include "data_type.h"
    
    using  namespace  std;
    
    vector<Node*> param_vector;
    vector<Node*> lines_vector;
    vector<Node*> spaces_vector;
    vector<double> current_vector;
    vector<Node*> func_param_vector;
    
    vector<string> nameStack;
    
    SymbolTable ts;
    
    int current_depth;
    
    extern FILE *yyin;
    extern  int  yylex ();
    extern  void  yyerror(char *);
    
    void  yyerror(char *);
    void buildCheckForErrors();
    void stringStack(string* dst );
    bool heightSearch(string* target, int max);
    std::string int_to_hexString(int);
    
    void generateCodeFromAST(char*);
    void checkErrors();
    
    int codeLabel = 0;
    int statLabel = 0;
    int label = 0;
    int functionLabel = 1000;
    int staticMem = 73728; // 0x12000 hex
    int relativePositionToR6 = 0;
    
    %}

%locations

%union {
    Node*    node;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val>    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC  ABRELLAVES CIERRALLAVES GLOBAL ABREPARENTESIS CIERRAPARENTESIS DEVUELVE IF WHILE BREAK CALL
%token <str_val>    VARIABLE REAL PUNTOYCOMA VECTOR STRING INICIO
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR

%type<int_val> operacion
%type<node> termino line declaracion llamadaFuncion devolucion devuelve funcion lineas variablesGlobales asignacion expresion



%start  parsetree

%left SUMA MENOS
%left DIVIDE MULTIPLICA
%nonassoc OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MAYORIGUAL MENORQUE MENORIGUAL

%%


parsetree: { spaces_vector = *new vector<Node*>(); current_depth = 0; ts = *new SymbolTable(); nameStack = *new std::vector<string>();} espacios {}
|error { spaces_vector.clear(); lines_vector.clear(); param_vector.clear(); current_vector.clear(); current_depth = 0;} // colocamos el error en la raíz del árbol para limpiar facilmente el árbol de nodos.
;

espacios: {current_depth -= 1;}
|{ current_depth += 1;} variablesGlobales {spaces_vector.push_back($2); current_depth -= 1;}espacios
|{ current_depth += 1;} funcion {spaces_vector.push_back($2);current_depth -= 1;}espacios
;

variablesGlobales:  GLOBAL declaracion PUNTOYCOMA
{
    $$ = new GlobalVar($2);
    if(Declaration* n = dynamic_cast<Declaration*>($2)){
        DataType type;
        if(n->isReal()){
            type = real;
        }else{
            type = DataTypeVector;
        }
        SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,$2);
        ts.insertRecord(*(n->getIdentification()), record );
    }
};



funcion: FUNC INICIO
{
    nameStack.push_back("inicio");
    DataType type = initFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord("inicio", record);
    
}
bloque
{
    $$ = new FunctionDefinition($2,ts.getNodeVector("inicio"));
    nameStack.pop_back();
}
|FUNC VARIABLE ABREPARENTESIS //Hey yu //Sigue por aquí :D

{
    nameStack.push_back(*$2);
    DataType type = voidFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    record.setAddress(functionLabel);
    ts.insertRecord(*$2, record);
    param_vector = *new vector<Node*>();
    
    functionLabel -= 1;
}
parametros CIERRAPARENTESIS bloque
{
    $$ = new FunctionDefinition($2,param_vector,ts.getNodeVector(*$2));
    nameStack.pop_back();
}

|FUNC REAL VARIABLE ABREPARENTESIS
{
    nameStack.push_back(*$3);
    DataType type = realFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    record.setAddress(functionLabel);
    ts.insertRecord(*$3, record);
    param_vector = *new vector<Node*>();
    functionLabel -= 1;
    
}
parametros CIERRAPARENTESIS
{
    func_param_vector = param_vector;
}
ABRELLAVES lineas devuelve CIERRALLAVES
{
    ts.setParams(param_vector,*$3);
    $$ = new FunctionDefinition($3,func_param_vector,ts.getNodeVector(*$3),true,$11);
    SymbolTableRecord* r = ts.getRecord(*$3);
    r->setFunctionDefinition($$);
    nameStack.pop_back();
}
;



line:declaracion PUNTOYCOMA
{
    $$ = $1;
    string blockName;
    stringStack(&blockName);
}

|asignacion PUNTOYCOMA
{
    $$ = $1;
    string blockName;
    stringStack(&blockName);
}

|IF
{
    nameStack.push_back("If");
    string blockName;
    stringStack(&blockName);
    DataType type = flowControlIf;
    SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord(blockName, record);
    
}
ABREPARENTESIS expresion CIERRAPARENTESIS bloque
{
    string blockName;
    stringStack(&blockName);
    $$ = new FlowControl(false,$4,ts.getNodeVector(blockName));
    ts.removeRecord(blockName);
    nameStack.pop_back();
}
//////////////////////_________________________________________________________
|WHILE
{
    nameStack.push_back("While");
    string blockName;
    stringStack(&blockName);
    DataType type = flowControlIf;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord(blockName, record);
    
}
ABREPARENTESIS expresion CIERRAPARENTESIS bloque
{
    string blockName;
    stringStack(&blockName);
    $$ = new FlowControl(true,$4,ts.getNodeVector(blockName));
    ts.removeRecord(blockName);
    nameStack.pop_back();
}

|VARIABLE ASIGNA INPUT PUNTOYCOMA
{
    $$ = new AsignationInput();
    if(!heightSearch($1, current_depth)  ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
    
}

|VARIABLE ASIGNA llamadaFuncion PUNTOYCOMA
{
    $$ = new AsignationFunctionCall($1,$3);
    if(!ts.exists(*$1)){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
    //if(!heightSearch($1, current_depth)  ){
    //
    //} //TODO control de errores: controlar que la funcion que se llama existe tras construir todo el árbol.
}
| llamadaFuncion PUNTOYCOMA
{
    //$$ = new AsignationFunctionCall(nullptr,$2);
}

|OUTPUT VARIABLE PUNTOYCOMA
{
    $$ = new Output_Expression(true, $2);
    int n = ts.exists(*$2);
    if(n == -1 || n > current_depth){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
|OUTPUT STRING PUNTOYCOMA
{
    $$ = new Output_Expression(false, $2);
}
|BREAK PUNTOYCOMA
{
    $$ = new BreakNode();
    string blockName;
    stringStack(&blockName);
    if(blockName.find("While") == std::string::npos){
        yyerror("TU TAS TO LOCO PEPE JUAN para que haces un break fuera de un while tas tonto ¬¬\n");
    }
}
;

bloque: ABRELLAVES {current_depth += 1;} lineas { current_depth -= 1;}CIERRALLAVES ;

lineas:  line
{
    string blockName;
    stringStack(&blockName);
    ts.saveNode(blockName,$1);
}lineas

|line
{
    string blockName;
    stringStack(&blockName);
    ts.saveNode(blockName,$1);
}
;

devuelve: DEVUELVE devolucion PUNTOYCOMA { $$ = new ReturnNode($2);};

devolucion: VALORREAL  {$$ = new Math_Term<double>($1);}
| VARIABLE {$$ = new Math_Term<std::string>(*$1);}
;


llamadaFuncion: CALL VARIABLE ABREPARENTESIS {param_vector = *new std::vector<Node*>();} parametros CIERRAPARENTESIS { $$ = new FunctionCall($2,param_vector);}
;

parametros:
| declaracion
{
    param_vector.push_back($1);
}

| declaracion { param_vector.push_back($1);} COMA parametros
;


vectorNT: ABRECORCHETES {current_vector = *new vector<double>();} elementos CIERRACORCHETES;

elementos: VALORREAL {current_vector.push_back($1);}
| VALORREAL COMA elementos {current_vector.push_back($1);}
;

termino: VALORREAL {$$ = new Math_Term<double>($1);}
|VARIABLE {$$ = new Math_Term<std::string>(*$1);}
;

operacion: SUMA {$$ = '+';}
| MENOS {$$ = '-';}
|DIVIDE {$$ = '/';}
|MULTIPLICA {$$ = '*';}
|OR {$$ = '|';}
|AND {$$ = '&';}
|NOT {$$ = '!';}
|IGUALVALOR {$$ = '=';}
|DISTINTOVALOR {$$ = '~';}
|MAYORQUE {$$ = '>';}
|MAYORIGUAL {$$ = 'Z';}
|MENORQUE {$$ = '<';}
|MENORIGUAL {$$ = 'z';}
;

expresion: termino operacion termino
{
    $$ = new  Math_Expression($1,$2,$3);
}; //expresssionnnnn fin


declaracion: REAL VARIABLE
{
    
    if(!heightSearch($2, current_depth)){
        
        DataType type = real ;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*$2, record);
    }
    $$ = new Declaration($2,true);
    
}
|VECTOR VARIABLE
{
    if(!heightSearch($2, current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*$2, record);
    }
    
    $$ = new Declaration($2,false);
};


asignacion: REAL VARIABLE ASIGNA VALORREAL
{
    $$ = new REAL_Asignation(true, $2, $4);
    if(heightSearch($2,1)){
        ts.saveNode(*$2,$$);
    }
    else if(!heightSearch($2, current_depth)){
        DataType type = real ;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*$2, record);
    }
    
}
|VECTOR VARIABLE ASIGNA vectorNT
{
    $$ = new VECTOR_Asignation(true, $2,current_vector,current_vector.size());
    current_vector.clear();
    if(heightSearch($2,1)){
        ts.saveNode(*$2,$$);
    }
    else if(!heightSearch($2, current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>(),current_vector);
        ts.insertRecord(*$2, record);
    }
}
|VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
{
    $$ = new VECTOR_Asignation(true, $2, *new std::vector<double>,(int)$6);
    if(heightSearch($2,1)){
        ts.saveNode(*$2,$$);
    }
    else if(!heightSearch($2, current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*$2, record);
    }
}

|VARIABLE ASIGNA expresion{
    $$ = new Expression2Var($1,$3);
    
    if(!ts.exists(*$1)){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}

|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
{
    $$ = new ELEM_VECTOR_Asignation($1,(int)$3,$6);
    
    if(!ts.exists(*$1)){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA expresion
{
    $$ = new Expression2Var($1,$3,$6);
    
    if(!ts.exists(*$1)){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
|VARIABLE ASIGNA VARIABLE
{
    $$ = new VAR2VAR_Asignation($1,$3);
    if(!ts.exists(*$1) || !ts.exists(*$3) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
|VARIABLE ASIGNA VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES
{
    $$ = new  ELEM_VECTOR2VAR_Asignation ($3,$5, $1);
    if(!ts.exists(*$1) || !ts.exists(*$3) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
|VARIABLE ASIGNA VARIABLE ABRECORCHETES  VARIABLE CIERRACORCHETES
{
    $$ = new  ELEM_VECTOR2VAR_Asignation ($3,$5, $1);
    if(!ts.exists(*$1) || !ts.exists(*$3) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
}
; //fin asignacion

%%
void buildCheckForErrors(){
    printf("Jeronimo");
}

void stringStack(string* dst ){
    for(int i = 0; i < nameStack.size(); i++){
        (*dst) += nameStack[i];
    }
}


bool heightSearch(string* target, int max){
    for(int i = 0; i < spaces_vector.size();i++){
        if(spaces_vector[i]->searchByHeight( target,0,max)) return true;
    }
    return false;
}


void  yyerror(char* str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n",yylineno,str );
    exit(-1);
    
}

std::string int_to_hexString(int c){
    std::stringstream stream ;
    stream << "0x" << std::hex << c;
    return stream.str();
    
}

void generateCodeFromAST(char* filename){
    
    
    
    string filename_e (filename);
    filename_e += ".q.c";
    string header = "#include \"Q.h\"\n\
    BEGIN\n";
    
    ofstream objFile;
    objFile.open(filename_e);
    
    objFile << header ;
    
    //CodeGeneration here
    // set global vars
    
    //TODO check global vars numbers
    std::vector<std::string> globals = ts.getGlobalVars();
    objFile << "\tSTAT(0)\n";
    for(int i = 0; i < globals.size(); i++){
        if(ts[globals[i]].getType() == real){
            staticMem -= sizeof(double);
            objFile << "\tMEM("+int_to_hexString(staticMem)+"," + std::to_string(sizeof(double)) +");\n" ;
        }
        else{ //se guarda una dirección donde estará reservado el vector.
            staticMem -= sizeof(double)*10;
            objFile << "\tFIL("+int_to_hexString(staticMem)+",10,0);\n" ;
        }
        ts.setAddress(globals[i],staticMem);
    }
    
    
    objFile << "\tCODE(0)\n";
    vector<SymbolTableRecord*> nonInitFunction = ts.getNonInitFunctions();
    
   
   printf("N non init functions %d\n", nonInitFunction.size());
    for(int i = 0; i < nonInitFunction.size(); i++){
        
        objFile << "L " + std::to_string(nonInitFunction[i]->getAddress()) + ":";
        std::string r = nonInitFunction[i]->functionDefinition->generateCode(&codeLabel, &statLabel,&staticMem,&ts);
        
        objFile << r;
        
    }
    
    SymbolTableRecord initFunc = ts.getInit();
    
    
   
    //codeLabel +=1;
    objFile << "L 0:";
    vector<Node*> mainFuncNodes = initFunc.getNodeStack();
    
    objFile << "\tR6=R7;\n";
    
    relativePositionToR6 = 0;
    for(int i = 0; i < mainFuncNodes.size(); i++){
        objFile << mainFuncNodes[i]->generateCode(&codeLabel, &statLabel,&staticMem,&ts);
    }
    objFile << "GT(-2);\n" ;
    objFile << "END" ;
    
    objFile.close();
    
}

void checkErrors(){
    if(!ts.hasOnlyInit()){
        printf("Se ha detectado varias funciones de inicio o ninguna. Solo se permite que haya una.\n");
        exit(-1);
    }
}

int  main(int  num_args , char** args) {
    if(num_args  != 2) {
        printf("usage: ./ parser1  filename\n");
        exit (0);
    }
    FILE* file = fopen(args[1],"r");
    if(file == NULL) {
        printf("couldn 't open %s\n", args [1]);
        exit (0);
    }else{
        yyin = file;   // now  flex  reads  from  file
    }
    yyparse ();
    
    //ts.printState();
    checkErrors();
    generateCodeFromAST(args[1]);
    fclose(file);
    return 0;
}
