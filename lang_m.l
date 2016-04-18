%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    using  namespace  std;
    #include "sang_m.tab.h"   //  output  of  bison on  example1.y
    void  yyerror(char *);
    int  yyparse(void);
%}
%option noyywrap
%option yylineno

%%
[ \t\n]+                  ;   // do  nothing  on  whitespace
"print"                   return  PRINT;
"="                        {return  EQUALS;}
"+"                        {return  PLUS;}
"-"                        {return  MINUS;}
"*"                        {return  ASTERISK;}
"/"                        {return  FSLASH;}
"("                        {return  LPAREN;}
")"                        {return  RPAREN;}
";"                        {return  SEMICOLON;}
[a-zA -Z][a-zA -Z0 -9]*    {yylval.str_val = new  string(yytext );  return  VARIABLE ;}
[0 -9][0 -9]*(.[0 -9]+)?   {yylval.double_val = atof(yytext );  return  NUMBER ;}
<<EOF>>             {printf("END\n");exit(0);}
%%
void  yyerror(char* str) {printf("Parse  Error: \n%s\n",str );}


int  main(int  num_args , char** args) {
    if(num_args  != 2) {printf("usage: ./ parser1  filename\n"); exit (0);}
    FILE* file = fopen(args[1],"r");
    if(file == NULL) {printf("couldn 't open %s\n", args [1]);  exit (0);}
    yyin = file;   // now  flex  reads  from  file
    yyparse ();
    fclose(file);
}