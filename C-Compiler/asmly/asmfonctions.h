#ifndef ASMFONCTIONS_H
#define ASMFONCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

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

/* Define max tab */
#define TOPMEMO 1000
#define MAXINST 1024
#define MAXMEMO 16
#define MAXREGS 32

/* R31 = ebp */

void init_asm();
void execute_asm();

void print_regs();
void print_memo();
void print_inst();

void add_asmline_cop(char*reg1, char*reg2);
void add_asmline_afc(char*reg1, int val);
/* R1 <- [R2(ebp) + val] */
void add_asmline_load(char*reg1, char*regebp, int val);
/* [R1(ebp) + val] -> R3 */
void add_asmline_store(char*regebp, int val, char*reg3);
void add_asmline_jmp(int adr);
/* jmpc adr if R2=0 */
void add_asmline_jmpc(int adr, char*reg2);
void add_asmline_jmpr(char*reg1);

/* print R1 */
void add_asmline_prt(char*reg1);

void add_asmline_expr(int type, char*reg1, char*reg2, char*reg3);

#endif /* ASMFONCTIONS_H */
