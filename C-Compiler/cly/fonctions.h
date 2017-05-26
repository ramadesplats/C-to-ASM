#ifndef fonctions_h
#define fonctions_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

/**********************************************************************************
 * Constants and symbols definitions **********************************************************************************/

/* Type definition for the type column of the symbol table*/
#define TYPE_NORMAL 0
#define TYPE_CONST 1
#define TYPE_TMP 2
#define TYPE_POINTEUR 3

/* Type definition for arithmetical operations purpose */
#define EQEQ 10
#define NEQ 11
#define AND 12
#define OR 13
#define ADD 14
#define SUB 15
#define MUL 16
#define DIV 17
#define INF 18
#define SUP 19
#define INFEQ 20
#define SUPEQ 21

/* top adress memory */
#define TOPMEMO 1000
#define MAXTABVAR 100
#define MAXTABINSRTUCT 1024
#define MAXTABFUNC 20

/* Type definition for enhanced printf */
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


/* getter setter */
/* the true esp = ebp + compteur_ebp + compteur_tmp*/
int get_compteur_ebp();
void set_compteur_ebp(int val);
int get_ebp();
void set_ebp(int val);
/* the first instruction begin at line 0 */
int get_asmline();
/* variable depth */
void set_depth_add1();
void set_depth_sub1();
int get_depth();

/* init values of ebp and jump to main function */
void init();

/* file output */
void write_asm();

/* debug info*/
void print_symbol_table();
void print_asm_instructions();

/* function pre-define printf and malloc*/
int print_symbol_value(char*var1);
int create_malloc(char*p);

/* instructions */
/* return -1 if not define, -2 if const */
int affect_variable(char *var1,int adre1);
int affect_pointeur(char *p, int adre1);
/* return -1 if already define at current depth,
* do not declare const with this function*/
int declare_variable(char *var1, int type);
/* return -1 if already define at current depth*/
int declare_variable_affectation(char *var1, int type);

/* expr */
int tID_value(char *id);
int tNB_value(int val);
int tMULtID_value(char *id);
int tADRtID_value(char *id);
int arithmetical_expression(int type);

/* jump if and while */
void create_jump_if();
void set_jump_fin_if(int asmline);
void set_jump_fin_else(int asmline);
void create_jump_while();
void set_while_jump(int asmline_before_cond, int asmline_after_jmpc);

/* function */
void set_entry_main();
/* definition of the function */
/* return -1 if already define */
int define_function(char *id);
void add_arg_function(char *var1,int type);
void end_define_function();
/* invocation of the function */
void before_call_function();
void add_param_function();
/* return -1 if not define */
int call_function(char*id, int asmline_after_before_call);

/* error */
extern void PrintError(char *errorstring, ...);

#endif /* fonctions_h */
