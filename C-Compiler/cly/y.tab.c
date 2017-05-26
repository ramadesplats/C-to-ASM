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
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     tINFEQ = 258,
     tSUPEQ = 259,
     tNEQ = 260,
     tINF = 261,
     tSUP = 262,
     tAND = 263,
     tOR = 264,
     tEQ = 265,
     tSUB = 266,
     tADD = 267,
     tDIV = 268,
     tMUL = 269,
     tEQEQ = 270,
     tPF = 271,
     tPO = 272,
     tPV = 273,
     tMAIN = 274,
     tPRINTF = 275,
     tMALLOC = 276,
     tQUOTE = 277,
     tIF = 278,
     tELSE = 279,
     tWHILE = 280,
     tFOR = 281,
     tINT = 282,
     tCONST = 283,
     tVIR = 284,
     tAF = 285,
     tAO = 286,
     tRETURN = 287,
     tADR = 288,
     tID = 289,
     tNB = 290
   };
#endif
/* Tokens.  */
#define tINFEQ 258
#define tSUPEQ 259
#define tNEQ 260
#define tINF 261
#define tSUP 262
#define tAND 263
#define tOR 264
#define tEQ 265
#define tSUB 266
#define tADD 267
#define tDIV 268
#define tMUL 269
#define tEQEQ 270
#define tPF 271
#define tPO 272
#define tPV 273
#define tMAIN 274
#define tPRINTF 275
#define tMALLOC 276
#define tQUOTE 277
#define tIF 278
#define tELSE 279
#define tWHILE 280
#define tFOR 281
#define tINT 282
#define tCONST 283
#define tVIR 284
#define tAF 285
#define tAO 286
#define tRETURN 287
#define tADR 288
#define tID 289
#define tNB 290




/* Copy the first part of user declarations.  */
#line 1 "compilateur.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "fonctions.h"

