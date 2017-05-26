%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "fonctions.h"

int yylex(void);
void yyerror(char *s);
int compteur_error;


%}

/*Union for yyval*/
%union {int nb; char *str;}

/*
* Priorities definition on arithmetic expressions' tokens
* Prevents from reduce/reduce and deplacement/reduce conflicts
*/
%left tOR tAND tSUP tINF tNEQ tSUPEQ tINFEQ
%right tEQ
%left tADD tSUB
%left tMUL tDIV
%left tEQEQ
%left tPO tPF
%left error tPV

/*
* Token defintions and return type defintions for non-terminal token
*/
%token tMAIN tPRINTF tMALLOC tQUOTE
%token tIF  tELSE tWHILE tFOR
%token tINT tCONST
/* , ; )  } */
%token tVIR tPV tPF tAF
/* = == && || != > < <= >= */
%token tEQ tEQEQ tAND tOR tNEQ tSUP tINF tSUPEQ tINFEQ
/* + - * / */
%token tADD tSUB tMUL tDIV
%token tPO tAO
%token tRETURN
%token tADR
/* &a = tADR tID, *p = tMUL tID */

%token <str> tID
%token <nb> tNB
%type <nb> E
/* For value saving purpose we use PO and AO as int token */
%type <nb> Invocation tWHILE tELSE tPO tAO tFOR
%type <nb> Vide
%type <str> Fonction

/*
* Entry point
*/
%start Prog

%%
Prog :
			{init();}
		Fonctions
;

Fonctions :
		/*epsilon*/
		| Main
		| Fonction Fonctions
		| Main error tPV {yyerrok;}
;


Main :
        tINT tMAIN
            {set_entry_main();}
        tPO Params tPF Body
;

Fonction :
		tINT tID tPO
		    {int result = define_function($2);
		        if(result==-1){
                    yyerror("try to define a function already define");
                }
		    }
		Args tPF
		Body
		    {end_define_function();}
			{printf("Function definition %s.\n", $2);}
		| error tPV {yyerrok;}
;

Args :
		/*epsilon*/
		| tINT tID
		    {add_arg_function($2,TYPE_NORMAL);}
		ArgsN
		| tCONST tINT tID
		    {add_arg_function($3,TYPE_CONST);}
		ArgsN
		| tINT tMUL tID
		    {add_arg_function($3,TYPE_POINTEUR);}
		ArgsN
;

ArgsN :
		/*epsilon*/
		| tVIR tINT tID
		    {add_arg_function($3,TYPE_NORMAL);}
		ArgsN
		| tVIR tCONST tINT tID
		    {add_arg_function($4,TYPE_CONST);}
		ArgsN
		| tVIR tINT tMUL tID
		    {add_arg_function($4,TYPE_POINTEUR);}
		ArgsN
;

Body :
		tAO
			{$1=get_compteur_ebp();set_depth_add1();}
		Insts
			{set_depth_sub1();set_compteur_ebp($1);}
        tAF
;


Insts :
		/*epsilon*/
		| Affectation tPV Insts
        | Declaration tPV Insts
		| Invocation tPV Insts
		| If Insts
		| While Insts
		| For Insts
        | Printf tPV Insts
        | Malloc tPV Insts
        | error tPV Insts{yyerrok;}
;

Affectation :
		tID tEQ E
            { int result=affect_variable($1,$3);
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }
            }
        | tMUL tID tEQ E
            { int result=affect_pointeur($2,$4);
              if(result==-1){
                  yyerror("trying to affect a value to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to affect a value to a constant");
              }else if (result==-3){
                  yyerror("trying to point with a non-pointer variable");
              }
            printf("Affectation d'une pointeur\n");}

;

Declaration :
		tINT Decl1 DeclN
		| tCONST tINT Decl1Const DeclNConst
;



