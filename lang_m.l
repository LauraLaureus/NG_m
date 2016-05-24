%{
    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include <vector>
    #include <map>
    #include "ASTNodes.hpp"
    using  namespace  std;
    #include "sang_m.tab.h"   //  output  of  bison
    
    int  yyparse(void);
    extern vector<Node> param_vector;
    extern vector<Node> lines_vector;
    extern vector<Node> spaces_vector;
    extern vector<double> current_vector;
    extern void  yyerror(char *);
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
"parar"                     {return BREAK;}
"llama"                     {return CALL;}
L?\"(\\.|[^\\"])*\"	{yylval.str_val = new  string(yytext ); return STRING; }
{digitos}+("."{digitos})* {yylval.double_val=atof(yytext);return VALORREAL;}
{letras}({letras}|{digitos})*    {yylval.str_val = new  string(yytext ); return  VARIABLE;}
{ignora}+ {;}
.   {yyerror("Unknown character\n"); exit(-1);}

%%