int yylex(void);
void yyerror(char *s);
int compteur_error;




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
#line 16 "compilateur.y"
{int nb; char *str;}
/* Line 193 of yacc.c.  */
#line 182 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 195 "y.tab.c"

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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   542

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  204

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    13,    17,    18,
      26,    27,    28,    37,    40,    41,    42,    47,    48,    54,
      55,    61,    62,    63,    69,    70,    77,    78,    85,    86,
      87,    93,    94,    98,   102,   106,   109,   112,   115,   119,
     123,   127,   131,   136,   140,   145,   147,   151,   154,   159,
     160,   164,   168,   169,   173,   174,   175,   176,   177,   188,
     189,   190,   193,   194,   198,   203,   209,   216,   217,   218,
     227,   228,   231,   232,   233,   241,   242,   243,   255,   257,
     259,   262,   265,   269,   271,   275,   279,   283,   287,   291,
     295,   299,   303,   307,   311,   315,   319
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    -1,    38,    39,    -1,    -1,    40,    -1,
      42,    39,    -1,    40,     1,    18,    -1,    -1,    27,    19,
      41,    17,    69,    16,    53,    -1,    -1,    -1,    27,    34,
      17,    43,    45,    16,    53,    44,    -1,     1,    18,    -1,
      -1,    -1,    27,    34,    46,    49,    -1,    -1,    28,    27,
      34,    47,    49,    -1,    -1,    27,    14,    34,    48,    49,
      -1,    -1,    -1,    29,    27,    34,    50,    49,    -1,    -1,
      29,    28,    27,    34,    51,    49,    -1,    -1,    29,    27,
      14,    34,    52,    49,    -1,    -1,    -1,    31,    54,    56,
      55,    30,    -1,    -1,    57,    18,    56,    -1,    58,    18,
      56,    -1,    63,    18,    56,    -1,    73,    56,    -1,    77,
      56,    -1,    80,    56,    -1,    71,    18,    56,    -1,    72,
      18,    56,    -1,     1,    18,    56,    -1,    34,    10,    83,
      -1,    14,    34,    10,    83,    -1,    27,    59,    60,    -1,
      28,    27,    61,    62,    -1,    34,    -1,    34,    10,    83,
      -1,    14,    34,    -1,    14,    34,    10,    83,    -1,    -1,
      29,    59,    60,    -1,    34,    10,    83,    -1,    -1,    29,
      61,    62,    -1,    -1,    -1,    -1,    -1,    34,    17,    68,
      68,    64,    65,    69,    16,    66,    67,    -1,    -1,    -1,
      83,    70,    -1,    -1,    29,    83,    70,    -1,    20,    17,
      34,    16,    -1,    20,    17,    14,    34,    16,    -1,    14,
      34,    10,    21,    17,    16,    -1,    -1,    -1,    23,    17,
      83,    16,    74,    53,    75,    76,    -1,    -1,    24,    53,
      -1,    -1,    -1,    25,    78,    17,    83,    79,    16,    53,
      -1,    -1,    -1,    26,    17,    57,    18,    81,    83,    18,
      82,    57,    16,    53,    -1,    34,    -1,    35,    -1,    14,
      34,    -1,    33,    34,    -1,    17,    83,    16,    -1,    63,
      -1,    83,    15,    83,    -1,    83,     5,    83,    -1,    83,
       8,    83,    -1,    83,     9,    83,    -1,    83,    12,    83,
      -1,    83,    11,    83,    -1,    83,    14,    83,    -1,    83,
      13,    83,    -1,    83,     6,    83,    -1,    83,     7,    83,
      -1,    83,     3,    83,    -1,    83,     4,    83,    -1,    83,
       1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    62,    66,    68,    69,    70,    76,    75,
      82,    89,    81,    91,    94,    97,    96,   100,    99,   103,
     102,   107,   110,   109,   113,   112,   116,   115,   122,   124,
     121,   129,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   143,   152,   167,   168,   174,   179,   184,   189,   196,
     198,   202,   209,   211,   216,   217,   220,   225,   215,   231,
     234,   236,   239,   241,   245,   247,   253,   269,   271,   268,
     276,   278,   283,   285,   282,   292,   294,   291,   301,   303,
     305,   307,   309,   311,   312,   314,   316,   318,   320,   322,
     324,   326,   328,   330,   332,   334,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tINFEQ", "tSUPEQ", "tNEQ", "tINF",
  "tSUP", "tAND", "tOR", "tEQ", "tSUB", "tADD", "tDIV", "tMUL", "tEQEQ",
  "tPF", "tPO", "tPV", "tMAIN", "tPRINTF", "tMALLOC", "tQUOTE", "tIF",
  "tELSE", "tWHILE", "tFOR", "tINT", "tCONST", "tVIR", "tAF", "tAO",
  "tRETURN", "tADR", "tID", "tNB", "$accept", "Prog", "@1", "Fonctions",
  "Main", "@2", "Fonction", "@3", "@4", "Args", "@5", "@6", "@7", "ArgsN",
  "@8", "@9", "@10", "Body", "@11", "@12", "Insts", "Affectation",
  "Declaration", "Decl1", "DeclN", "Decl1Const", "DeclNConst",
  "Invocation", "@13", "@14", "@15", "@16", "Vide", "Params", "ParamsN",
  "Printf", "Malloc", "If", "@17", "@18", "Else", "While", "@19", "@20",
  "For", "@21", "@22", "E", 0
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
     285,   286,   287,   288,   289,   290
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    38,    37,    39,    39,    39,    39,    41,    40,
      43,    44,    42,    42,    45,    46,    45,    47,    45,    48,
      45,    49,    50,    49,    51,    49,    52,    49,    54,    55,
      53,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    60,
      60,    61,    62,    62,    64,    65,    66,    67,    63,    68,
      69,    69,    70,    70,    71,    71,    72,    74,    75,    73,
      76,    76,    78,    79,    77,    81,    82,    80,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     2,     3,     0,     7,
       0,     0,     8,     2,     0,     0,     4,     0,     5,     0,
       5,     0,     0,     5,     0,     6,     0,     6,     0,     0,
       5,     0,     3,     3,     3,     2,     2,     2,     3,     3,
       3,     3,     4,     3,     4,     1,     3,     2,     4,     0,
       3,     3,     0,     3,     0,     0,     0,     0,    10,     0,
       0,     2,     0,     3,     4,     5,     6,     0,     0,     8,
       0,     2,     0,     0,     7,     0,     0,    11,     1,     1,
       2,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     0,     0,    13,
       8,     0,     0,     6,     0,    10,     7,    60,    14,     0,
       0,     0,    78,    79,    83,     0,     0,     0,     0,     0,
      80,     0,    81,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    61,
       0,    15,     0,     0,    82,    59,    28,     9,    96,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    21,    17,    11,    54,     0,    63,    21,
       0,    16,    21,    12,    55,     0,     0,     0,     0,    72,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    20,     0,     0,    18,    60,     0,     0,
       0,     0,     0,     0,     0,    45,    49,     0,     0,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,    22,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,    43,     0,    52,     0,    30,    32,
      33,    34,    38,    39,    26,    21,    24,    56,     0,     0,
       0,    64,    67,     0,     0,    75,     0,     0,    49,     0,
       0,    44,    21,    23,    21,    57,     0,    65,     0,     0,
       0,     0,     0,    50,     0,    52,    27,    25,    58,    66,
      68,     0,     0,    53,    70,    74,    76,     0,    69,     0,
      71,     0,     0,    77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    14,     8,    18,    83,    29,
      73,    82,    79,    81,   155,   174,   172,    57,    77,   119,
      94,    95,    96,   116,   144,   146,   171,    24,    84,   107,
     175,   188,    55,    25,    49,    98,    99,   100,   178,   194,
     198,   101,   112,   179,   102,   181,   199,    26
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -111
static const yytype_int16 yypact[] =
{
    -111,    40,     7,  -111,    23,    52,  -111,     9,     7,  -111,
    -111,    25,    26,  -111,    29,  -111,  -111,    41,   -13,    35,
      41,    38,    56,  -111,  -111,    27,   389,    -2,    50,    69,
    -111,   494,  -111,  -111,    57,    72,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,  -111,
      58,  -111,    59,    57,  -111,  -111,  -111,  -111,  -111,   161,
     180,   199,   218,   237,   256,   275,   294,   313,   332,   351,
     370,   389,  -111,    65,  -111,  -111,  -111,    34,  -111,    65,
      11,  -111,    65,  -111,  -111,    78,    70,    88,    89,  -111,
      90,    -1,    81,    -6,  -111,    91,    92,    93,    94,    96,
      34,    34,    34,  -111,    22,    97,  -111,    41,    34,   105,
      31,    41,    99,    33,    84,   109,    98,    86,    41,    95,
      34,    34,    34,    34,    34,  -111,  -111,  -111,    87,  -111,
     114,   107,  -111,    49,   117,   112,   510,    41,   118,   119,
     113,   143,    41,    -1,  -111,   144,   126,   446,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,    65,  -111,  -111,   139,   462,
     141,  -111,  -111,   526,   149,  -111,    41,   129,    98,    41,
      86,  -111,    65,  -111,    65,  -111,   147,  -111,    57,   155,
      41,    41,   408,  -111,   427,   126,  -111,  -111,  -111,  -111,
    -111,    57,   478,  -111,   154,  -111,  -111,    57,  -111,    33,
    -111,   164,    57,  -111
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -111,  -111,  -111,   174,  -111,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,   -77,  -111,  -111,  -111,   -52,  -111,  -111,
     -21,  -110,  -111,    54,    48,    67,    14,   -71,  -111,  -111,
    -111,  -111,   146,   111,   168,  -111,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,  -111,  -111,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -96
static const yytype_int16 yytable[] =
{
      31,    75,   103,   140,   118,   106,    97,    -4,     4,    -5,
      12,    33,    50,   114,    27,    28,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    97,
      97,    97,    51,   115,     5,    85,   128,    97,   104,   105,
       3,     9,    15,    34,    16,   134,    17,   138,    86,    97,
      97,    97,    97,    97,    87,    19,   129,    88,    20,    89,
      90,    91,    92,    19,   -31,   135,    20,   139,    93,    30,
     158,    10,    32,    33,    21,    22,    23,    52,   173,   125,
     126,   127,    21,    22,    23,    53,    11,   132,    56,   201,
      58,   136,    72,    74,    80,   186,   108,   187,   147,   149,
     150,   151,   152,   153,   109,   110,   111,   113,   117,   120,
     121,   122,   123,   159,   124,   133,   137,   163,   141,   142,
     145,   154,   167,   157,   130,   148,   190,   143,   161,   118,
      35,   165,    36,    37,    38,    39,    40,    41,    42,   195,
      43,    44,    45,    46,    47,   200,   182,   -46,   156,   184,
     203,   160,   164,   166,   169,   170,   176,   177,   -46,   180,
     159,   192,    35,   189,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   191,    43,    44,    45,    46,    47,   -94,   197,   -94,
     202,    35,    13,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -94,    43,    44,    45,    46,    47,   -95,   168,   -95,   193,
      35,    76,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -95,
      43,    44,    45,    46,    47,   -85,   183,   -85,   131,    35,
       0,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -85,    43,
      44,    45,    46,    47,   -92,     0,   -92,   185,    35,    78,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -92,    43,    44,
      45,    46,    47,   -93,     0,   -93,     0,    35,     0,   -86,
     -86,   -86,   -86,   -86,   -86,   -86,   -93,    43,    44,    45,
      46,    47,   -86,     0,   -86,     0,    35,     0,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -86,    43,    44,    45,    46,
      47,   -87,     0,   -87,     0,    35,     0,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -87,   -89,   -89,    45,    46,    47,
     -89,     0,   -89,     0,    35,     0,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -89,   -88,   -88,    45,    46,    47,   -88,
       0,   -88,     0,    35,     0,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -88,   -91,   -91,   -91,   -91,    47,   -91,     0,
     -91,     0,    35,     0,   -90,   -90,   -90,   -90,   -90,   -90,
     -90,   -91,   -90,   -90,   -90,   -90,    47,   -90,     0,   -90,
       0,    35,     0,   -84,   -84,   -84,   -84,   -84,   -84,   -84,
     -90,   -84,   -84,   -84,   -84,   -84,   -84,     0,   -84,     0,
      35,     0,    36,    37,    38,    39,    40,    41,    42,   -84,
      43,    44,    45,    46,    47,   -62,     0,     0,     0,    35,
       0,    36,    37,    38,    39,    40,    41,    42,    48,    43,
      44,    45,    46,    47,     0,     0,   -48,     0,    35,     0,
      36,    37,    38,    39,    40,    41,    42,   -48,    43,    44,
      45,    46,    47,     0,     0,   -51,     0,    35,     0,    36,
      37,    38,    39,    40,    41,    42,   -51,    43,    44,    45,
      46,    47,   -41,    35,   -41,    36,    37,    38,    39,    40,
      41,    42,     0,    43,    44,    45,    46,    47,   -42,    35,
     -42,    36,    37,    38,    39,    40,    41,    42,     0,    43,
      44,    45,    46,    47,     0,    35,   196,    36,    37,    38,
      39,    40,    41,    42,     0,    43,    44,    45,    46,    47,
      54,    35,     0,    36,    37,    38,    39,    40,    41,    42,
       0,    43,    44,    45,    46,    47,   162,    35,     0,    36,
      37,    38,    39,    40,    41,    42,     0,    43,    44,    45,
      46,    47,   -73
};

static const yytype_int16 yycheck[] =
{
      20,    53,    79,   113,    10,    82,    77,     0,     1,     0,
       1,    17,    14,    14,    27,    28,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   100,
     101,   102,    34,    34,    27,     1,    14,   108,    27,    28,
       0,    18,    17,    16,    18,    14,    17,    14,    14,   120,
     121,   122,   123,   124,    20,    14,    34,    23,    17,    25,
      26,    27,    28,    14,    30,    34,    17,    34,    34,    34,
      21,    19,    34,    17,    33,    34,    35,    27,   155,   100,
     101,   102,    33,    34,    35,    16,    34,   108,    31,   199,
      18,   111,    34,    34,    29,   172,    18,   174,   118,   120,
     121,   122,   123,   124,    34,    17,    17,    17,    27,    18,
      18,    18,    18,   133,    18,    10,    17,   137,    34,    10,
      34,    34,   142,    16,    27,    30,   178,    29,    16,    10,
       1,    18,     3,     4,     5,     6,     7,     8,     9,   191,
      11,    12,    13,    14,    15,   197,   166,    18,    34,   169,
     202,    34,    34,    10,    10,    29,    17,    16,    29,    10,
     180,   181,     1,    16,     3,     4,     5,     6,     7,     8,
       9,    16,    11,    12,    13,    14,    15,    16,    24,    18,
      16,     1,     8,     3,     4,     5,     6,     7,     8,     9,
      29,    11,    12,    13,    14,    15,    16,   143,    18,   185,
       1,    55,     3,     4,     5,     6,     7,     8,     9,    29,
      11,    12,    13,    14,    15,    16,   168,    18,   107,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    29,    11,
      12,    13,    14,    15,    16,    -1,    18,   170,     1,    71,
       3,     4,     5,     6,     7,     8,     9,    29,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    29,    11,    12,    13,
      14,    15,    16,    -1,    18,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    29,    11,    12,    13,    14,
      15,    16,    -1,    18,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    29,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    29,    11,    12,    13,    14,    15,    16,
      -1,    18,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    29,    11,    12,    13,    14,    15,    16,    -1,
      18,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    29,    11,    12,    13,    14,    15,    16,    -1,    18,
      -1,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      29,    11,    12,    13,    14,    15,    16,    -1,    18,    -1,
       1,    -1,     3,     4,     5,     6,     7,     8,     9,    29,
      11,    12,    13,    14,    15,    16,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    29,    11,
      12,    13,    14,    15,    -1,    -1,    18,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    29,    11,    12,
      13,    14,    15,    -1,    -1,    18,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    29,    11,    12,    13,
      14,    15,    16,     1,    18,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    13,    14,    15,    16,     1,
      18,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    13,    14,    15,    -1,     1,    18,     3,     4,     5,
       6,     7,     8,     9,    -1,    11,    12,    13,    14,    15,
      16,     1,    -1,     3,     4,     5,     6,     7,     8,     9,
      -1,    11,    12,    13,    14,    15,    16,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    13,
      14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    37,    38,     0,     1,    27,    39,    40,    42,    18,
      19,    34,     1,    39,    41,    17,    18,    17,    43,    14,
      17,    33,    34,    35,    63,    69,    83,    27,    28,    45,
      34,    83,    34,    17,    16,     1,     3,     4,     5,     6,
       7,     8,     9,    11,    12,    13,    14,    15,    29,    70,
      14,    34,    27,    16,    16,    68,    31,    53,    18,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    34,    46,    34,    53,    68,    54,    70,    48,
      29,    49,    47,    44,    64,     1,    14,    20,    23,    25,
      26,    27,    28,    34,    56,    57,    58,    63,    71,    72,
      73,    77,    80,    49,    27,    28,    49,    65,    18,    34,
      17,    17,    78,    17,    14,    34,    59,    27,    10,    55,
      18,    18,    18,    18,    18,    56,    56,    56,    14,    34,
      27,    69,    56,    10,    14,    34,    83,    17,    14,    34,
      57,    34,    10,    29,    60,    34,    61,    83,    30,    56,
      56,    56,    56,    56,    34,    50,    34,    16,    21,    83,
      34,    16,    16,    83,    34,    18,    10,    83,    59,    10,
      29,    62,    52,    49,    51,    66,    17,    16,    74,    79,
      10,    81,    83,    60,    83,    61,    49,    49,    67,    16,
      53,    16,    83,    62,    75,    53,    18,    24,    76,    82,
      53,    57,    16,    53
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 62 "compilateur.y"
    {init();}
    break;

  case 7:
#line 70 "compilateur.y"
    {yyerrok;}
    break;

  case 8:
#line 76 "compilateur.y"
    {set_entry_main();}
    break;

  case 10:
#line 82 "compilateur.y"
    {int result = define_function((yyvsp[(2) - (3)].str));
		        if(result==-1){
                    yyerror("try to define a function already define");
                }
		    }
    break;

  case 11:
#line 89 "compilateur.y"
    {end_define_function();}
    break;

  case 12:
#line 90 "compilateur.y"
    {printf("Function definition %s.\n", (yyvsp[(2) - (8)].str));}
    break;

  case 13:
#line 91 "compilateur.y"
    {yyerrok;}
    break;

  case 15:
#line 97 "compilateur.y"
    {add_arg_function((yyvsp[(2) - (2)].str),TYPE_NORMAL);}
    break;

  case 17:
#line 100 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_CONST);}
    break;

  case 19:
#line 103 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_POINTEUR);}
    break;

  case 22:
#line 110 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_NORMAL);}
    break;

  case 24:
#line 113 "compilateur.y"
    {add_arg_function((yyvsp[(4) - (4)].str),TYPE_CONST);}
    break;

  case 26:
#line 116 "compilateur.y"
    {add_arg_function((yyvsp[(4) - (4)].str),TYPE_POINTEUR);}
    break;

  case 28:
#line 122 "compilateur.y"
    {(yyvsp[(1) - (1)].nb)=get_compteur_ebp();set_depth_add1();}
    break;

  case 29:
#line 124 "compilateur.y"
    {set_depth_sub1();set_compteur_ebp((yyvsp[(1) - (3)].nb));}
    break;

  case 40:
#line 139 "compilateur.y"
    {yyerrok;}
    break;

  case 41:
#line 144 "compilateur.y"
    { int result=affect_variable((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].nb));
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }
            }
    break;

  case 42:
