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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "compilateur.y"
{int nb; char *str;}
/* Line 1529 of yacc.c.  */
#line 123 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

