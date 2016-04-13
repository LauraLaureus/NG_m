%{
    #include <stdio.h>
    #include "sang_m.tab.h"
%}
%option noyywrap
%option yylineno

digitos [0-9]
letras [a-zA-Z]
ignora " "|\t|\n

%%

"si"        {return SI;}
"fin"       {return FIN;}
"caso"      {return CASO;}
"func"      {return COMIENZAFUNCION;}
"nulo"      {return NULO;}
"para"      {return PARA;}
"sino"      {return SINO;}
"final"     {return FINAL;}
"inicio"    {return INICIO;}
"salida"    {return SALIDA;}
"soloSi"    {return SOLOSI;}
"espacio"   {return RESERVAESPACIOVECTOR;}
"devuelve"  {return DEVUELVE;}
"mientras"  {return MIENTRAS;}
"dependeDe" {return DEPENDE;}
"porDefecto" {return PORDEFECTO;}
"REAL"      {return TIPOREAL;}
"VECTOR"    {return TIPOVECTOR;}
"LETRA"     {return TIPOLETRA;}
"lee"       {return LEER;}
"escribe"   {return ESCRIBIR;}

"#"({letras}|{digitos}|[" "|\t|])*[\n]? {;}
{ignora}+   {;}
({letras}){1} {return CARACTER;}
{digitos}+  {yylval.real=atof(yytext);return ENTERO;}
{digitos}+"."{digitos}* {yylval.real=atof(yytext);return REAL;}
{letras}({letras}|{digitos})* {return IDENTIFICADOR;}
. 		  			 		  {return ERROR;}