#line 153 "compilateur.y"
    { int result=affect_pointeur((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].nb));
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }else if (result==-3){
                  yyerror("trying to point with a non-pointer variable");
              }
            printf("Affectation d'une pointeur\n");}
    break;

  case 45:
#line 175 "compilateur.y"
    {if(declare_variable((yyvsp[(1) - (1)].str),TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
    break;

  case 46:
#line 180 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(1) - (3)].str),TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
    break;

  case 47:
#line 185 "compilateur.y"
    {int result = declare_variable((yyvsp[(2) - (2)].str),TYPE_POINTEUR);
             if (result==-1){yyerror("redefinition of a variable");
             }
            }
    break;

  case 48:
#line 190 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(2) - (4)].str),TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
             }
            }
    break;

  case 51:
#line 203 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(1) - (3)].str),TYPE_CONST)==-1){
                    yyerror("redefinition of a const variable");
                }
            }
    break;

  case 54:
#line 216 "compilateur.y"
    {(yyvsp[(3) - (4)].nb) = get_ebp();(yyvsp[(4) - (4)].nb) = get_compteur_ebp();set_depth_add1();}
    break;

  case 55:
#line 217 "compilateur.y"
    {before_call_function();
		    (yyvsp[(2) - (5)].nb) = get_asmline();}
    break;

  case 56:
