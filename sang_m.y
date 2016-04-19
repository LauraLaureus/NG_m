//  BISON  file  example1.y
%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <map>
    #include  <vector>
    using  namespace  std;
    map <string ,double > vars;    // map  from  variable  name to value
    extern  int  yylex ();
    extern  void  yyerror(char *);
    void  Div0Error(void);
    void  UnknownVarError(string s);
%}
%union {
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
%token <int_val >    ASIGNA ABRECORCHETES CIERRACORCHETES COMA RESERVAESPACIO SUMA MENOS DIVIDE MULTIPLICA OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MENORQUE MAYORIGUAL MENORIGUAL INPUT OUTPUT FUNC INICIO ABRELLAVES CIERRALLAVES GLOBAL
%token <str_val >    VARIABLE REAL PUNTOYCOMA VECTOR
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR

%start  parsetree

%left SUMA MENOS
%left DIVIDE MULTIPLICA
%nonassoc OR AND NOT IGUALVALOR DISTINTOVALOR MAYORQUE MAYORIGUAL MENORQUE MENORIGUAL

%%


parsetree: lines ;

lines:  lines  line
    | line
    ;

line: declaracion PUNTOYCOMA {printf("DECLARACION \n");}
    |asignacion PUNTOYCOMA {printf("ASIGNA\n");}
    |expresion PUNTOYCOMA
    |GLOBAL declaracion PUNTOYCOMA  {printf("GLOBAL VAR");}
    |FUNC INICIO ABRELLAVES  lines CIERRALLAVES;
    ;

vectorNT: ABRECORCHETES elementos CIERRACORCHETES;

elementos: VALORREAL
        | VALORREAL COMA elementos
        | VALORREAL PUNTOYCOMA elementos
        ;
expresion: VALORREAL
        |VECTOR
        |expresion SUMA expresion {printf("SUMA");}
        |expresion MENOS expresion {printf("MENOS");}
        |expresion DIVIDE expresion {printf("DIVIDE");}
        |expresion MULTIPLICA expresion {printf("MULTIPLICA");}
        |expresion OR expresion {printf("OR");}
        |expresion AND expresion {printf("AND");}
        |expresion NOT expresion {printf("NOT");}
        |expresion IGUALVALOR expresion {printf("==");}
        |expresion DISTINTOVALOR expresion {printf("!=");}
        |expresion MAYORQUE expresion {printf(">");}
        |expresion MAYORIGUAL expresion {printf(">=");}
        |expresion MENORQUE expresion {printf("<");}
        |expresion MENORIGUAL expresion {printf("<=");}
        |INPUT {printf("lee");}
        |OUTPUT VARIABLE {printf("escribe");}
;

declaracion: REAL VARIABLE
            |VECTOR VARIABLE
            ;

asignacion: REAL VARIABLE ASIGNA VALORREAL
        |VECTOR VARIABLE ASIGNA vectorNT
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES
        |VECTOR VARIABLE ASIGNA RESERVAESPACIO ABRECORCHETES VALORREAL CIERRACORCHETES ABRECORCHETES VALORREAL CIERRACORCHETES
        ;


%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}