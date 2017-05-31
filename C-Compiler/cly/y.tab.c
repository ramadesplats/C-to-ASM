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
     tINCREMENT = 289,
     tID = 290,
     tNB = 291
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
#define tINCREMENT 289
#define tID 290
#define tNB 291




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
#line 15 "compilateur.y"
{int nb; char *str;}
/* Line 193 of yacc.c.  */
#line 183 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 196 "y.tab.c"

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
#define YYLAST   593

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  223

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    10,    13,    17,    18,
      26,    27,    28,    37,    40,    41,    42,    47,    48,    54,
      55,    61,    62,    63,    69,    70,    77,    78,    85,    86,
      87,    94,    95,    99,   100,   101,   106,   107,   112,   113,
     118,   119,   123,   124,   128,   129,   133,   137,   141,   145,
     149,   154,   157,   160,   164,   169,   171,   175,   178,   183,
     184,   188,   192,   193,   197,   198,   199,   200,   201,   212,
     213,   214,   217,   218,   222,   227,   233,   240,   241,   242,
     251,   252,   255,   256,   257,   265,   266,   267,   268,   269,
     284,   286,   288,   291,   294,   297,   300,   304,   306,   310,
     314,   318,   322,   326,   330,   334,   338,   342,   346,   350,
     354
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    -1,    39,    40,    -1,    -1,    41,    -1,
      43,    40,    -1,    41,     1,    18,    -1,    -1,    27,    19,
      42,    17,    77,    16,    54,    -1,    -1,    -1,    27,    35,
      17,    44,    46,    16,    54,    45,    -1,     1,    18,    -1,
      -1,    -1,    27,    35,    47,    50,    -1,    -1,    28,    27,
      35,    48,    50,    -1,    -1,    27,    14,    35,    49,    50,
      -1,    -1,    -1,    29,    27,    35,    51,    50,    -1,    -1,
      29,    28,    27,    35,    52,    50,    -1,    -1,    29,    27,
      14,    35,    53,    50,    -1,    -1,    -1,    31,    55,    58,
      57,    56,    30,    -1,    -1,    32,    93,    18,    -1,    -1,
      -1,    65,    18,    59,    58,    -1,    -1,    66,    18,    60,
      58,    -1,    -1,    71,    18,    61,    58,    -1,    -1,    81,
      62,    58,    -1,    -1,    85,    63,    58,    -1,    -1,    88,
      64,    58,    -1,    79,    18,    58,    -1,    80,    18,    58,
      -1,     1,    18,    58,    -1,    35,    10,    93,    -1,    14,
      35,    10,    93,    -1,    35,    34,    -1,    34,    35,    -1,
      27,    67,    68,    -1,    28,    27,    69,    70,    -1,    35,
      -1,    35,    10,    93,    -1,    14,    35,    -1,    14,    35,
      10,    93,    -1,    -1,    29,    67,    68,    -1,    35,    10,
      93,    -1,    -1,    29,    69,    70,    -1,    -1,    -1,    -1,
      -1,    35,    17,    76,    76,    72,    73,    77,    16,    74,
      75,    -1,    -1,    -1,    93,    78,    -1,    -1,    29,    93,
      78,    -1,    20,    17,    35,    16,    -1,    20,    17,    14,
      35,    16,    -1,    14,    35,    10,    21,    17,    16,    -1,
      -1,    -1,    23,    17,    93,    16,    82,    54,    83,    84,
      -1,    -1,    24,    54,    -1,    -1,    -1,    25,    86,    17,
      93,    87,    16,    54,    -1,    -1,    -1,    -1,    -1,    26,
      17,    65,    18,    89,    93,    18,    90,    35,    34,    91,
      16,    54,    92,    -1,    35,    -1,    36,    -1,    14,    35,
      -1,    33,    35,    -1,    34,    35,    -1,    35,    34,    -1,
      17,    93,    16,    -1,    71,    -1,    93,    15,    93,    -1,
      93,     5,    93,    -1,    93,     8,    93,    -1,    93,     9,
      93,    -1,    93,    12,    93,    -1,    93,    11,    93,    -1,
      93,    14,    93,    -1,    93,    13,    93,    -1,    93,     6,
      93,    -1,    93,     7,    93,    -1,    93,     3,    93,    -1,
      93,     4,    93,    -1,    93,     1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    63,    67,    69,    70,    71,    77,    76,
      83,    90,    82,    92,    95,    98,    97,   101,   100,   104,
     103,   108,   111,   110,   114,   113,   117,   116,   123,   126,
     122,   130,   132,   136,   139,   138,   142,   141,   145,   144,
     148,   147,   151,   150,   154,   153,   156,   157,   158,   162,
     171,   182,   184,   189,   190,   196,   201,   206,   211,   218,
     220,   224,   231,   233,   238,   239,   242,   247,   237,   253,
     256,   258,   261,   263,   267,   269,   275,   291,   293,   290,
     298,   300,   305,   307,   304,   314,   316,   318,   320,   313,
     328,   330,   332,   334,   336,   338,   340,   342,   344,   346,
     348,   350,   352,   354,   356,   358,   360,   362,   364,   366,
     368
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
  "tRETURN", "tADR", "tINCREMENT", "tID", "tNB", "$accept", "Prog", "@1",
  "Fonctions", "Main", "@2", "Fonction", "@3", "@4", "Args", "@5", "@6",
  "@7", "ArgsN", "@8", "@9", "@10", "Body", "@11", "@12", "Return",
  "Insts", "@13", "@14", "@15", "@16", "@17", "@18", "Affectation",
  "Declaration", "Decl1", "DeclN", "Decl1Const", "DeclNConst",
  "Invocation", "@19", "@20", "@21", "@22", "Vide", "Params", "ParamsN",
  "Printf", "Malloc", "If", "@23", "@24", "Else", "While", "@25", "@26",
  "For", "@27", "@28", "@29", "@30", "E", 0
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    40,    40,    42,    41,
      44,    45,    43,    43,    46,    47,    46,    48,    46,    49,
      46,    50,    51,    50,    52,    50,    53,    50,    55,    56,
      54,    57,    57,    58,    59,    58,    60,    58,    61,    58,
      62,    58,    63,    58,    64,    58,    58,    58,    58,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    70,    70,    72,    73,    74,    75,    71,    76,
      77,    77,    78,    78,    79,    79,    80,    82,    83,    81,
      84,    84,    86,    87,    85,    89,    90,    91,    92,    88,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     1,     2,     3,     0,     7,
       0,     0,     8,     2,     0,     0,     4,     0,     5,     0,
       5,     0,     0,     5,     0,     6,     0,     6,     0,     0,
       6,     0,     3,     0,     0,     4,     0,     4,     0,     4,
       0,     3,     0,     3,     0,     3,     3,     3,     3,     3,
       4,     2,     2,     3,     4,     1,     3,     2,     4,     0,
       3,     3,     0,     3,     0,     0,     0,     0,    10,     0,
       0,     2,     0,     3,     4,     5,     6,     0,     0,     8,
       0,     2,     0,     0,     7,     0,     0,     0,     0,    14,
       1,     1,     2,     2,     2,     2,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     3,     0,     0,    13,
       8,     0,     0,     6,     0,    10,     7,    70,    14,     0,
       0,     0,     0,    90,    91,    97,     0,     0,     0,     0,
       0,    92,     0,    93,    94,    69,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    71,     0,    15,     0,     0,    96,    69,    28,
       9,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    21,    17,    11,    64,
       0,    73,    21,     0,    16,    21,    12,    65,     0,     0,
       0,     0,    82,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,    40,    42,    44,    20,     0,     0,
      18,    70,     0,     0,     0,     0,     0,     0,     0,    55,
      59,     0,    52,     0,    51,     0,    29,    34,    36,    38,
       0,     0,     0,     0,     0,     0,    22,     0,     0,    48,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,    53,     0,    62,     0,     0,     0,     0,     0,     0,
      46,    47,    41,    43,    45,    26,    21,    24,    66,     0,
       0,     0,    74,    77,     0,     0,    85,     0,     0,    59,
       0,     0,    54,    32,    30,    35,    37,    39,    21,    23,
      21,    67,     0,    75,     0,     0,     0,     0,     0,    60,
       0,    62,    27,    25,    68,    76,    78,     0,     0,    63,
      80,    84,    86,     0,    79,     0,    81,     0,    87,     0,
       0,    88,    89
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    14,     8,    18,    86,    30,
      76,    85,    82,    84,   166,   190,   188,    60,    80,   156,
     126,    98,   157,   158,   159,   132,   133,   134,    99,   100,
     120,   151,   153,   182,    25,    87,   111,   191,   204,    58,
      26,    52,   102,   103,   104,   194,   210,   214,   105,   116,
     195,   106,   197,   215,   219,   222,    27
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
     -95,     4,     6,   -95,    -9,    39,   -95,    11,     6,   -95,
     -95,    26,    29,   -95,    33,   -95,   -95,    79,   -14,     9,
      79,    16,    17,    25,   -95,   -95,    44,   405,    31,    45,
      57,   -95,   545,   -95,   -95,   -95,   -95,    46,    58,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,   -95,    43,   -95,    48,    46,   -95,   -95,   -95,
     -95,   -95,   177,   196,   215,   234,   253,   272,   291,   310,
     329,   348,   367,   386,   405,   -95,    50,   -95,   -95,   -95,
     108,   -95,    50,   -11,   -95,    50,   -95,   -95,    66,    56,
      68,    75,   -95,    77,    32,    70,    63,    -2,    67,    82,
      83,    84,    86,    88,   -95,   -95,   -95,   -95,    34,    80,
     -95,    79,   108,   101,    35,    79,    99,    27,    90,   107,
      89,    91,   -95,    79,   -95,    79,   -95,   -95,   -95,   -95,
     108,   108,   108,   108,   108,    92,   -95,    95,   103,   -95,
      54,    97,   105,   561,    79,   102,     0,   123,   113,    79,
      32,   -95,   134,   116,   481,   497,   117,   108,   108,   108,
     -95,   -95,   -95,   -95,   -95,   -95,    50,   -95,   -95,   129,
     513,   132,   -95,   -95,   577,   139,   -95,    79,   424,    89,
      79,    91,   -95,   -95,   -95,   -95,   -95,   -95,    50,   -95,
      50,   -95,   135,   -95,    46,   137,    79,    79,   443,   -95,
     462,   116,   -95,   -95,   -95,   -95,   -95,    46,   529,   -95,
     126,   -95,   -95,    46,   -95,   119,   -95,   121,   -95,   140,
      46,   -95,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   151,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -80,   -95,   -95,   -95,   -55,   -95,   -95,
     -95,   -94,   -95,   -95,   -95,   -95,   -95,   -95,    47,   -95,
      12,   -18,   -15,   -38,   -77,   -95,   -95,   -95,   -95,   109,
      59,    94,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -20
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -110
static const yytype_int16 yytable[] =
{
      32,    78,   107,   101,     3,   110,    -4,     4,   123,     9,
     123,    -5,    12,    28,    29,    35,   108,   109,   139,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   124,     5,   124,   101,   160,   161,   162,   163,
     164,   145,    35,    15,    31,    53,   118,    16,   135,   141,
      17,    33,    34,   101,   101,   101,   101,   101,    10,    36,
      37,    96,   146,   185,   186,   187,    54,   119,    19,   136,
     142,    20,    55,    56,    11,   169,    61,    59,    75,    83,
     101,   101,   101,    77,   112,   114,   189,    21,    22,    23,
      24,   113,   115,    19,   117,   143,    20,   121,   122,   125,
     127,   128,   129,   154,   130,   155,   131,   137,   202,    88,
     203,   140,    21,    22,    23,    24,   144,   149,   150,   168,
     170,   172,    89,   177,   174,   148,   152,   165,    90,   178,
     167,    91,   171,    92,    93,    94,    95,   175,   -33,   206,
     -33,   176,    96,    97,   180,   181,   192,   184,   193,   196,
     213,   205,   211,   207,   217,   218,   220,   198,   216,    13,
     200,   199,   179,   209,   147,   221,   201,    79,    81,     0,
     138,     0,     0,     0,     0,     0,   170,   208,    38,     0,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,     0,    46,    47,
      48,    49,    50,  -108,     0,  -108,     0,    38,     0,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -108,    46,    47,    48,
      49,    50,  -109,     0,  -109,     0,    38,     0,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,  -109,    46,    47,    48,    49,
      50,   -99,     0,   -99,     0,    38,     0,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,   -99,    46,    47,    48,    49,    50,
    -106,     0,  -106,     0,    38,     0,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -106,    46,    47,    48,    49,    50,  -107,
       0,  -107,     0,    38,     0,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -107,    46,    47,    48,    49,    50,  -100,     0,
    -100,     0,    38,     0,  -101,  -101,  -101,  -101,  -101,  -101,
    -101,  -100,    46,    47,    48,    49,    50,  -101,     0,  -101,
       0,    38,     0,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -101,  -103,  -103,    48,    49,    50,  -103,     0,  -103,     0,
      38,     0,  -102,  -102,  -102,  -102,  -102,  -102,  -102,  -103,
    -102,  -102,    48,    49,    50,  -102,     0,  -102,     0,    38,
       0,  -105,  -105,  -105,  -105,  -105,  -105,  -105,  -102,  -105,
    -105,  -105,  -105,    50,  -105,     0,  -105,     0,    38,     0,
    -104,  -104,  -104,  -104,  -104,  -104,  -104,  -105,  -104,  -104,
    -104,  -104,    50,  -104,     0,  -104,     0,    38,     0,   -98,
     -98,   -98,   -98,   -98,   -98,   -98,  -104,   -98,   -98,   -98,
     -98,   -98,   -98,     0,   -98,     0,    38,     0,    39,    40,
      41,    42,    43,    44,    45,   -98,    46,    47,    48,    49,
      50,   -72,     0,     0,     0,    38,     0,    39,    40,    41,
      42,    43,    44,    45,    51,    46,    47,    48,    49,    50,
       0,     0,   -56,     0,    38,     0,    39,    40,    41,    42,
      43,    44,    45,   -56,    46,    47,    48,    49,    50,     0,
       0,   -58,     0,    38,     0,    39,    40,    41,    42,    43,
      44,    45,   -58,    46,    47,    48,    49,    50,     0,     0,
     -61,     0,    38,     0,    39,    40,    41,    42,    43,    44,
      45,   -61,    46,    47,    48,    49,    50,     0,    38,   -49,
      39,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,    50,     0,    38,   183,    39,    40,    41,    42,
      43,    44,    45,     0,    46,    47,    48,    49,    50,     0,
      38,   -50,    39,    40,    41,    42,    43,    44,    45,     0,
      46,    47,    48,    49,    50,     0,    38,   212,    39,    40,
      41,    42,    43,    44,    45,     0,    46,    47,    48,    49,
      50,    57,    38,     0,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    47,    48,    49,    50,   173,    38,     0,
      39,    40,    41,    42,    43,    44,    45,     0,    46,    47,
      48,    49,    50,   -83
};