#line 220 "compilateur.y"
    {int result = call_function((yyvsp[(1) - (8)].str),(yyvsp[(2) - (8)].nb));
		        if(result==-1){
                    yyerror("trying to call a not define function");
                }
		    }
    break;

  case 57:
#line 225 "compilateur.y"
    {set_depth_sub1();set_compteur_ebp((yyvsp[(4) - (9)].nb));set_ebp((yyvsp[(3) - (9)].nb));}
    break;

  case 58:
#line 226 "compilateur.y"
    {(yyval.nb) = 0;}
    break;

  case 59:
#line 231 "compilateur.y"
    {(yyval.nb)=0;}
    break;

  case 61:
#line 236 "compilateur.y"
    {add_param_function();}
    break;

  case 63:
#line 241 "compilateur.y"
    {add_param_function();}
    break;

  case 64:
#line 246 "compilateur.y"
    {print_symbol_value((yyvsp[(3) - (4)].str));}
    break;

  case 65:
#line 248 "compilateur.y"
    {print_symbol_value((yyvsp[(4) - (5)].str));}
    break;

  case 66:
#line 254 "compilateur.y"
    {int result = create_malloc((yyvsp[(2) - (6)].str));
              if(result==-1){
                  yyerror("trying to malloc to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to malloc to a constant");
              }else if (result==-3){
                  yyerror("trying to malloc a non-pointer variable");
              }
            }
    break;

  case 67:
