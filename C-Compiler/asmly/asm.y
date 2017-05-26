%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asmfonctions.h"

int yylex(void);
void yyerror(char *s);

%}

/*Union for yyval*/
%union {int nb; char *str;}

/*
* Token defintions and return type defintions for non-terminal token
*/
%token tADD tMUL tSUB tDIV
%token tCOP tAFC
%token tLOAD tSTORE
%token tEQU tINF tINFE tSUP tSUPE
%token tJMP tJMPC tJMPR
%token tPRT //tPUSH tPOP tCALL

%token <nb> tNB
%token <str> tREG

/*
* Entry point for Yacc
*/
%start Prog

%%

Prog :
            {init_asm();}
        Lines
            {execute_asm();}
;

Lines :
		/*epsilon*/
		| Line Lines
;

Line :
         tADD tREG tREG tREG
            {add_asmline_expr(ADD,$2,$3,$4);}
        | tMUL tREG tREG tREG
            {add_asmline_expr(MUL,$2,$3,$4);}
        | tSUB tREG tREG tREG
            {add_asmline_expr(SUB,$2,$3,$4);}
        | tDIV tREG tREG tREG
            {add_asmline_expr(DIV,$2,$3,$4);}
        | tCOP tREG tREG
            {add_asmline_cop($2,$3);}
        | tAFC tREG tNB
            {add_asmline_afc($2,$3);}
        | tLOAD tREG tREG tNB
            {add_asmline_load($2,$3,$4);}
        | tSTORE tREG tNB tREG
            {add_asmline_store($2,$3,$4);}
        | tEQU tREG tREG tREG
            {add_asmline_expr(EQU,$2,$3,$4);}
        | tINF tREG tREG tREG
            {add_asmline_expr(INF,$2,$3,$4);}
        | tINFE tREG tREG tREG
            {add_asmline_expr(INFE,$2,$3,$4);}
        | tSUP tREG tREG tREG
            {add_asmline_expr(SUP,$2,$3,$4);}
        | tSUPE tREG tREG tREG
            {add_asmline_expr(SUPE,$2,$3,$4);}
        | tJMP tNB
            {add_asmline_jmp($2);}
        | tJMPC tNB tREG
            {add_asmline_jmpc($2,$3);}
        | tJMPR tREG
            {add_asmline_jmpr($2);}
        | tPRT tREG
            {add_asmline_prt($2);}
;

%%
void yyerror(char *s) {
    extern int yylineno; /* defined in lex.c*/
    printf("ERROR: %s on line %d\n", s, yylineno);

}

int main(int argc, char**argv){
    extern FILE*yyin;
    FILE *input;
    if ((argc == 2)&&(input = fopen(argv[1],"r"))){
        yyin = input;
    }
    printf("  \n");
    printf("     === Interpretor ASM ===     \n");
    printf("  \n");
    yyparse();
    return 0;
}
