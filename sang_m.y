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
    string* str_val;
}
%token <int_val >     ASIGNA ABRECORCHETES CIERRACORCHETES COMA
%token <str_val >    VARIABLE REAL PUNTOYCOMA VECTOR
%token <double_val > VALORREAL
%token <vector_val> VALORVECTOR

%start  parsetree

%%


parsetree:     lines;

lines:          lines  line | line;

line: //REAL {printf("Token:real \n");}
    //|VARIABLE {printf("Token:nombre variable \n");}
    //|PUNTOYCOMA {printf("Token: punto y coma");}
    //|VECTOR {printf("Token: VECTOR");}
    |REAL VARIABLE PUNTOYCOMA {printf("DECLARACION \n");}
    |VECTOR VARIABLE PUNTOYCOMA {printf("DECLARA VECTOR\n");}
    |REAL VARIABLE ASIGNA VALORREAL PUNTOYCOMA {printf("ASIGNA REAL\n");}
|vectorNT {printf("VECTOR VALOR\n");}
;

vectorNT: ABRECORCHETES elementos CIERRACORCHETES ;

elementos: VALORREAL
        | VALORREAL COMA elementos
;

%%
void  Div0Error(void) {printf("Error: division  by zero\n"); exit (0);}
void  UnknownVarError(string s) {printf("Error: %s does  not  exist !\n", s.c_str ());  exit (0);}