#line 269 "compilateur.y"
    {create_jump_if();(yyvsp[(2) - (4)].nb) = get_asmline();}
    break;

  case 68:
#line 271 "compilateur.y"
    {set_jump_fin_if((yyvsp[(2) - (6)].nb));(yyvsp[(2) - (6)].nb) = get_asmline();}
    break;

  case 69:
#line 273 "compilateur.y"
    {set_jump_fin_else((yyvsp[(2) - (8)].nb));}
    break;

  case 72:
#line 283 "compilateur.y"
    {(yyvsp[(1) - (1)].nb) = get_asmline();}
    break;

  case 73:
#line 285 "compilateur.y"
    {create_jump_while();(yyvsp[(3) - (4)].nb) = get_asmline();}
    break;

  case 74:
#line 287 "compilateur.y"
    {set_while_jump((yyvsp[(1) - (7)].nb),(yyvsp[(3) - (7)].nb));}
    break;

  case 75:
#line 292 "compilateur.y"
    {(yyvsp[(1) - (4)].nb) = get_asmline();}
    break;

  case 76:
#line 294 "compilateur.y"
    {create_jump_while();(yyvsp[(2) - (7)].nb) = get_asmline();}
    break;

  case 77:
#line 296 "compilateur.y"
    {set_while_jump((yyvsp[(1) - (11)].nb),(yyvsp[(2) - (11)].nb));}
    break;

  case 78:
