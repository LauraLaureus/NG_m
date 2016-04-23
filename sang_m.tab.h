/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASIGNA = 258,
     ABRECORCHETES = 259,
     CIERRACORCHETES = 260,
     COMA = 261,
     RESERVAESPACIO = 262,
     SUMA = 263,
     MENOS = 264,
     DIVIDE = 265,
     MULTIPLICA = 266,
     OR = 267,
     AND = 268,
     NOT = 269,
     IGUALVALOR = 270,
     DISTINTOVALOR = 271,
     MAYORQUE = 272,
     MENORQUE = 273,
     MAYORIGUAL = 274,
     MENORIGUAL = 275,
     INPUT = 276,
     OUTPUT = 277,
     FUNC = 278,
     INICIO = 279,
     ABRELLAVES = 280,
     CIERRALLAVES = 281,
     GLOBAL = 282,
     ABREPARENTESIS = 283,
     CIERRAPARENTESIS = 284,
     DEVUELVE = 285,
     IF = 286,
     WHILE = 287,
     VARIABLE = 288,
     REAL = 289,
     PUNTOYCOMA = 290,
     VECTOR = 291,
     STRING = 292,
     VALORREAL = 293,
     VALORVECTOR = 294
   };
#endif
/* Tokens.  */
#define ASIGNA 258
#define ABRECORCHETES 259
#define CIERRACORCHETES 260
#define COMA 261
#define RESERVAESPACIO 262
#define SUMA 263
#define MENOS 264
#define DIVIDE 265
#define MULTIPLICA 266
#define OR 267
#define AND 268
#define NOT 269
#define IGUALVALOR 270
#define DISTINTOVALOR 271
#define MAYORQUE 272
#define MENORQUE 273
#define MAYORIGUAL 274
#define MENORIGUAL 275
#define INPUT 276
#define OUTPUT 277
#define FUNC 278
#define INICIO 279
#define ABRELLAVES 280
#define CIERRALLAVES 281
#define GLOBAL 282
#define ABREPARENTESIS 283
#define CIERRAPARENTESIS 284
#define DEVUELVE 285
#define IF 286
#define WHILE 287
#define VARIABLE 288
#define REAL 289
#define PUNTOYCOMA 290
#define VECTOR 291
#define STRING 292
#define VALORREAL 293
#define VALORVECTOR 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "sang_m.y"
{
    Node    node;
    Asignation* r_asignation;
    Math_Expression* expression;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
/* Line 1529 of yacc.c.  */
#line 137 "sang_m.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

