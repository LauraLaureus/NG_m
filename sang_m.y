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
    extern  int  yylex ();
    extern  void  yyerror(char *);
    void  Div0Error(void);
    void  UnknownVarError(string s);
%}
%union {
    Node    node;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val >    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC INICIO ABRELLAVES CIERRALLAVES GLOBAL ABREPARENTESIS CIERRAPARENTESIS DEVUELVE IF WHILE
%token <str_val >    VARIABLE REAL PUNTOYCOMA VECTOR
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR

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
    ;

vectorNT: ABRECORCHETES elementos CIERRACORCHETES;

elementos: VALORREAL
        | VALORREAL COMA elementos
        | VALORREAL PUNTOYCOMA elementos
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

asignacion: REAL VARIABLE ASIGNA VALORREAL
        |VECTOR VARIABLE ASIGNA vectorNT
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES ABRECORCHETES VALORREAL CIERRACORCHETES
        |VARIABLE ASIGNA expresion
        ;


%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}