#line 302 "compilateur.y"
    {(yyval.nb) = tID_value((yyvsp[(1) - (1)].str));}
    break;

  case 79:
#line 304 "compilateur.y"
    {(yyval.nb) = tNB_value((yyvsp[(1) - (1)].nb));}
    break;

  case 80:
#line 306 "compilateur.y"
    {(yyval.nb) = tMULtID_value((yyvsp[(2) - (2)].str));}
    break;

  case 81:
#line 308 "compilateur.y"
    {(yyval.nb) = tADRtID_value((yyvsp[(2) - (2)].str));}
    break;

  case 82:
#line 310 "compilateur.y"
    {(yyval.nb) = (yyvsp[(2) - (3)].nb);}
    break;

  case 84:
#line 313 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(EQEQ);}
    break;

  case 85:
#line 315 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(NEQ);}
    break;

  case 86:
#line 317 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(AND);}
    break;

  case 87:
#line 319 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(NEQ);}
    break;

  case 88:
#line 321 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(ADD);}
    break;

  case 89:
#line 323 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUB);}
    break;

  case 90:
#line 325 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(MUL);}
    break;

  case 91:
#line 327 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(DIV);}
    break;

  case 92:
#line 329 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(INF);}
    break;

  case 93:
#line 331 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUP);}
    break;

  case 94:
