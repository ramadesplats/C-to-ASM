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
     tADD = 258,
     tMUL = 259,
     tSUB = 260,
     tDIV = 261,
     tCOP = 262,
     tAFC = 263,
     tLOAD = 264,
     tSTORE = 265,
     tEQU = 266,
     tINF = 267,
     tINFE = 268,
     tSUP = 269,
     tSUPE = 270,
     tJMP = 271,
     tJMPC = 272,
     tJMPR = 273,
     tPRT = 274,
     tNB = 275,
     tREG = 276
   };
#endif
/* Tokens.  */
#define tADD 258
#define tMUL 259
#define tSUB 260
#define tDIV 261
#define tCOP 262
#define tAFC 263
#define tLOAD 264
#define tSTORE 265
#define tEQU 266
#define tINF 267
#define tINFE 268
#define tSUP 269
#define tSUPE 270
#define tJMP 271
#define tJMPC 272
#define tJMPR 273
#define tPRT 274
#define tNB 275
#define tREG 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 49 "asm2op.y"
{int nb; char *str;}
/* Line 1529 of yacc.c.  */
#line 93 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

