%{
#include "y.tab.h"
%}

/* expression reg */
separateur [ \t\r\n]
comment [/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]|"//".*
id [A-Za-z][A-Za-z0-9_]*
nbdec [0-9]+\.[0-9]+
nbexp [0-9]+e[0-9]+
nb [0-9]+

%option yylineno

%%
"\""                    { return tQUOTE; /*not use*/}
"main"                  { return tMAIN; }
"printf"                { return tPRINTF; }
"malloc"                { return tMALLOC; }
"if"                    { return tIF; }
"else"                  { return tELSE; }
"while"                 { return tWHILE; }
"for"                   { return tFOR; }
"return"                { return tRETURN; }
"int"                   { return tINT; }
"const"                 { return tCONST; }
"++"                    { return tINCREMENT; }
"("                     { return tPO; }
")"                     { return tPF; }
"{"                     { return tAO; }
"}"                     { return tAF; }
","                     { return tVIR; }
";"                     { return tPV; }
"=="                    { return tEQEQ; }
"="                     { return tEQ; }
"+"                     { return tADD; }
"-"                     { return tSUB; }
"*"                     { return tMUL; }
"/"                     { return tDIV; }
"!="                    { return tNEQ; }
"&&"                    { return tAND; }
"||"                    { return tOR; }
">"                     { return tSUP; }
"<"                     { return tINF; }
">="                    { return tSUPEQ; }
"<="                    { return tINFEQ; }
"&"                     { return tADR;}


{id}                    { yylval.str = strdup(yytext); return tID; }
{nb}                    { yylval.nb = atoi(yytext); return tNB; }
{nbexp}|{nbdec}         { yylval.nb = (int)atof(yytext); return tNB; }

{comment}               ;
{separateur}            ;

%%

int yywrap() {return 1;}