#line 333 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(INFEQ);}
    break;

  case 95:
#line 335 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUPEQ);}
    break;

  case 96:
#line 336 "compilateur.y"
    {yyerrok;}
    break;


/* Line 1267 of yacc.c.  */
#line 1988 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
		      yytoken, &yylval);
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 340 "compilateur.y"


static int nb_error;

void printUsage (const char *exec, FILE* stream) {
    fprintf(stream, "Usage: %s input\n", exec) ;
}


void yyerror(char *s) {
    extern int yylineno; /* defined in lex.c*/
    printf(BOLDRED"ERROR: %s on line %d\n"RESET, s, yylineno);
    nb_error++;
}

int main(int argc, char**argv){
    extern FILE*yyin;
    FILE *input;
    if (argc != 2){
        fprintf(stderr, "No input file specified.\n") ;
        printUsage(argv[0], stderr) ;
        return 1;
    }
    yyin = fopen(argv[1], "r") ;
    if (!yyin) {
        fprintf(stderr, "Input file \"%s\" not found.\n", argv[1]) ;
        printUsage(argv[0], stderr) ;
        return 1 ;
    }

    printf("  \n");
    printf(BOLDBLACK "     === Sample program of a C to ASM translator ===     \n" RESET);
    printf(BOLDBLACK "       *** Authors: Rama Desplats & Yuxiao Mao ***           \n" RESET);
    printf("  \n");
    printf(CYAN "                     +++ Parsing +++                      \n\n" RESET);
    yyparse();
    printf("  \n");
    printf(CYAN "                  +++ End of Parsing +++                      \n\n" RESET);

    if (nb_error>0) {
     unlink("result_clair.txt");
     return -1 ;
     //If there are errors then we unlink the asm file
    }
    else{
        printf( BOLDBLACK "==> Creating the files\n\n" RESET );
        print_symbol_table();
        print_asm_instructions();
        write_asm();
        printf("\n");
    }
    return 0;
}

