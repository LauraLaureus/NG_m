//  BISON  file  example1.y
%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <map>
    #include  <vector>
    #include "ASTNodes.hpp"
    using  namespace  std;
    map <string ,double > vars;    // map  from  variable  name to value
    vector<double>* current_vector;
    extern  int  yylex ();
    extern  void  yyerror(char *);
    void  Div0Error(void);
    void  UnknownVarError(string s);
%}
%union {
    Node    node;
    REAL_Asignation* r_asignation;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val >    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC INICIO ABRELLAVES CIERRALLAVES GLOBAL ABREPARENTESIS CIERRAPARENTESIS DEVUELVE IF WHILE
%token <str_val >    VARIABLE REAL PUNTOYCOMA VECTOR
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR
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
        | VALORREAL PUNTOYCOMA elementos {current_vector->push_back($1);printf("PUSH_BACK\n");}
        ;

termino: VALORREAL
        |VALORVECTOR
        |VARIABLE
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
| OUTPUT VARIABLE  {printf("escribe");}
        ;


parametros:
        | declaracion
        | declaracion COMA parametros
        ;

declaracion: REAL VARIABLE
            |VECTOR VARIABLE
            ;

asignacion: REAL VARIABLE ASIGNA VALORREAL {printf("Asigna valor real\n"); $$ = new REAL_Asignation(true, $2, $3);}
        |VECTOR VARIABLE ASIGNA vectorNT
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES ABRECORCHETES VALORREAL CIERRACORCHETES
        |VARIABLE ASIGNA expresion
        |VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
        |VARIABLE ABRECORCHETES VALORREAL CIERRACORCHETES ABRECORCHETES VALORREAL CIERRACORCHETES ASIGNA VALORREAL
        ;

llamadaFuncion: VARIABLE ABREPARENTESIS parametros CIERRAPARENTESIS
        ;


%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}