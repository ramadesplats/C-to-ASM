#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asmfonctions.h"

/* def struct */
typedef struct {
    int type;
    int val1;
    int val2;
    int val3;
} type_instruct;

/* def tab */
type_instruct inst[MAXINST];
int memo[MAXMEMO];
int regs[MAXREGS];

/* def var */
int compteur_inst;

/* decl fonc inter */
int reg2int(char*reg);
int add_inst(int type, int val1, int val2, int val3);
int execute_line(int ip);

/* init & execute */
void init_asm(){
    compteur_inst = 0;
}

void execute_asm(){
    int ip = 0;
    char f;
    printf("BEGIN of execute_asm\n");
    printf("INST ACTUEL: APPUYER\n");
    while (ip<compteur_inst){
        getchar();
        printf("INST[%d] = %d %d %d %d\n", ip, inst[ip].type,
                inst[ip].val1, inst[ip].val2, inst[ip].val3);
        print_regs();
        print_memo();
        printf("----------------------\n");
        ip = execute_line(ip);
    }

    printf("\nEND execute_asm or MEMO insufficiant\n");
    print_regs();
    print_memo();
}

/* print */
void print_regs(){
    int i;
    for(i=0;i<10;i++){
        printf("R%d = %d\n", i, regs[i]);
    }
    printf("R29 = %d\n", regs[29]);
    printf("R30 = %d\n", regs[30]);
    printf("R31 = %d\n", regs[31]);
}

void print_memo(){
    int i;
    for(i=0;i<20;i++){
        printf("MEMO[%d] = %d\n", TOPMEMO+i, memo[i]);
    }
}

void print_inst(){
    int i;
    for(i=0;i<compteur_inst;i++){
        printf("INST[%d] = %d %d %d %d\n", i, inst[i].type,
                inst[i].val1, inst[i].val2, inst[i].val3);
    }
}

/* add_asmline */
void add_asmline_cop(char*reg1, char*reg2){
    int val1 = reg2int(reg1);
    int val2 = reg2int(reg2);
    add_inst(COP,val1,val2,0);
}

void add_asmline_afc(char*reg1, int val){
    int val1 = reg2int(reg1);
    add_inst(AFC,val1,val,0);
}

void add_asmline_load(char*reg1, char*regebp, int val){
    int val1 = reg2int(reg1);
    int valebp = reg2int(regebp);
    add_inst(LOAD,val1,valebp,val);
}

void add_asmline_store(char*regebp, int val, char*reg3){
    int valebp = reg2int(regebp);
    int val3 = reg2int(reg3);
    add_inst(STORE,valebp,val,val3);
}

void add_asmline_jmp(int adr){
    add_inst(JMP,adr,0,0);
}

void add_asmline_jmpc(int adr, char*reg2){
    int val2 = reg2int(reg2);
    add_inst(JMPC,adr,val2,0);
}

void add_asmline_jmpr(char*reg1){
    int val1 = reg2int(reg1);
    add_inst(JMPR,val1,0,0);
}

void add_asmline_prt(char*reg1){
    int val1 = reg2int(reg1);
    add_inst(PRT, val1, 0, 0);
}

void add_asmline_expr(int type, char*reg1, char*reg2, char*reg3){
    int val1 = reg2int(reg1);
    int val2 = reg2int(reg2);
    int val3 = reg2int(reg3);
    add_inst(type, val1, val2, val3);
}


/*************************************************************/
/* code fonc inter*/
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

int add_inst(int type, int val1, int val2, int val3){
    inst[compteur_inst].type = type;
    inst[compteur_inst].val1 = val1;
    inst[compteur_inst].val2 = val2;
    inst[compteur_inst].val3 = val3;
    compteur_inst ++;
}


/* execute */
int execute_line(int ip){
    int nextip = ip + 1;
    int type = inst[ip].type;
    int val1 = inst[ip].val1;
    int val2 = inst[ip].val2;
    int val3 = inst[ip].val3;

    switch (type) {
        case ADD:
            regs[val1] = regs[val2] + regs[val3];
            break;
        case MUL:
            regs[val1] = regs[val2] * regs[val3];
            break;
        case SUB:
            regs[val1] = regs[val2] - regs[val3];
            break;
        case DIV:
            regs[val1] = regs[val2] / regs[val3];
            break;
        case COP:
            regs[val1] = regs[val2];
            break;
        case AFC:
            regs[val1] = val2;
            break;
        case LOAD:
            regs[val1] = memo[regs[val2] + val3 - TOPMEMO];
            break;
        case STORE:
            memo[regs[val1] + val2 - TOPMEMO] = regs[val3];
            break;
        case EQU:
            if (regs[val2] == regs[val3]){
                regs[val1] = 1;
            }else{
                regs[val1] = 0;
            }
            break;
        case INF:
            if (regs[val2] < regs[val3]){
                regs[val1] = 1;
            }else{
                regs[val1] = 0;
            }
            break;
        case INFE:
            if (regs[val2] <= regs[val3]){
                regs[val1] = 1;
            }else{
                regs[val1] = 0;
            }
            break;
        case SUP:
            if (regs[val2] > regs[val3]){
                regs[val1] = 1;
            }else{
                regs[val1] = 0;
            }
            break;
        case SUPE:
            if (regs[val2] >= regs[val3]){
                regs[val1] = 1;
            }else{
                regs[val1] = 0;
            }
            break;
        case JMP:
            nextip = val1;
            break;
        case JMPC:
            if (regs[val2] == 0){
                nextip = val1;
            }
            break;
        case JMPR:
            nextip = regs[val1];
            break;
        case PRT:
            printf("Value of REG[%d] is %d\n",val1,regs[val1]);
            break;
        default:
            printf("Make sure you have inserted the right operation type\n");
            printf("It should be of type ==  !=  &&  ||  +  -  *  / <  >  <=  >=\n");
            return -1;
            break;
    }
    return nextip;
}
