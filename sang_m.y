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
    Math_Expression* expression;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val>    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC INICIO ABRELLAVES CIERRALLAVES GLOBAL ABREPARENTESIS CIERRAPARENTESIS DEVUELVE IF WHILE
%token <str_val>    VARIABLE REAL PUNTOYCOMA VECTOR STRING
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR

%type<int_val> operacion
%type<node> termino
%type<expression> expresion
%type<r_asignation> asignacion

%start  parsetree

%left SUMA MENOS
%left DIVIDE MULTIPLICA
%nonassoc OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MAYORIGUAL MENORQUE MENORIGUAL

%%


parsetree: espacios ;

espacios:
    |variablesGlobales espacios
    |funcion espacios
;

variablesGlobales: GLOBAL declaracion PUNTOYCOMA  {printf("GLOBAL VAR\n");}
    ;

funcion: FUNC INICIO ABRELLAVES lineas CIERRALLAVES {printf("FIN FUNCIÓN INICIO\n");}
    |FUNC VARIABLE ABREPARENTESIS parametros CIERRAPARENTESIS bloque {printf("FIN FUNCIÓN \n");}
    |FUNC REAL VARIABLE ABREPARENTESIS parametros CIERRAPARENTESIS ABRELLAVES lineas devuelve CIERRALLAVES { printf("FUNCIÓN CON DEVOLUCIÓN");}
    ;

devuelve: DEVUELVE devolucion PUNTOYCOMA;

devolucion: VALORREAL
    | VARIABLE
    ;

bloque: ABRELLAVES lineas CIERRALLAVES ;


lineas:  line lineas
| line
;

line:declaracion PUNTOYCOMA {printf("DECLARACION \n");}
    |asignacion PUNTOYCOMA {printf("ASIGNA\n");}
    |IF ABREPARENTESIS expresion CIERRAPARENTESIS bloque { printf("IF");}
    |WHILE ABREPARENTESIS expresion CIERRAPARENTESIS bloque { printf("WHILE");}
    |VARIABLE ASIGNA INPUT PUNTOYCOMA {printf("Lee");}
    |VARIABLE ASIGNA llamadaFuncion PUNTOYCOMA {printf("llamada funcion \n");}
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
}
| OUTPUT VARIABLE  {printf("escribe");}
| OUTPUT STRING {printf("escribe string");}
        ; //expresssionnnnn fin


parametros:
        | declaracion
        | declaracion COMA parametros
        ;

declaracion: REAL VARIABLE
            |VECTOR VARIABLE
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
        |VARIABLE ASIGNA expresion
|VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
{
    printf("Asigna valor a elemento de vector\n");
    $$ = new ELEM_VECTOR_Asignation($1,(int)$3,$6);
}
        |VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA expresion
        |VARIABLE ASIGNA VARIABLE
{
    printf("Asigna variable a variable\n");
    $$ = new VAR2VAR_Asignation($1,$3);
}
        ; //fin asignacion



llamadaFuncion: VARIABLE ABREPARENTESIS parametros CIERRAPARENTESIS
        ;


%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}