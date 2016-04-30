//  BISON  file  example1.y
%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <map>
    #include  <vector>
    #include "ASTNodes.hpp"
    #include "SymbolTable.hpp"
    #include <fstream>
    using  namespace  std;
    vector<Node*> param_vector;
    vector<Node*> lines_vector;
    vector<Node*> spaces_vector;
    vector<double> current_vector;
    SymbolTable ts;
    int current_depth;
    extern FILE *yyin;
    extern  int  yylex ();
    extern  void  yyerror(char *);
    void buildCheckForErrors();
%}

%locations

%union {
    Node*    node;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val>    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC  ABRELLAVES CIERRALLAVES GLOBAL ABREPARENTESIS CIERRAPARENTESIS DEVUELVE IF WHILE BREAK
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


parsetree: { spaces_vector = *new vector<Node*>(); current_depth = 0; ts = *new SymbolTable();} espacios {}
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
        DataType type = initFunction;
        SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord("inicio", record);
    }//Sigue por aquí :D
    bloque
    {
        current_depth -= 1;
        $$ = new FunctionDefinition($2,ts.getNodeVector("inicio"));
    }
    |FUNC VARIABLE ABREPARENTESIS
        {param_vector = *new vector<Node*>();}
    parametros CIERRAPARENTESIS bloque {$$ = new FunctionDefinition($2,param_vector,lines_vector);}
    |FUNC REAL VARIABLE ABREPARENTESIS {param_vector = *new vector<Node*>();} parametros CIERRAPARENTESIS ABRELLAVES lineas devuelve CIERRALLAVES { printf("FUNCIÓN CON DEVOLUCIÓN"); $$ = new FunctionDefinition($3,param_vector,lines_vector,true,$9);}
    ;



line:declaracion PUNTOYCOMA { $$ = $1;}
    |asignacion PUNTOYCOMA { $$ = $1;}
    |IF{ lines_vector.push_back(new NewBlock(0) );} ABREPARENTESIS expresion CIERRAPARENTESIS bloque { $$ = new FlowControl(false,$4,lines_vector); lines_vector.push_back(new ResumeBlock(0) );}
    |WHILE { lines_vector.push_back(new NewBlock(current_depth) );} ABREPARENTESIS expresion CIERRAPARENTESIS bloque {
        lines_vector.push_back(new ResumeBlock(current_depth) );
        std::vector<Node*> whileNodes = *new std::vector<Node*>();
        int i = lines_vector.size()-1;
        int obtained_depth = 0;
        for(; i > 0; i--){
            if(ResumeBlock* b = dynamic_cast<ResumeBlock*>(lines_vector[i])){
               
                obtained_depth = b->getDepth();
                break;
            }
        }
        
        for(; i > 0;i--){
            whileNodes.insert(whileNodes.begin(),lines_vector[i]);
            lines_vector.erase(lines_vector.begin()+i);
            if(NewBlock* n = dynamic_cast<NewBlock*>(whileNodes[0])){
                printf("Stays in vegas");
                break;
            }
        }
        
        $$ = new FlowControl(true,$4,whileNodes);}

    |VARIABLE ASIGNA INPUT PUNTOYCOMA { $$ = new AsignationInput();}
    |VARIABLE ASIGNA llamadaFuncion PUNTOYCOMA {$$ = new AsignationFunctionCall($1,$3);}
    |llamadaFuncion PUNTOYCOMA {$$ = new AsignationFunctionCall(nullptr,$1);}

    |OUTPUT VARIABLE PUNTOYCOMA {$$ = new Output_Expression(true, $2);}
    |OUTPUT STRING PUNTOYCOMA { $$ = new Output_Expression(false, $2);}
    |BREAK PUNTOYCOMA {$$ = new BreakNode();}
    ;

bloque: ABRELLAVES {current_depth += 1;lines_vector = *new std::vector<Node*>();} lineas { current_depth -= 1;}CIERRALLAVES ;

lineas:  line {lines_vector.push_back($1);} lineas
| line {lines_vector.push_back($1);}
;

devuelve: DEVUELVE devolucion PUNTOYCOMA { $$ = new ReturnNode($2);};

devolucion: VALORREAL  {$$ = new Math_Term<double>($1);}
| VARIABLE {$$ = new Math_Term<std::string>(*$1);}
;


llamadaFuncion: VARIABLE ABREPARENTESIS {param_vector = *new std::vector<Node*>();} parametros CIERRAPARENTESIS { $$ = new FunctionCall($1,param_vector);}
;

parametros:
| declaracion { param_vector.push_back($1);}
| declaracion { param_vector.push_back($1);} COMA parametros
;


vectorNT: ABRECORCHETES {current_vector = *new vector<double>();} elementos CIERRACORCHETES;

elementos: VALORREAL {current_vector.push_back($1);}
        | VALORREAL COMA elementos {current_vector.push_back($1);}
        ;

termino: VALORREAL {$$ = new Math_Term<double>($1);}
        |VARIABLE {$$ = new Math_Term<std::string>(*$1);}
        ;

operacion: SUMA
        | MENOS
        |DIVIDE
        |MULTIPLICA
        |OR
        |AND
        |NOT
        |IGUALVALOR
        |DISTINTOVALOR
        |MAYORQUE
        |MAYORIGUAL
        |MENORQUE
        |MENORIGUAL
        ;

expresion: termino operacion termino
{
    $$ = new  Math_Expression($1,$2,$3);
}; //expresssionnnnn fin


declaracion: REAL VARIABLE
{
    $$ = new Declaration($2,true);
}
            |VECTOR VARIABLE
{ $$ = new Declaration($2,false);}
            ;

asignacion: REAL VARIABLE ASIGNA VALORREAL
{
    $$ = new REAL_Asignation(true, $2, $4);
}
|VECTOR VARIABLE ASIGNA vectorNT
{
    $$ = new VECTOR_Asignation(true, $2, current_vector,current_vector.size());
    current_vector.clear();
}
|VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
{
    $$ = new VECTOR_Asignation(true, $2, *new std::vector<double>,(int)$6);
}
|VARIABLE ASIGNA expresion{
    $$ = new Expression2Var($1,$3);
}
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
{
    $$ = new ELEM_VECTOR_Asignation($1,(int)$3,$6);
}
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA expresion
{
    $$ = new Expression2Var($1,$3,$6);
}
|VARIABLE ASIGNA VARIABLE
{
    $$ = new VAR2VAR_Asignation($1,$3);
}
|VARIABLE ASIGNA VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES
{
    $$ = new  ELEM_VECTOR2VAR_Asignation ($3,$5, $1);
}
|VARIABLE ASIGNA VARIABLE ABRECORCHETES  VARIABLE CIERRACORCHETES
{
    $$ = new  ELEM_VECTOR2VAR_Asignation ($3,$5, $1);
}
; //fin asignacion

%%
void buildCheckForErrors(){
    printf("Jeronimo");
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
    for(int i = 0; i < spaces_vector.size();i++){
        spaces_vector[i]->roam();
    }
    ts.printState();
    fclose(file);
    return 0;
}
