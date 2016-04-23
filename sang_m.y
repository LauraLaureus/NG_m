//  BISON  file  example1.y
%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <map>
    #include  <vector>
    #include "ASTNodes.hpp"
    using  namespace  std;
    vector<double>* current_vector;
    vector<Node>* param_vector;
    vector<Node>* lines_vector;
    vector<Node>* spaces_vector;
    int current_vector_dimensions;
    int current_vector_width;
    extern  int  yylex ();
    extern  void  yyerror(char *);
    void  Div0Error(void);
    void  UnknownVarError(string s);
%}
%union {
    Node    node;
    Asignation* r_asignation;
    Expression* expression;
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
%type<node> termino line declaracion llamadaFuncion devolucion devuelve funcion lineas variablesGlobales
%type<expression> expresion
%type<r_asignation> asignacion

%start  parsetree

%left SUMA MENOS
%left DIVIDE MULTIPLICA
%nonassoc OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MAYORIGUAL MENORQUE MENORIGUAL

%%


parsetree: { spaces_vector = new vector<Node>(); }espacios ;

espacios:
    |variablesGlobales {spaces_vector->push_back($1);} espacios
    |funcion {spaces_vector->push_back($1);} espacios
;

variablesGlobales: GLOBAL declaracion PUNTOYCOMA  {printf("GLOBAL VAR\n");$$ = GlobalVar(&$2);}
    ;

funcion: FUNC INICIO ABRELLAVES lineas CIERRALLAVES {printf("FIN FUNCIÓN INICIO\n"); $$ = FunctionDefinition($2,&$4);}
    |FUNC VARIABLE ABREPARENTESIS
        {param_vector = new vector<Node>();}
    parametros CIERRAPARENTESIS bloque {printf("FIN FUNCIÓN \n"); $$ = FunctionDefinition($2,&$4,&$6);}
    |FUNC REAL VARIABLE ABREPARENTESIS {param_vector = new vector<Node>();} parametros CIERRAPARENTESIS ABRELLAVES lineas devuelve CIERRALLAVES { printf("FUNCIÓN CON DEVOLUCIÓN"); $$ = FunctionDefinition($3,&$5,&$8,true,&$9);}
    ;



line:declaracion PUNTOYCOMA {printf("DECLARACION \n"); $$ = $1;}
    |asignacion PUNTOYCOMA {printf("ASIGNA\n"); $$ = *$1;}
    |IF ABREPARENTESIS expresion CIERRAPARENTESIS bloque { printf("IF"); $$ = *new FlowControl(false,$3,lines_vector);}
    |WHILE ABREPARENTESIS expresion CIERRAPARENTESIS bloque { printf("WHILE");  $$ = *new FlowControl(true,$3,lines_vector);}
    |VARIABLE ASIGNA INPUT PUNTOYCOMA {printf("Lee"); $$ = *new AsignationInput();}
    |VARIABLE ASIGNA llamadaFuncion PUNTOYCOMA {printf("llamada funcion \n");$$ = *new AsignationFunctionCall($1,&$3);}
    |OUTPUT VARIABLE PUNTOYCOMA {printf("escribe"); $$ = *new Output_Expression(true, $2);}
    |OUTPUT STRING PUNTOYCOMA {printf("escribe string");  $$ = *new Output_Expression(false, $2);}
    |BREAK PUNTOYCOMA {$$ = *new BreakNode();}
    ;

bloque: ABRELLAVES {lines_vector = new std::vector<Node>();} lineas CIERRALLAVES ;

lineas:  line {lines_vector->push_back($1);} lineas
| line {lines_vector->push_back($1);}
;

devuelve: DEVUELVE devolucion PUNTOYCOMA { $$ = *new ReturnNode(&$2);};

devolucion: VALORREAL  {$$ = *new Math_Term<double>($1);}
| VARIABLE {$$ = *new Math_Term<std::string>(*$1);}
;


llamadaFuncion: VARIABLE ABREPARENTESIS {param_vector = new std::vector<Node>();} parametros CIERRAPARENTESIS { $$ = *new FunctionCall($1,param_vector);}
;

parametros:
| declaracion { param_vector->push_back($1);}
| declaracion { param_vector->push_back($1);} COMA parametros
;


vectorNT: ABRECORCHETES {current_vector = new vector<double>();} elementos { for(int i = 0; i < current_vector->size();i++){printf("%F\n",(*current_vector)[i]);} }CIERRACORCHETES;

elementos: VALORREAL {current_vector->push_back($1);printf("PUSH_BACK\n");}
        | VALORREAL COMA elementos {current_vector->push_back($1);printf("PUSH_BACK\n");}
        ;

termino: VALORREAL {$$ = *new Math_Term<double>($1);}
        |VARIABLE {$$ = *new Math_Term<std::string>(*$1);}
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
{ $$ = *new Declaration($2,true);}
            |VECTOR VARIABLE
{ $$ = *new Declaration($2,false);}
            ;

asignacion: REAL VARIABLE ASIGNA VALORREAL
{
    printf("Asigna valor real\n");
    $$ = new REAL_Asignation(true, $2, $4);
}
|VECTOR VARIABLE ASIGNA vectorNT
{
    printf("Asigna valor vector\n");
    $$ = new VECTOR_Asignation(true, $2, current_vector,current_vector->size());
    current_vector->clear();
}
|VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
{
    printf("Asigna espacio vector\n");
    $$ = new VECTOR_Asignation(true, $2, new std::vector<double>,(int)$6);
}
|VARIABLE ASIGNA expresion{
    printf("Asigna expression a variable\n");
    $$ = new Expression2Var($1,$3);
} //Hey falto yo
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
{
    printf("Asigna valor a elemento de vector\n");
    $$ = new ELEM_VECTOR_Asignation($1,(int)$3,$6);
}
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA expresion
{
    printf("Asigna expression a variable\n");
    $$ = new Expression2Var($1,$3,$6);
}
|VARIABLE ASIGNA VARIABLE
{
    printf("Asigna variable a variable\n");
    $$ = new VAR2VAR_Asignation($1,$3);
}
; //fin asignacion



%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}