/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



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
     ABRELLAVES = 279,
     CIERRALLAVES = 280,
     GLOBAL = 281,
     ABREPARENTESIS = 282,
     CIERRAPARENTESIS = 283,
     DEVUELVE = 284,
     IF = 285,
     WHILE = 286,
     BREAK = 287,
     CALL = 288,
     VARIABLE = 289,
     REAL = 290,
     PUNTOYCOMA = 291,
     VECTOR = 292,
     STRING = 293,
     INICIO = 294,
     VALORREAL = 295,
     VALORVECTOR = 296
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
#define ABRELLAVES 279
#define CIERRALLAVES 280
#define GLOBAL 281
#define ABREPARENTESIS 282
#define CIERRAPARENTESIS 283
#define DEVUELVE 284
#define IF 285
#define WHILE 286
#define BREAK 287
#define CALL 288
#define VARIABLE 289
#define REAL 290
#define PUNTOYCOMA 291
#define VECTOR 292
#define STRING 293
#define INICIO 294
#define VALORREAL 295
#define VALORVECTOR 296




/* Copy the first part of user declarations.  */
#line 1 "sang_m.y"

    #include  <stdio.h>
    #include  <stdlib.h>
    #include  <string>
    #include  <vector>
    #include  <fstream>
    #include  <iostream>
    #include  <sstream>
    
    
    #include "ASTNodes.hpp"
    #include "SymbolTable.hpp"
    #include "data_type.h"
    
    using  namespace  std;
    
    vector<Node*> param_vector;
    vector<Node*> lines_vector;
    vector<Node*> spaces_vector;
    vector<double> current_vector;
    vector<Node*> func_param_vector;
    
    vector<string> nameStack;
    
    SymbolTable ts;
    
    int current_depth;
    
    extern FILE *yyin;
    extern  int  yylex ();
    extern  void  yyerror(char *);
    
    void  yyerror(char *);
    void buildCheckForErrors();
    void stringStack(string* dst );
    bool heightSearch(string* target, int max);
    std::string int_to_hexString(int);
    
    void generateCodeFromAST(char*);
    void checkErrors();
    
    int codeLabel = 0;
    int statLabel = 0;
    int label = 0;
    int functionLabel = 1000;
    int staticMem = 73728; // 0x12000 hex
    int relativePositionToR6 = 0;
    
    

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 53 "sang_m.y"
{
    Node*    node;
    int      int_val;
    double   double_val;
    string*  str_val;
    vector<double> *vector;
}
/* Line 193 of yacc.c.  */
#line 236 "sang_m.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 261 "sang_m.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    10,    11,    12,    17,
      18,    19,    24,    28,    29,    34,    35,    43,    44,    45,
      58,    61,    64,    65,    72,    73,    80,    85,    90,    93,
      97,   101,   104,   105,   106,   112,   113,   117,   119,   123,
     125,   127,   128,   135,   136,   138,   139,   144,   145,   150,
     152,   156,   158,   160,   162,   164,   166,   168,   170,   172,
     174,   176,   178,   180,   182,   184,   186,   190,   193,   196,
     201,   206,   214,   218,   225,   232,   236,   243
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    44,    45,    -1,     1,    -1,    -1,
      -1,    -1,    46,    50,    47,    45,    -1,    -1,    -1,    48,
      51,    49,    45,    -1,    26,    76,    36,    -1,    -1,    23,
      39,    52,    59,    -1,    -1,    23,    34,    27,    53,    68,
      28,    59,    -1,    -1,    -1,    23,    35,    34,    27,    54,
      68,    28,    55,    24,    62,    64,    25,    -1,    76,    36,
      -1,    77,    36,    -1,    -1,    30,    57,    27,    75,    28,
      59,    -1,    -1,    31,    58,    27,    75,    28,    59,    -1,
      34,     3,    21,    36,    -1,    34,     3,    66,    36,    -1,
      66,    36,    -1,    22,    34,    36,    -1,    22,    38,    36,
      -1,    32,    36,    -1,    -1,    -1,    24,    60,    62,    61,
      25,    -1,    -1,    56,    63,    62,    -1,    56,    -1,    29,
      65,    36,    -1,    40,    -1,    34,    -1,    -1,    33,    34,
      27,    67,    68,    28,    -1,    -1,    76,    -1,    -1,    76,
      69,     6,    68,    -1,    -1,     4,    71,    72,     5,    -1,
      40,    -1,    40,     6,    72,    -1,    40,    -1,    34,    -1,
       8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,
      13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,
      19,    -1,    18,    -1,    20,    -1,    73,    74,    73,    -1,
      35,    34,    -1,    37,    34,    -1,    35,    34,     3,    40,
      -1,    37,    34,     3,    70,    -1,    37,    34,     3,     7,
       4,    40,     5,    -1,    34,     3,    75,    -1,    34,     4,
      40,     5,     3,    40,    -1,    34,     4,    40,     5,     3,
      75,    -1,    34,     3,    34,    -1,    34,     3,    34,     4,
      40,     5,    -1,    34,     3,    34,     4,    34,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    79,    80,    83,    84,    84,    84,    85,
      85,    85,    88,   106,   105,   120,   118,   137,   148,   136,
     163,   170,   178,   177,   197,   196,   215,   224,   234,   239,
     247,   251,   262,   262,   262,   265,   264,   271,   279,   281,
     282,   286,   286,   289,   290,   295,   295,   299,   299,   301,
     302,   305,   306,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   324,   330,   342,   354,
     367,   380,   393,   401,   409,   417,   424,   431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASIGNA", "ABRECORCHETES",
  "CIERRACORCHETES", "COMA", "RESERVAESPACIO", "SUMA", "MENOS", "DIVIDE",
  "MULTIPLICA", "OR", "AND", "NOT", "IGUALVALOR", "DISTINTOVALOR",
  "MAYORQUE", "MENORQUE", "MAYORIGUAL", "MENORIGUAL", "INPUT", "OUTPUT",
  "FUNC", "ABRELLAVES", "CIERRALLAVES", "GLOBAL", "ABREPARENTESIS",
  "CIERRAPARENTESIS", "DEVUELVE", "IF", "WHILE", "BREAK", "CALL",
  "VARIABLE", "REAL", "PUNTOYCOMA", "VECTOR", "STRING", "INICIO",
  "VALORREAL", "VALORVECTOR", "$accept", "parsetree", "@1", "espacios",
  "@2", "@3", "@4", "@5", "variablesGlobales", "funcion", "@6", "@7", "@8",
  "@9", "line", "@10", "@11", "bloque", "@12", "@13", "lineas", "@14",
  "devuelve", "devolucion", "llamadaFuncion", "@15", "parametros", "@16",
  "vectorNT", "@17", "elementos", "termino", "operacion", "expresion",
  "declaracion", "asignacion", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    44,    43,    43,    45,    46,    47,    45,    48,
      49,    45,    50,    52,    51,    53,    51,    54,    55,    51,
      56,    56,    57,    56,    58,    56,    56,    56,    56,    56,
      56,    56,    60,    61,    59,    63,    62,    62,    64,    65,
      65,    67,    66,    68,    68,    69,    68,    71,    70,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     0,     0,     4,     0,
       0,     4,     3,     0,     4,     0,     7,     0,     0,    12,
       2,     2,     0,     6,     0,     6,     4,     4,     2,     3,
       3,     2,     0,     0,     5,     0,     3,     1,     3,     1,
       1,     0,     6,     0,     1,     0,     4,     0,     4,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     4,
       4,     7,     3,     6,     6,     3,     6,     6
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     0,     5,     1,     3,     0,     0,     0,     7,
       0,    10,     0,     0,     0,     5,     0,     0,    13,     5,
      67,    68,    12,     8,    15,     0,     0,    11,    43,    17,
      32,    14,     0,    44,    43,     0,     0,     0,     0,     0,
      22,    24,     0,     0,     0,     0,     0,    35,    33,     0,
       0,     0,    16,    43,    18,     0,     0,     0,     0,    31,
       0,     0,     0,    67,    68,     0,     0,    28,    20,    21,
      46,     0,    29,    30,     0,     0,    41,     0,    52,    51,
       0,     0,    72,     0,     0,     0,    36,    34,     0,    52,
       0,     0,    43,    26,     0,    27,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    64,    63,    65,     0,
       0,    69,    47,     0,    70,     0,     0,     0,     0,     0,
       0,    66,     0,     0,     0,     0,     0,    23,    25,    42,
      77,    76,    51,    74,    49,     0,     0,    40,    39,     0,
      19,     0,    48,    71,    38,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    15,     7,    19,     9,    11,
      26,    28,    34,    71,    47,    57,    58,    31,    35,    66,
      48,    65,   126,   139,    49,    92,    32,    37,   114,   123,
     135,    81,   109,    82,    33,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int8 yypact[] =
{
       8,   -71,    26,    23,   -71,   -71,     6,    28,    19,   -71,
     -11,   -71,    21,    24,    39,    23,    30,    42,   -71,    23,
     -71,   -71,   -71,   -71,   -71,    33,    53,   -71,    19,   -71,
     -71,   -71,    50,    73,    19,     5,    53,    77,    56,     7,
     -71,   -71,    49,    52,     9,    55,    57,    18,   -71,    51,
      58,    59,   -71,    19,   -71,    60,    61,    63,    65,   -71,
      66,   -15,    48,    95,    96,     5,    75,   -71,   -71,   -71,
     -71,    78,   -71,   -71,   -24,   -24,   -71,    67,    -3,   -71,
      68,    54,   -71,   100,    69,    46,   -71,   -71,     5,   -71,
      79,    80,    19,   -71,   -23,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -24,
      98,   -71,   -71,   102,   -71,    81,    53,    53,    83,   107,
     108,   -71,   -20,    74,    76,   -19,    90,   -71,   -71,   -71,
     -71,   -71,    82,   -71,   111,   114,   115,   -71,   -71,    85,
     -71,    74,   -71,   -71,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,    29,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -36,   -71,   -71,
     -58,   -71,   -71,   -71,    62,   -71,   -31,   -71,   -71,   -71,
     -17,    13,   -71,   -70,    -6,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -76
static const yytype_int16 yytable[] =
{
      52,    94,    14,    38,    90,    91,    77,    86,    -2,     1,
      89,   119,    61,    62,    89,   137,    79,   120,    43,    78,
     132,   138,    70,    16,    17,    79,     4,    39,    18,    50,
     115,    -2,     8,   -75,    -2,    40,    41,    42,    43,    44,
      45,    55,    46,   -37,    23,    56,    -9,   -37,    27,    -6,
     112,    10,   133,   113,    12,    20,    13,    24,    21,    50,
      29,   118,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,    22,    25,    30,    36,   -45,
     127,   128,    50,    53,    54,    59,    60,    67,    83,    63,
      74,    64,    75,    76,    68,    69,    72,    73,    84,    85,
      87,   122,    88,    93,    95,   110,   124,   116,   117,   111,
     125,   129,   130,   131,   134,   140,   136,   141,   -73,   142,
     143,   144,   121,    80,   145
};

static const yytype_uint8 yycheck[] =
{
      36,     4,     8,    34,    74,    75,    21,    65,     0,     1,
      34,    34,     3,     4,    34,    34,    40,    40,    33,    34,
      40,    40,    53,    34,    35,    40,     0,    22,    39,    35,
      88,    23,    26,    36,    26,    30,    31,    32,    33,    34,
      35,    34,    37,    25,    15,    38,    23,    29,    19,    26,
       4,    23,   122,     7,    35,    34,    37,    27,    34,    65,
      27,    92,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    36,    34,    24,    28,     6,
     116,   117,    88,     6,    28,    36,    34,    36,    40,    34,
      27,    34,    27,    27,    36,    36,    36,    36,     3,     3,
      25,     3,    24,    36,    36,     5,     4,    28,    28,    40,
      29,    28,     5,     5,    40,    25,    40,     6,    36,     5,
       5,    36,   109,    61,   141
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,    43,    44,     0,    45,    46,    48,    26,    50,
      23,    51,    35,    37,    76,    47,    34,    35,    39,    49,
      34,    34,    36,    45,    27,    34,    52,    45,    53,    27,
      24,    59,    68,    76,    54,    60,    28,    69,    68,    22,
      30,    31,    32,    33,    34,    35,    37,    56,    62,    66,
      76,    77,    59,     6,    28,    34,    38,    57,    58,    36,
      34,     3,     4,    34,    34,    63,    61,    36,    36,    36,
      68,    55,    36,    36,    27,    27,    27,    21,    34,    40,
      66,    73,    75,    40,     3,     3,    62,    25,    24,    34,
      75,    75,    67,    36,     4,    36,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    74,
       5,    40,     4,     7,    70,    62,    28,    28,    68,    34,
      40,    73,     3,    71,     4,    29,    64,    59,    59,    28,
       5,     5,    40,    75,    40,    72,    40,    34,    40,    65,
      25,     6,     5,     5,    36,    72
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "sang_m.y"
    { spaces_vector = *new vector<Node*>(); current_depth = 0; ts = *new SymbolTable(); nameStack = *new std::vector<string>();;}
    break;

  case 3:
#line 79 "sang_m.y"
    {;}
    break;

  case 4:
#line 80 "sang_m.y"
    { spaces_vector.clear(); lines_vector.clear(); param_vector.clear(); current_vector.clear(); current_depth = 0;;}
    break;

  case 5:
#line 83 "sang_m.y"
    {current_depth -= 1;;}
    break;

  case 6:
#line 84 "sang_m.y"
    { current_depth += 1;;}
    break;

  case 7:
#line 84 "sang_m.y"
    {spaces_vector.push_back((yyvsp[(2) - (2)].node)); current_depth -= 1;;}
    break;

  case 9:
#line 85 "sang_m.y"
    { current_depth += 1;;}
    break;

  case 10:
#line 85 "sang_m.y"
    {spaces_vector.push_back((yyvsp[(2) - (2)].node));current_depth -= 1;;}
    break;

  case 12:
#line 89 "sang_m.y"
    {
    (yyval.node) = new GlobalVar((yyvsp[(2) - (3)].node));
    if(Declaration* n = dynamic_cast<Declaration*>((yyvsp[(2) - (3)].node))){
        DataType type;
        if(n->isReal()){
            type = real;
        }else{
            type = DataTypeVector;
        }
        SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,(yyvsp[(2) - (3)].node));
        ts.insertRecord(*(n->getIdentification()), record );
    }
;}
    break;

  case 13:
#line 106 "sang_m.y"
    {
    nameStack.push_back("inicio");
    DataType type = initFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord("inicio", record);
    
;}
    break;

  case 14:
#line 114 "sang_m.y"
    {
    (yyval.node) = new FunctionDefinition((yyvsp[(2) - (4)].str_val),ts.getNodeVector("inicio"));
    nameStack.pop_back();
;}
    break;

  case 15:
#line 120 "sang_m.y"
    {
    nameStack.push_back(*(yyvsp[(2) - (3)].str_val));
    DataType type = voidFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    record.setAddress(functionLabel);
    ts.insertRecord(*(yyvsp[(2) - (3)].str_val), record);
    param_vector = *new vector<Node*>();
    
    functionLabel -= 1;
;}
    break;

  case 16:
#line 131 "sang_m.y"
    {
    (yyval.node) = new FunctionDefinition((yyvsp[(2) - (7)].str_val),param_vector,ts.getNodeVector(*(yyvsp[(2) - (7)].str_val)));
    nameStack.pop_back();
;}
    break;

  case 17:
#line 137 "sang_m.y"
    {
    nameStack.push_back(*(yyvsp[(3) - (4)].str_val));
    DataType type = realFunction;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    record.setAddress(functionLabel);
    ts.insertRecord(*(yyvsp[(3) - (4)].str_val), record);
    param_vector = *new vector<Node*>();
    functionLabel -= 1;
    
;}
    break;

  case 18:
#line 148 "sang_m.y"
    {
    func_param_vector = param_vector;
;}
    break;

  case 19:
#line 152 "sang_m.y"
    {
    ts.setParams(param_vector,*(yyvsp[(3) - (12)].str_val));
    (yyval.node) = new FunctionDefinition((yyvsp[(3) - (12)].str_val),func_param_vector,ts.getNodeVector(*(yyvsp[(3) - (12)].str_val)),true,(yyvsp[(11) - (12)].node));
    SymbolTableRecord* r = ts.getRecord(*(yyvsp[(3) - (12)].str_val));
    r->setFunctionDefinition((yyval.node));
    nameStack.pop_back();
;}
    break;

  case 20:
#line 164 "sang_m.y"
    {
    (yyval.node) = (yyvsp[(1) - (2)].node);
    string blockName;
    stringStack(&blockName);
;}
    break;

  case 21:
#line 171 "sang_m.y"
    {
    (yyval.node) = (yyvsp[(1) - (2)].node);
    string blockName;
    stringStack(&blockName);
;}
    break;

  case 22:
#line 178 "sang_m.y"
    {
    nameStack.push_back("If");
    string blockName;
    stringStack(&blockName);
    DataType type = flowControlIf;
    SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord(blockName, record);
    
;}
    break;

  case 23:
#line 188 "sang_m.y"
    {
    string blockName;
    stringStack(&blockName);
    (yyval.node) = new FlowControl(false,(yyvsp[(4) - (6)].node),ts.getNodeVector(blockName));
    ts.removeRecord(blockName);
    nameStack.pop_back();
;}
    break;

  case 24:
#line 197 "sang_m.y"
    {
    nameStack.push_back("While");
    string blockName;
    stringStack(&blockName);
    DataType type = flowControlIf;
    SymbolTableRecord record = *new SymbolTableRecord(true,type,current_depth,*new std::vector<Node*>());
    ts.insertRecord(blockName, record);
    
;}
    break;

  case 25:
#line 207 "sang_m.y"
    {
    string blockName;
    stringStack(&blockName);
    (yyval.node) = new FlowControl(true,(yyvsp[(4) - (6)].node),ts.getNodeVector(blockName));
    ts.removeRecord(blockName);
    nameStack.pop_back();
;}
    break;

  case 26:
#line 216 "sang_m.y"
    {
    (yyval.node) = new AsignationInput();
    if(!heightSearch((yyvsp[(1) - (4)].str_val), current_depth)  ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
    
;}
    break;

  case 27:
#line 225 "sang_m.y"
    {
    (yyval.node) = new AsignationFunctionCall((yyvsp[(1) - (4)].str_val),(yyvsp[(3) - (4)].node));
    if(!ts.exists(*(yyvsp[(1) - (4)].str_val))){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
    //if(!heightSearch($1, current_depth)  ){
    //
    //} //TODO control de errores: controlar que la funcion que se llama existe tras construir todo el árbol.
;}
    break;

  case 28:
#line 235 "sang_m.y"
    {
    //$$ = new AsignationFunctionCall(nullptr,$2);
;}
    break;

  case 29:
#line 240 "sang_m.y"
    {
    (yyval.node) = new Output_Expression(true, (yyvsp[(2) - (3)].str_val));
    int n = ts.exists(*(yyvsp[(2) - (3)].str_val));
    if(n == -1 || n > current_depth){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 30:
#line 248 "sang_m.y"
    {
    (yyval.node) = new Output_Expression(false, (yyvsp[(2) - (3)].str_val));
;}
    break;

  case 31:
#line 252 "sang_m.y"
    {
    (yyval.node) = new BreakNode();
    string blockName;
    stringStack(&blockName);
    if(blockName.find("While") == std::string::npos){
        yyerror("TU TAS TO LOCO PEPE JUAN para que haces un break fuera de un while tas tonto ¬¬\n");
    }
;}
    break;

  case 32:
#line 262 "sang_m.y"
    {current_depth += 1;;}
    break;

  case 33:
#line 262 "sang_m.y"
    { current_depth -= 1;;}
    break;

  case 35:
#line 265 "sang_m.y"
    {
    string blockName;
    stringStack(&blockName);
    ts.saveNode(blockName,(yyvsp[(1) - (1)].node));
;}
    break;

  case 37:
#line 272 "sang_m.y"
    {
    string blockName;
    stringStack(&blockName);
    ts.saveNode(blockName,(yyvsp[(1) - (1)].node));
;}
    break;

  case 38:
#line 279 "sang_m.y"
    { (yyval.node) = new ReturnNode((yyvsp[(2) - (3)].node));;}
    break;

  case 39:
#line 281 "sang_m.y"
    {(yyval.node) = new Math_Term<double>((yyvsp[(1) - (1)].double_val ));;}
    break;

  case 40:
#line 282 "sang_m.y"
    {(yyval.node) = new Math_Term<std::string>(*(yyvsp[(1) - (1)].str_val));;}
    break;

  case 41:
#line 286 "sang_m.y"
    {param_vector = *new std::vector<Node*>();;}
    break;

  case 42:
#line 286 "sang_m.y"
    { (yyval.node) = new FunctionCall((yyvsp[(2) - (6)].str_val),param_vector);;}
    break;

  case 44:
#line 291 "sang_m.y"
    {
    param_vector.push_back((yyvsp[(1) - (1)].node));
;}
    break;

  case 45:
#line 295 "sang_m.y"
    { param_vector.push_back((yyvsp[(1) - (1)].node));;}
    break;

  case 47:
#line 299 "sang_m.y"
    {current_vector = *new vector<double>();;}
    break;

  case 49:
#line 301 "sang_m.y"
    {current_vector.push_back((yyvsp[(1) - (1)].double_val ));;}
    break;

  case 50:
#line 302 "sang_m.y"
    {current_vector.push_back((yyvsp[(1) - (3)].double_val ));;}
    break;

  case 51:
#line 305 "sang_m.y"
    {(yyval.node) = new Math_Term<double>((yyvsp[(1) - (1)].double_val ));;}
    break;

  case 52:
#line 306 "sang_m.y"
    {(yyval.node) = new Math_Term<std::string>(*(yyvsp[(1) - (1)].str_val));;}
    break;

  case 53:
#line 309 "sang_m.y"
    {(yyval.int_val) = '+';;}
    break;

  case 54:
#line 310 "sang_m.y"
    {(yyval.int_val) = '-';;}
    break;

  case 55:
#line 311 "sang_m.y"
    {(yyval.int_val) = '/';;}
    break;

  case 56:
#line 312 "sang_m.y"
    {(yyval.int_val) = '*';;}
    break;

  case 57:
#line 313 "sang_m.y"
    {(yyval.int_val) = '|';;}
    break;

  case 58:
#line 314 "sang_m.y"
    {(yyval.int_val) = '&';;}
    break;

  case 59:
#line 315 "sang_m.y"
    {(yyval.int_val) = '!';;}
    break;

  case 60:
#line 316 "sang_m.y"
    {(yyval.int_val) = '=';;}
    break;

  case 61:
#line 317 "sang_m.y"
    {(yyval.int_val) = '~';;}
    break;

  case 62:
#line 318 "sang_m.y"
    {(yyval.int_val) = '>';;}
    break;

  case 63:
#line 319 "sang_m.y"
    {(yyval.int_val) = 'Z';;}
    break;

  case 64:
#line 320 "sang_m.y"
    {(yyval.int_val) = '<';;}
    break;

  case 65:
#line 321 "sang_m.y"
    {(yyval.int_val) = 'z';;}
    break;

  case 66:
#line 325 "sang_m.y"
    {
    (yyval.node) = new  Math_Expression((yyvsp[(1) - (3)].node),(yyvsp[(2) - (3)].int_val),(yyvsp[(3) - (3)].node));
;}
    break;

  case 67:
#line 331 "sang_m.y"
    {
    
    if(!heightSearch((yyvsp[(2) - (2)].str_val), current_depth)){
        
        DataType type = real ;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*(yyvsp[(2) - (2)].str_val), record);
    }
    (yyval.node) = new Declaration((yyvsp[(2) - (2)].str_val),true);
    
;}
    break;

  case 68:
#line 343 "sang_m.y"
    {
    if(!heightSearch((yyvsp[(2) - (2)].str_val), current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*(yyvsp[(2) - (2)].str_val), record);
    }
    
    (yyval.node) = new Declaration((yyvsp[(2) - (2)].str_val),false);
;}
    break;

  case 69:
#line 355 "sang_m.y"
    {
    (yyval.node) = new REAL_Asignation(true, (yyvsp[(2) - (4)].str_val), (yyvsp[(4) - (4)].double_val ));
    if(heightSearch((yyvsp[(2) - (4)].str_val),1)){
        ts.saveNode(*(yyvsp[(2) - (4)].str_val),(yyval.node));
    }
    else if(!heightSearch((yyvsp[(2) - (4)].str_val), current_depth)){
        DataType type = real ;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*(yyvsp[(2) - (4)].str_val), record);
    }
    
;}
    break;

  case 70:
#line 368 "sang_m.y"
    {
    (yyval.node) = new VECTOR_Asignation(true, (yyvsp[(2) - (4)].str_val),current_vector,current_vector.size());
    current_vector.clear();
    if(heightSearch((yyvsp[(2) - (4)].str_val),1)){
        ts.saveNode(*(yyvsp[(2) - (4)].str_val),(yyval.node));
    }
    else if(!heightSearch((yyvsp[(2) - (4)].str_val), current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>(),current_vector);
        ts.insertRecord(*(yyvsp[(2) - (4)].str_val), record);
    }
;}
    break;

  case 71:
#line 381 "sang_m.y"
    {
    (yyval.node) = new VECTOR_Asignation(true, (yyvsp[(2) - (7)].str_val), *new std::vector<double>,(int)(yyvsp[(6) - (7)].double_val ));
    if(heightSearch((yyvsp[(2) - (7)].str_val),1)){
        ts.saveNode(*(yyvsp[(2) - (7)].str_val),(yyval.node));
    }
    else if(!heightSearch((yyvsp[(2) - (7)].str_val), current_depth)){
        DataType type = DataTypeVector;
        SymbolTableRecord record = *new SymbolTableRecord(false,type,current_depth,*new std::vector<Node*>());
        ts.insertRecord(*(yyvsp[(2) - (7)].str_val), record);
    }
;}
    break;

  case 72:
#line 393 "sang_m.y"
    {
    (yyval.node) = new Expression2Var((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].node));
    
    if(!ts.exists(*(yyvsp[(1) - (3)].str_val))){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 73:
#line 402 "sang_m.y"
    {
    (yyval.node) = new ELEM_VECTOR_Asignation((yyvsp[(1) - (6)].str_val),(int)(yyvsp[(3) - (6)].double_val ),(yyvsp[(6) - (6)].double_val ));
    
    if(!ts.exists(*(yyvsp[(1) - (6)].str_val))){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 74:
#line 410 "sang_m.y"
    {
    (yyval.node) = new Expression2Var((yyvsp[(1) - (6)].str_val),(yyvsp[(3) - (6)].double_val ),(yyvsp[(6) - (6)].node));
    
    if(!ts.exists(*(yyvsp[(1) - (6)].str_val))){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 75:
#line 418 "sang_m.y"
    {
    (yyval.node) = new VAR2VAR_Asignation((yyvsp[(1) - (3)].str_val),(yyvsp[(3) - (3)].str_val));
    if(!ts.exists(*(yyvsp[(1) - (3)].str_val)) || !ts.exists(*(yyvsp[(3) - (3)].str_val)) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 76:
#line 425 "sang_m.y"
    {
    (yyval.node) = new  ELEM_VECTOR2VAR_Asignation ((yyvsp[(3) - (6)].str_val),(yyvsp[(5) - (6)].double_val ), (yyvsp[(1) - (6)].str_val));
    if(!ts.exists(*(yyvsp[(1) - (6)].str_val)) || !ts.exists(*(yyvsp[(3) - (6)].str_val)) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;

  case 77:
#line 432 "sang_m.y"
    {
    (yyval.node) = new  ELEM_VECTOR2VAR_Asignation ((yyvsp[(3) - (6)].str_val),(yyvsp[(5) - (6)].str_val), (yyvsp[(1) - (6)].str_val));
    if(!ts.exists(*(yyvsp[(1) - (6)].str_val)) || !ts.exists(*(yyvsp[(3) - (6)].str_val)) ){
        yyerror("TU TAS TO LOCO PEPE JUAN declara la variable\n");
    }
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2164 "sang_m.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 440 "sang_m.y"

void buildCheckForErrors(){
    printf("Jeronimo");
}

void stringStack(string* dst ){
    for(int i = 0; i < nameStack.size(); i++){
        (*dst) += nameStack[i];
    }
}


bool heightSearch(string* target, int max){
    for(int i = 0; i < spaces_vector.size();i++){
        if(spaces_vector[i]->searchByHeight( target,0,max)) return true;
    }
    return false;
}


void  yyerror(char* str) {
    extern int yylineno;
    printf("Parse  Error near line %d \n %s\n",yylineno,str );
    exit(-1);
    
}

std::string int_to_hexString(int c){
    std::stringstream stream ;
    stream << "0x" << std::hex << c;
    return stream.str();
    
}

void generateCodeFromAST(char* filename){
    
    
    
    string filename_e (filename);
    filename_e += ".q.c";
    string header = "#include \"Q.h\"\n\
    BEGIN\n";
    
    ofstream objFile;
    objFile.open(filename_e);
    
    objFile << header ;
    
    //CodeGeneration here
    // set global vars
    
    //TODO check global vars numbers
    std::vector<std::string> globals = ts.getGlobalVars();
    objFile << "\tSTAT(0)\n";
    for(int i = 0; i < globals.size(); i++){
        if(ts[globals[i]].getType() == real){
            staticMem -= sizeof(double);
            objFile << "\tMEM("+int_to_hexString(staticMem)+"," + std::to_string(sizeof(double)) +");\n" ;
        }
        else{ //se guarda una dirección donde estará reservado el vector.
            staticMem -= sizeof(double)*10;
            objFile << "\tFIL("+int_to_hexString(staticMem)+",10,0);\n" ;
        }
        ts.setAddress(globals[i],staticMem);
    }
    
    
    objFile << "\tCODE(0)\n";
    vector<SymbolTableRecord*> nonInitFunction = ts.getNonInitFunctions();
    
   
   printf("N non init functions %d\n", nonInitFunction.size());
    for(int i = 0; i < nonInitFunction.size(); i++){
        
        objFile << "L " + std::to_string(nonInitFunction[i]->getAddress()) + ":";
        std::string r = nonInitFunction[i]->functionDefinition->generateCode(&codeLabel, &statLabel,&staticMem,&ts);
        
        objFile << r;
        
    }
    
    SymbolTableRecord initFunc = ts.getInit();
    
    
   
    //codeLabel +=1;
    objFile << "L 0:";
    vector<Node*> mainFuncNodes = initFunc.getNodeStack();
    
    objFile << "\tR6=R7;\n";
    
    relativePositionToR6 = 0;
    for(int i = 0; i < mainFuncNodes.size(); i++){
        objFile << mainFuncNodes[i]->generateCode(&codeLabel, &statLabel,&staticMem,&ts);
    }
    objFile << "GT(-2);\n" ;
    objFile << "END" ;
    
    objFile.close();
    
}

void checkErrors(){
    if(!ts.hasOnlyInit()){
        printf("Se ha detectado varias funciones de inicio o ninguna. Solo se permite que haya una.\n");
        exit(-1);
    }
}

int  main(int  num_args , char** args) {
    if(num_args  != 2) {
        printf("usage: ./ parser1  filename\n");
        exit (0);
    }
    FILE* file = fopen(args[1],"r");
    if(file == NULL) {
        printf("couldn 't open %s\n", args [1]);
        exit (0);
    }else{
        yyin = file;   // now  flex  reads  from  file
    }
    yyparse ();
    
    //ts.printState();
    checkErrors();
    generateCodeFromAST(args[1]);
    fclose(file);
    return 0;
}