Decl1 :
		tID
			{if(declare_variable($1,TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
		| tID tEQ E
			{if(declare_variable_affectation($1,TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
                }
            }
        | tMUL tID
            {int result = declare_variable($2,TYPE_POINTEUR);
             if (result==-1){yyerror("redefinition of a variable");
             }
            }
        | tMUL tID tEQ E
            {if(declare_variable_affectation($2,TYPE_NORMAL)==-1){
                    yyerror("redefinition of a variable");
             }
            }
;

DeclN :
		/*epsilon*/
		| tVIR Decl1 DeclN
;

Decl1Const :
		tID tEQ E
			{if(declare_variable_affectation($1,TYPE_CONST)==-1){
                    yyerror("redefinition of a const variable");
                }
            }
;

DeclNConst :
		/*epsilon*/
		| tVIR Decl1Const DeclNConst
;

Invocation :
		tID tPO Vide Vide
		    {$3 = get_ebp();$4 = get_compteur_ebp();set_depth_add1();}
		    {before_call_function();
		    $2 = get_asmline();}
		Params tPF
		    {int result = call_function($1,$2);
		        if(result==-1){
                    yyerror("trying to call a not define function");
                }
		    }
            {set_depth_sub1();set_compteur_ebp($4);set_ebp($3);}
			{$$ = 0;}
;

Vide :
        /*epsilon*/
            {$$=0;}
;

Params :
		/*epsilon*/
		| E ParamsN {add_param_function();}
;

ParamsN :
		/*epsilon*/
		| tVIR E ParamsN {add_param_function();}
;

Printf :
        tPRINTF tPO tID tPF
            {print_symbol_value($3);}
        | tPRINTF tPO tMUL tID tPF
            {print_symbol_value($4);}
;

Malloc :
            /* *p=malloc() */
        tMUL tID tEQ tMALLOC tPO tPF
            {int result = create_malloc($2);
              if(result==-1){
                  yyerror("trying to malloc to an undeclared variable");
              }
              else if (result==-2){
                  yyerror("trying to malloc to a constant");
              }else if (result==-3){
                  yyerror("trying to malloc a non-pointer variable");
              }
            }
;


If :
        tIF tPO E tPF
        	{create_jump_if();$2 = get_asmline();}
        Body
        	{set_jump_fin_if($2);$2 = get_asmline();}
        Else
            {set_jump_fin_else($2);}
;

Else :
		/*epsilon*/
		| tELSE Body
;

While :
		tWHILE
			{$1 = get_asmline();}
		tPO E
			{create_jump_while();$3 = get_asmline();}
		tPF Body
			{set_while_jump($1,$3);}
;

For :
		tFOR tPO Affectation tPV
			{$1 = get_asmline();}
		E tPV
			{create_jump_while();$2 = get_asmline();}
		Affectation tPF Body
			{set_while_jump($1,$2);}
;

/* return index in tab_var of _tmp value */
E :
		tID
		    {$$ = tID_value($1);}
        | tNB
            {$$ = tNB_value($1);}
        | tMUL tID
            {$$ = tMULtID_value($2);}
        | tADR tID
            {$$ = tADRtID_value($2);}
		| tPO E tPF
		    {$$ = $2;}
		| Invocation
		| E tEQEQ E
		    {$$ = arithmetical_expression(EQEQ);}
		| E tNEQ E
		    {$$ = arithmetical_expression(NEQ);}
		| E tAND E
		    {$$ = arithmetical_expression(AND);}
		| E tOR E
		    {$$ = arithmetical_expression(NEQ);}
		| E tADD E
		    {$$ = arithmetical_expression(ADD);}
		| E tSUB E
		    {$$ = arithmetical_expression(SUB);}
        | E tMUL E
            {$$ = arithmetical_expression(MUL);}
		| E tDIV E
		    {$$ = arithmetical_expression(DIV);}
		| E tINF E
		    {$$ = arithmetical_expression(INF);}
		| E tSUP E
		    {$$ = arithmetical_expression(SUP);}
        | E tINFEQ E
            {$$ = arithmetical_expression(INFEQ);}
        | E tSUPEQ E
            {$$ = arithmetical_expression(SUPEQ);}
        | E error tPV {yyerrok;}
;


%%

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