static const yytype_int16 yycheck[] =
{
      20,    56,    82,    80,     0,    85,     0,     1,    10,    18,
      10,     0,     1,    27,    28,    17,    27,    28,   112,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    34,    27,    34,   112,   130,   131,   132,   133,
     134,    14,    17,    17,    35,    14,    14,    18,    14,    14,
      17,    35,    35,   130,   131,   132,   133,   134,    19,    34,
      16,    34,    35,   157,   158,   159,    35,    35,    14,    35,
      35,    17,    27,    16,    35,    21,    18,    31,    35,    29,
     157,   158,   159,    35,    18,    17,   166,    33,    34,    35,
      36,    35,    17,    14,    17,   115,    17,    27,    35,    32,
      18,    18,    18,   123,    18,   125,    18,    27,   188,     1,
     190,    10,    33,    34,    35,    36,    17,    10,    29,    16,
     140,    16,    14,    10,   144,    35,    35,    35,    20,   149,
      35,    23,    35,    25,    26,    27,    28,    35,    30,   194,
      32,    18,    34,    35,    10,    29,    17,    30,    16,    10,
      24,    16,   207,    16,    35,    34,    16,   177,   213,     8,
     180,   179,   150,   201,   117,   220,   181,    58,    74,    -1,
     111,    -1,    -1,    -1,    -1,    -1,   196,   197,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
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
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    29,    11,
      12,    13,    14,    15,    16,    -1,    18,    -1,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    29,    11,    12,
      13,    14,    15,    16,    -1,    18,    -1,     1,    -1,     3,
       4,     5,     6,     7,     8,     9,    29,    11,    12,    13,
      14,    15,    16,    -1,    18,    -1,     1,    -1,     3,     4,
       5,     6,     7,     8,     9,    29,    11,    12,    13,    14,
      15,    16,    -1,    -1,    -1,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    29,    11,    12,    13,    14,    15,
      -1,    -1,    18,    -1,     1,    -1,     3,     4,     5,     6,
       7,     8,     9,    29,    11,    12,    13,    14,    15,    -1,
      -1,    18,    -1,     1,    -1,     3,     4,     5,     6,     7,
       8,     9,    29,    11,    12,    13,    14,    15,    -1,    -1,
      18,    -1,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    29,    11,    12,    13,    14,    15,    -1,     1,    18,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    -1,     1,    18,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    14,    15,    -1,
       1,    18,     3,     4,     5,     6,     7,     8,     9,    -1,
      11,    12,    13,    14,    15,    -1,     1,    18,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    13,    14,
      15,    16,     1,    -1,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    12,    13,    14,    15,    16,     1,    -1,
       3,     4,     5,     6,     7,     8,     9,    -1,    11,    12,
      13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    38,    39,     0,     1,    27,    40,    41,    43,    18,
      19,    35,     1,    40,    42,    17,    18,    17,    44,    14,
      17,    33,    34,    35,    36,    71,    77,    93,    27,    28,
      46,    35,    93,    35,    35,    17,    34,    16,     1,     3,
       4,     5,     6,     7,     8,     9,    11,    12,    13,    14,
      15,    29,    78,    14,    35,    27,    16,    16,    76,    31,
      54,    18,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    35,    47,    35,    54,    76,
      55,    78,    49,    29,    50,    48,    45,    72,     1,    14,
      20,    23,    25,    26,    27,    28,    34,    35,    58,    65,
      66,    71,    79,    80,    81,    85,    88,    50,    27,    28,
      50,    73,    18,    35,    17,    17,    86,    17,    14,    35,
      67,    27,    35,    10,    34,    32,    57,    18,    18,    18,
      18,    18,    62,    63,    64,    14,    35,    27,    77,    58,
      10,    14,    35,    93,    17,    14,    35,    65,    35,    10,
      29,    68,    35,    69,    93,    93,    56,    59,    60,    61,
      58,    58,    58,    58,    58,    35,    51,    35,    16,    21,
      93,    35,    16,    16,    93,    35,    18,    10,    93,    67,
      10,    29,    70,    18,    30,    58,    58,    58,    53,    50,
      52,    74,    17,    16,    82,    87,    10,    89,    93,    68,
      93,    69,    50,    50,    75,    16,    54,    16,    93,    70,
      83,    54,    18,    24,    84,    90,    54,    35,    34,    91,
      16,    54,    92
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
#line 63 "compilateur.y"
    {init();}
    break;

  case 7:
#line 71 "compilateur.y"
    {yyerrok;}
    break;

  case 8:
#line 77 "compilateur.y"
    {set_entry_main();}
    break;

  case 10:
#line 83 "compilateur.y"
    {int result = define_function((yyvsp[(2) - (3)].str));
                if(result==-1){
                    yyerror("try to define a function already define");
                }
                }
    break;

  case 11:
#line 90 "compilateur.y"
    {end_define_function();}
    break;

  case 12:
#line 91 "compilateur.y"
    {/*printf("Function definition %s.\n", $2);*/}
    break;

  case 13:
#line 92 "compilateur.y"
    {yyerrok;}
    break;

  case 15:
#line 98 "compilateur.y"
    {add_arg_function((yyvsp[(2) - (2)].str),TYPE_NORMAL);}
    break;

  case 17:
#line 101 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_CONST);}
    break;

  case 19:
#line 104 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_POINTEUR);}
    break;

  case 22:
#line 111 "compilateur.y"
    {add_arg_function((yyvsp[(3) - (3)].str),TYPE_NORMAL);}
    break;

  case 24:
#line 114 "compilateur.y"
    {add_arg_function((yyvsp[(4) - (4)].str),TYPE_CONST);}
    break;

  case 26:
#line 117 "compilateur.y"
    {add_arg_function((yyvsp[(4) - (4)].str),TYPE_POINTEUR);}
    break;

  case 28:
#line 123 "compilateur.y"
    {(yyvsp[(1) - (1)].nb)=get_compteur_ebp();set_depth_add1();}
    break;

  case 29:
#line 126 "compilateur.y"
    {set_depth_sub1();set_compteur_ebp((yyvsp[(1) - (4)].nb));}
    break;

  case 32:
#line 133 "compilateur.y"
    {set_return_value_to_r0();}
    break;

  case 34:
#line 139 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 36:
#line 142 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 38:
#line 145 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 40:
#line 148 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 42:
#line 151 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 44:
#line 154 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 48:
#line 158 "compilateur.y"
    {yyerrok;}
    break;

  case 49:
#line 163 "compilateur.y"
    { int result=affect_variable((yyvsp[(1) - (3)].str),(yyvsp[(3) - (3)].nb));
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }
            }
    break;

  case 50:
