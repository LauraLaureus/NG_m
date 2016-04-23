%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include <vector>
    #include <map>
    #include "ASTNodes.hpp"
    using  namespace  std;
    #include "sang_m.tab.h"   //  output  of  bison
    void  yyerror(char *);
    int  yyparse(void);
%}
%option noyywrap
%option yylineno

digitos [0-9]
letras [a-zA-Z]
ignora " "|\t|\n

%%
"REAL"                     {return REAL;}
"VECTOR"                   {return VECTOR;}
";"                        {return PUNTOYCOMA;}
"="                        {return ASIGNA;}
"["                        {return ABRECORCHETES;}
"]"                        {return CIERRACORCHETES;}
","                        {return COMA;}
"espacio"                  {return RESERVAESPACIO;}
"+"                        {return SUMA;}
"-"                        {return MENOS;}
"/"                        {return DIVIDE;}
"*"                        {return MULTIPLICA;}
"||"                       {return OR;}
"&&"                       {return AND;}
"!"                        {return NOT;}
"=="                       {return IGUALVALOR;}
"!="                       {return DISTINTOVALOR;}
">"                        {return MAYORQUE;}
">="                       {return MAYORIGUAL;}
"<"                        {return MENORQUE;}
"<="                       {return MENORIGUAL;}
"lee"                      {return INPUT;}
"escribe"                  {return OUTPUT;}
"func"                     {return FUNC;}
"inicio"                   {return INICIO;}
"{"                        {return ABRELLAVES;}
"}"                        {return CIERRALLAVES;}
"global"                   {return GLOBAL;}
")"                        {return CIERRAPARENTESIS;}
"("                        {return ABREPARENTESIS;}
"devuelve"                 {return DEVUELVE;}
"si"                        {return IF;}
"mientras"                  {return WHILE;}
L?\"(\\.|[^\\"])*\"	{yylval.str_val = new  string(yytext ); return STRING; }
{digitos}+("."{digitos})* {yylval.double_val=atof(yytext);return VALORREAL;}
{letras}({letras}|{digitos})*    {yylval.str_val = new  string(yytext ); return  VARIABLE;}
{ignora}+ {;}
<<EOF>>             {printf("\nEND\n");exit(0);}
.   {yyerror("Unknown character\n"); exit(-1);}

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