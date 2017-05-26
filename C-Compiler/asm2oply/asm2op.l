%{
#include "y.tab.h"
%}

/* expression reg */
separateur [ \t\r\n\0\00]
nb -?[0-9]+
reg [R][0-9]+

%option yylineno

%%
"ADD"                   {return tADD;}
"MUL"                   {return tMUL;}
"SUB"                   {return tSUB;}
"DIV"                   {return tDIV;}
"COP"                   {return tCOP;}
"AFC"                   {return tAFC;}
"LOAD"                  {return tLOAD;}
"STORE"                 {return tSTORE;}
"EQU"                   {return tEQU;}
"INF"                   {return tINF;}
"INFE"                  {return tINFE;}
"SUP"                   {return tSUP;}
"SUPE"                  {return tSUPE;}
"JMP"                   {return tJMP;}
"JMPC"                  {return tJMPC;}
"JMPR"                  {return tJMPR;}
"PRT"                   {return tPRT;}

{separateur}            ;
{nb}   					{yylval.nb = atoi(yytext); return tNB; }
{reg} 		            {yylval.str = strdup(yytext);return tREG; }

%%

int yywrap() {return 1;}