#line 172 "compilateur.y"
    { int result=affect_pointeur((yyvsp[(2) - (4)].str),(yyvsp[(4) - (4)].nb));
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }else if (result==-3){
                  yyerror("trying to point with a non-pointer variable");
              }
            /*printf("Affectation d'une pointeur\n");*/}
    break;

  case 51:
#line 183 "compilateur.y"
    { tIDtINCREMENT_affectation((yyvsp[(1) - (2)].str)); }
    break;

  case 52:
#line 185 "compilateur.y"
    { tINCREMENTtID_affectation((yyvsp[(2) - (2)].str)); }
    break;

  case 55:
#line 197 "compilateur.y"
    {if(declare_variable((yyvsp[(1) - (1)].str),TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
    break;

  case 56:
#line 202 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(1) - (3)].str),TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
    break;

  case 57:
#line 207 "compilateur.y"
    {if (declare_variable((yyvsp[(2) - (2)].str),TYPE_POINTEUR)==-1){
                yyerror("redefinition of a variable");
             }
            }
    break;

  case 58:
#line 212 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(2) - (4)].str),TYPE_POINTEUR)==-1){
                    yyerror("redefinition of a variable");
             }
            }
    break;

  case 61:
#line 225 "compilateur.y"
    {if(declare_variable_affectation((yyvsp[(1) - (3)].str),TYPE_CONST)==-1){
                    yyerror("redefinition of a const variable");
                }
            }
    break;

  case 64:
#line 238 "compilateur.y"
    {(yyvsp[(3) - (4)].nb) = get_ebp();(yyvsp[(4) - (4)].nb) = get_compteur_ebp();set_depth_add1();}
    break;

  case 65:
#line 239 "compilateur.y"
    {before_call_function();
            (yyvsp[(2) - (5)].nb) = get_asmline();}
    break;

  case 66:
#line 242 "compilateur.y"
    {int result = call_function((yyvsp[(1) - (8)].str),(yyvsp[(2) - (8)].nb));
                if(result==-1){
                    yyerror("trying to call a not define function");
                }
            }
    break;

  case 67:
#line 247 "compilateur.y"
    {set_depth_sub1();set_compteur_ebp((yyvsp[(4) - (9)].nb));set_ebp((yyvsp[(3) - (9)].nb));}
    break;

  case 68:
#line 248 "compilateur.y"
    {(yyval.nb) = 0;}
    break;

  case 69:
#line 253 "compilateur.y"
    {(yyval.nb)=0;}
    break;

  case 71:
#line 258 "compilateur.y"
    {add_param_function();}
    break;

  case 73:
#line 263 "compilateur.y"
    {add_param_function();}
    break;

  case 74:
#line 268 "compilateur.y"
    {print_symbol_value((yyvsp[(3) - (4)].str));}
    break;

  case 75:
#line 270 "compilateur.y"
    {print_symbol_value((yyvsp[(4) - (5)].str));}
    break;

  case 76:
#line 276 "compilateur.y"
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

  case 77:
#line 291 "compilateur.y"
    {create_jump_if();(yyvsp[(2) - (4)].nb) = get_asmline();}
    break;

  case 78:
#line 293 "compilateur.y"
    {set_jump_fin_if((yyvsp[(2) - (6)].nb));(yyvsp[(2) - (6)].nb) = get_asmline();}
    break;

  case 79:
#line 295 "compilateur.y"
    {set_jump_fin_else((yyvsp[(2) - (8)].nb));}
    break;

  case 82:
#line 305 "compilateur.y"
    {(yyvsp[(1) - (1)].nb) = get_asmline();}
    break;

  case 83:
#line 307 "compilateur.y"
    {create_jump_while();(yyvsp[(3) - (4)].nb) = get_asmline();}
    break;

  case 84:
#line 309 "compilateur.y"
    {set_while_jump((yyvsp[(1) - (7)].nb),(yyvsp[(3) - (7)].nb));}
    break;

  case 85:
#line 314 "compilateur.y"
    {(yyvsp[(1) - (4)].nb) = get_asmline();}
    break;

  case 86:
#line 316 "compilateur.y"
    {create_jump_while();(yyvsp[(2) - (7)].nb) = get_asmline();}
    break;

  case 87:
#line 318 "compilateur.y"
    {tIDtINCREMENT_value((yyvsp[(9) - (10)].str));}
    break;

  case 88:
#line 320 "compilateur.y"
    {tab_postadd_flush(get_depth());}
    break;

  case 89:
#line 321 "compilateur.y"
    {set_while_jump((yyvsp[(1) - (14)].nb),(yyvsp[(2) - (14)].nb));}
    break;

  case 90:
#line 329 "compilateur.y"
    {(yyval.nb) = tID_value((yyvsp[(1) - (1)].str));}
    break;

  case 91:
#line 331 "compilateur.y"
    {(yyval.nb) = tNB_value((yyvsp[(1) - (1)].nb));}
    break;

  case 92:
#line 333 "compilateur.y"
    {(yyval.nb) = tMULtID_value((yyvsp[(2) - (2)].str));}
    break;

  case 93:
#line 335 "compilateur.y"
    {(yyval.nb) = tADRtID_value((yyvsp[(2) - (2)].str));}
    break;

  case 94:
#line 337 "compilateur.y"
    {(yyval.nb) = tINCREMENTtID_value((yyvsp[(2) - (2)].str));}
    break;

  case 95:
#line 339 "compilateur.y"
    {(yyval.nb) = tIDtINCREMENT_value((yyvsp[(1) - (2)].str));}
    break;

  case 96:
#line 341 "compilateur.y"
    {(yyval.nb) = (yyvsp[(2) - (3)].nb);}
    break;

  case 97:
#line 343 "compilateur.y"
    {(yyval.nb) = get_return_value_from_r0();}
    break;

  case 98:
#line 345 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(EQEQ);}
    break;

  case 99:
#line 347 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(NEQ);}
    break;

  case 100:
#line 349 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(AND);}
    break;

  case 101:
#line 351 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(NEQ);}
    break;

  case 102:
#line 353 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(ADD);}
    break;

  case 103:
#line 355 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUB);}
    break;

  case 104:
#line 357 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(MUL);}
    break;

  case 105:
#line 359 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(DIV);}
    break;

  case 106:
#line 361 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(INF);}
    break;

  case 107:
#line 363 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUP);}
    break;

  case 108:
#line 365 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(INFEQ);}
    break;

  case 109:
#line 367 "compilateur.y"
    {(yyval.nb) = arithmetical_expression(SUPEQ);}
    break;

  case 110:
#line 368 "compilateur.y"
    {yyerrok;}
    break;


/* Line 1267 of yacc.c.  */
#line 2089 "y.tab.c"
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


#line 372 "compilateur.y"


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
        print_asm_instructions();
        write_asm();
        printf("\n");
    }
    return 0;
}

