%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int yylex(void);
void yyerror(char *s);

/* Type definition */
#define ADD 1
#define MUL 2
#define SUB 3
#define DIV 4
#define COP 5
#define AFC 6
#define LOAD 7
#define STORE 8
#define EQU 9
#define INF 10
#define INFE 11
#define SUP 12
#define SUPE 13
#define JMP 14
#define JMPC 15
#define JMPR 16
#define PRT 40

/* conv reg to int*/
int reg2int(char*reg){
    int res = -1;
    char *registre=malloc(sizeof(char)*4);
    strncpy(registre,reg,4);

    if(registre[0]!='R'){
        printf("ERROR: try to converge not Reg");
        exit(-1);
    }else{
        // auto detect \0
        res = atoi(&registre[1]) ;
    }

    free(registre);
    return res;
}

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
%token tPRT

%token <nb> tNB
%token <str> tREG

/*
* Entry point for Yacc
*/
%start Prog

%%

Prog :
        Lines
;

Lines :
		/*epsilon*/
		| Line Lines
;

Line :
         tADD tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", ADD, reg2int($2), reg2int($3), reg2int($4));}
        | tMUL tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", MUL, reg2int($2), reg2int($3), reg2int($4));}
        | tSUB tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", SUB, reg2int($2), reg2int($3), reg2int($4));}
        | tDIV tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", DIV, reg2int($2), reg2int($3), reg2int($4));}
        | tCOP tREG tREG
            {printf("%02X%02X%02X00\n", COP, reg2int($2), reg2int($3));}
        | tAFC tREG tNB
            {printf("%02X%02X%04X\n", AFC, reg2int($2), (unsigned short)$3);}
        | tLOAD tREG tREG tNB
            {printf("%02X%02X%02X%02X\n", LOAD, reg2int($2), reg2int($3), (unsigned char)$4);}
        | tSTORE tREG tNB tREG
            {printf("%02X%02X%02X%02X\n", STORE, reg2int($2), (unsigned char)$3, reg2int($4));}
        | tEQU tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", EQU, reg2int($2), reg2int($3), reg2int($4));}
        | tINF tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", INF, reg2int($2), reg2int($3), reg2int($4));}
        | tINFE tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", INFE, reg2int($2), reg2int($3), reg2int($4));}
        | tSUP tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", SUP, reg2int($2), reg2int($3), reg2int($4));}
        | tSUPE tREG tREG tREG
            {printf("%02X%02X%02X%02X\n", SUPE, reg2int($2), reg2int($3), reg2int($4));}
        | tJMP tNB
            {printf("%02X%02X0000\n", JMP, $2);}
        | tJMPC tNB tREG
            {printf("%02X%02X%02X00\n", JMPC, $2, reg2int($3));}
        | tJMPR tREG
            {printf("%02X%02X0000\n", JMPR, reg2int($2));}
        | tPRT tREG
            {printf("%02X%02X0000\n", JMPR, reg2int($2));}
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
    yyparse();
    return 0;
}
