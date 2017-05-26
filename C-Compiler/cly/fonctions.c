#include "fonctions.h"

/**********************************************************************************
 * Constants and symbols definitions **********************************************************************************/

/* Structure used to represent the symbol table*/
typedef struct {
    char *id;
    int init;
    int adresse;
    int type;
    int depth;
} type_tabvar;

typedef struct {
    char *instruct;
    char *reg1;
    char *reg2;
    char *reg3;
} type_tab_instruct;

typedef struct {
    char *id;
    int nbarg;
    int begin_asm;
} type_tab_func;

/* The symbol table */
type_tabvar tabvar[MAXTABVAR];

/* Array of ASM instructions */
type_tab_instruct tab_instruct[MAXTABINSRTUCT];

/* The function table */
type_tab_func tab_func[MAXTABFUNC];

/* Global variable declarations*/
int compteur_ebp;
int compteur_tmp;
int current_depth;
int compteur_asm;
int ebp;
int compteur_func;
int isAdress;


/* func interne
******************************/
void tab_inst_addline(char* inst, char* reg1, char* reg2,char* reg3);
void tab_inst_set_reg1(int asmline, char* reg1);//jmp
void tab_inst_set_reg2(int asmline, char* reg2);//afc
/* return index of var in tab_var*/
int tab_var_add(char*id, int type);
int tab_var_addtmp(int val);
/* func */
void tab_func_add(char*id);
void tab_func_nbarg_add1();
int find_func(char*id);
/* return index of var in tab_var, or -1 not find*/
int find_var(char*var);
int arithmetical_E2E(int type);

/* getter setter
******************************/
int get_compteur_ebp(){
    return compteur_ebp;
}

void set_compteur_ebp(int val){
    compteur_ebp = val;
}

int get_ebp(){
    return ebp;
}

void set_ebp(int val){
    ebp = val;
}

int get_asmline(){
	return compteur_asm;
}

void set_depth_add1(){
    current_depth = current_depth + 1 ;
}

void set_depth_sub1(){
    current_depth = current_depth - 1;
}

int get_depth(){
    return current_depth;
}

/* to know if in an affectation, the value is an address or not */

int get_isAdress(){
    return isAdress;
}

void set_isAdress(int val){
    isAdress=val;
}

/* init values of ebp and jump to main function
******************************/
void init(){
    char *charvalue=malloc(sizeof(char)*2);

    sprintf(charvalue,"%d",TOPMEMO);
    tab_inst_addline("AFC","R31",charvalue,"");
    tab_inst_addline("JMP","X","","");

    free(charvalue);
}

/* file output
******************************/
void write_asm(){
    int iterator;
    printf( BOLDBLACK "\n==> Creating the files\n\n" RESET );
    FILE* fichier=fopen("result_clair.txt", "w");
    printf( BOLDBLACK "\n==> Writing ASMLines in file\n\n" RESET );
    for(iterator=0;iterator<compteur_asm;iterator++){
        fwrite(tab_instruct[iterator].instruct, 1, sizeof(char)*5, fichier);
        fwrite(" ",1,sizeof(char),fichier);
        fwrite(tab_instruct[iterator].reg1, 1, sizeof(char)*4, fichier);
        fwrite(" ",1,sizeof(char),fichier);
        fwrite(tab_instruct[iterator].reg2, 1, sizeof(char)*4, fichier);
        fwrite(" ",1,sizeof(char),fichier);
        fwrite(tab_instruct[iterator].reg3, 1, sizeof(char)*4, fichier);
        fwrite("\n",1,sizeof(char),fichier);
    }
    fclose(fichier);
}

/* debug info: print
******************************/
void print_symbol_table(){
    int iterator;
    printf(BOLDYELLOW"PRINT_SYMBOL_TABLE:ebp:%d, compteur_ebp:%d, compteur_tmp:%d\n"RESET, ebp, compteur_ebp, compteur_tmp);
    printf("------------------------------------------------------------------------\n");
    printf("|####################### ");
    printf(BOLDBLACK "TABLE DES SYMBOLES " RESET);
    printf("###########################|\n");
    printf("|----------------------------------------------------------|\n");
    printf("|   var   |   init   |   type    |   adresse   |   depth   |\n");
    printf("|----------------------------------------------------------|\n");
    for(iterator=0;iterator<ebp+compteur_ebp+compteur_tmp;iterator++){
        if (tabvar[iterator].id == NULL){
            printf("|   _tmp   |");
        }else{
            printf("|   %s   |",tabvar[iterator].id);
        }
        if(tabvar[iterator].init==0){
            printf(RED " not_init " RESET);
            printf("|   ");
        }
        else{
            printf(GREEN "   init   " RESET);
            printf("|   " );
        }
        if(tabvar[iterator].type==0){
            printf("int   |   ");
        }
        else if(tabvar[iterator].type==1){
            printf("const |   ");
        }
        else if(tabvar[iterator].type==2){
            printf("tmp   |   ");
        }
        else{
            printf("ptr   |   ");
        }
        printf("%d   |   ",tabvar[iterator].adresse);
        printf("%d   |   \n",tabvar[iterator].depth);
    }
    printf("------------------------------------------------------------------------\n");
}

void print_asm_instructions(){
    int iterator;
    printf("----------------------------------------------------------------------\n");
    printf("|###################### ");
    printf(BOLDBLACK "ASM INSTRUCT ARRAY " RESET);
    printf("##########################|\n");
    printf("|--------------------------------------------------------------------|\n");
    printf(CYAN "==> lines are printed for debug purposes\n\n"RESET);
    for(iterator=0;iterator<compteur_asm;iterator++){
        printf("line %d - ",iterator);
        if (strcmp(tab_instruct[iterator].instruct,"LOAD")==0 || strcmp(tab_instruct[iterator].instruct,"JMPC")==0){
            printf(BOLDBLACK"%s  ",tab_instruct[iterator].instruct);
            printf(RESET);
        }
        else if(strcmp(tab_instruct[iterator].instruct,"STORE")==0){
            printf(BOLDBLACK "%s ",tab_instruct[iterator].instruct);
            printf(RESET);
        }
        else{
            printf(BOLDBLACK "%s   ",tab_instruct[iterator].instruct);
            printf(RESET);
        }
        printf(BOLDBLACK"%s   ",tab_instruct[iterator].reg1);
        printf("%s   ",tab_instruct[iterator].reg2);
        printf("%s\n",tab_instruct[iterator].reg3);
        printf(RESET);
    }
    printf("----------------------------------------------------------------------\n");
}


/* pre-define function
******************************/
int print_symbol_value(char*var1){
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(var1);
    if (index != -1){
        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("LOAD","R0","R31",charvalue);
        tab_inst_addline("PRT","R0","","");
    }
    free(charvalue);
    return index;
}


/* return -1 if not define, -2 if const, -3 if type normal */
/* this function will create an varX (no initialized so can contain something)
* and let p point varX. With this implementation, the malloc will be automaticly free
* after the programme leave this stage of depth */
int create_malloc(char*p){
    int result=-1;
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(p);
    int index2;

    if(index == -1){
        result = -1;
    }else if(tabvar[index].type==TYPE_CONST){
        result = -2;
    }else if(tabvar[index].type==TYPE_NORMAL) {
        result = -3;
    }else{//type=TYPE_POINTEUR
        result = 0;
        tabvar[index].init=1;
        // if *p = malloc() then consider it is initialized

        index2 = tab_var_add("_vpt", TYPE_NORMAL);
        // but in index2 there can be an other value, it is not really "initialised"
        tabvar[index2].init=1;

        //asm
        sprintf(charvalue,"%d", (index2-ebp));
        tab_inst_addline("AFC","R0",charvalue,"");
        //@_vpt=index2
        // R0 = index2 = ebp + (index2-ebp)
        tab_inst_addline("ADD","R0","R31","R0");
        // store index2 in the @_vpt
        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("STORE","R31",charvalue,"R0");

        //debug info
        printf(CYAN "\n==> " RESET);
        printf("Malloc *pointeur %s\n", p);
    }

    free(charvalue);
    return 0;
}

/* instructions
******************************/
/* return -1 if not define, -2 if const */
int affect_variable(char *var1,int adre1){
    int result=-1;
    char *charvalue=malloc(sizeof(char)*2);

    int index = find_var(var1);

    if(index == -1){
        result = -1;
    }else if(tabvar[index].type==TYPE_CONST){
        result = -2;
    }else{
        result = 0;

        //asm
        sprintf(charvalue,"%d", (adre1-ebp));
        tab_inst_addline("LOAD","R0","R31",charvalue);
        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("STORE","R31",charvalue,"R0");

        //init or warning
        if(tabvar[index].type==TYPE_NORMAL){
            tabvar[index].init=1;
            if(get_isAdress()==1){
            printf(BOLDYELLOW"warning: try to affect an adress to a normal variable %s \n"RESET,var1);
            }
        }else if (tabvar[index].type==TYPE_POINTEUR){
            if(get_isAdress()==1){
                tabvar[index].init=1;
            }else{//not adress
                printf(BOLDYELLOW"warning: try to affect a normal value to a pointer %s\n"RESET, var1);
            }
        }

        print_symbol_table();
        //debug info
        printf(CYAN "\n==> " RESET);
        printf("Affectation %s\n", var1);
        /* at adr1 we have the temporary value for var1
        * That is why we decrement the temporary variable counter.
        */
        printf(YELLOW "Removing tmp variable at adress +%d.\n"RESET,compteur_tmp);
    }

    set_isAdress(0);
    compteur_tmp--;
    free(charvalue);
    return result;
}

/* return -1 if not define, -2 if const, -3 if type normal */
int affect_pointeur(char *p, int adre1){
    int result=-1;
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(p);

    if(index == -1){
        result = -1;
    }else if(tabvar[index].type==TYPE_CONST){
        result = -2;
    }else if(tabvar[index].type==TYPE_NORMAL) {
        result = -3;
    }else{//type=TYPE_POINTEUR

        sprintf(charvalue,"%d", compteur_ebp);
        tab_inst_addline("LOAD","R0","R31",charvalue);
        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("LOAD","R1","R31",charvalue);
        tab_inst_addline("STORE","R1","0","R0");

        //debug info
        printf(CYAN "\n==> " RESET);
        printf("Affectation pointeur %s, make sure that p contains a correct adress\n", p);
        if(get_isAdress()==1){
            printf(BOLDYELLOW"warning: try to affect an adresse to *pointer %s\n"RESET,p);
        }
        /* at adr1 we have the temporary value for var1
        * That is why we decrement the temporary variable counter.
        */
        printf(YELLOW "Removing tmp variable at adress +%d.\n" RESET,compteur_tmp);
    }

    set_isAdress(0);
    compteur_tmp--;
    free(charvalue);
    return 0;
}

/* return -1 if already define at current depth*/
int declare_variable(char *var1, int type){
    int result = 0;
    printf(GREEN "\n==> " RESET);
    printf("Declaration %s.\n", var1);
    int index = find_var(var1);
    if(index == -1){//not define
        tab_var_add(var1, type);
    }else if (current_depth==tabvar[index].depth){
        return -1;
    }else{//not define at current depth
        tab_var_add(var1, type);
    }

    return result;
}

/* return -1 if already define at current depth*/
int declare_variable_affectation(char *var1, int type){
    int result = 0;
    printf(GREEN "==> " RESET);
    printf("Declaration with affectation %s.\n", var1);
    int index = find_var(var1);
    int index2;

    if(index == -1){//not define
    }else if (current_depth==tabvar[index].depth){
        return -1;
    }else{//not define at current depth
    }

    index2 = tab_var_add(var1, type);
    tabvar[index2].init=1;

    //debug info
    if((type==TYPE_POINTEUR)&&(get_isAdress()==0)){
            printf(BOLDYELLOW"warning: try to affect a normal value to a pointer %s\n"RESET, var1);
    }
    if((type==TYPE_NORMAL)&&(get_isAdress()==1)){
            printf(BOLDYELLOW"warning: try to affect an adress to a normal variable %s\n"RESET,var1);
    }

    // no need asm because the tmp value is at the right place
    // value in memo existed when calcul E _tmp
    set_isAdress(0);
    compteur_tmp--;

    return result;
}



/* expr
******************************/
int tID_value(char *id){
    int result = -1;
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(id);

    if(index == -1){//not define
        result = -1;
    }else{
        // we cant know the value in memo[index]
        // but we need a new val tmp to store this value
        result = tab_var_addtmp(0);

        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("LOAD","R0","R31",charvalue);
        sprintf(charvalue,"%d",(result-ebp));
        tab_inst_addline("STORE","R31",charvalue,"R0");

        //if id is a pointer, then its value is an adress
        if (tabvar[index].type==TYPE_POINTEUR){
            set_isAdress(1);
        }
    }

    free(charvalue);
    return result;
}

int tNB_value(int val){
    int index = -1;
    char *charvalue=malloc(sizeof(char)*2);

    index = tab_var_addtmp(val);

    sprintf(charvalue,"%d",val);
    tab_inst_addline("AFC","R1",charvalue,"");
    sprintf(charvalue,"%d",(index-ebp));
    tab_inst_addline("STORE","R31",charvalue,"R1");

    free(charvalue);
    return index;
}


int tMULtID_value(char*id){
    int result = -1;
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(id);

    if(index == -1){//not define
        result = -1;
    }else{
        // we need the value of memo[@] where @=memo[index]
        // but we need a new val tmp to store this value
        result = tab_var_addtmp(0);

        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("LOAD","R0","R31",charvalue);
        tab_inst_addline("LOAD","R0","R0","0");
        sprintf(charvalue,"%d",(result-ebp));
        tab_inst_addline("STORE","R31",charvalue,"R0");
    }

    free(charvalue);
    return result;
}

int tADRtID_value(char*id){
    int result = -1;
    char *charvalue=malloc(sizeof(char)*2);
    int index = find_var(id);

    if(index == -1){//not define
        result = -1;
    }else{
        // we need the value of &index = TOPMEMO + index = ebp + (index-ebp)
        // but we need a new val tmp to store this value
        result = tab_var_addtmp(0);

        sprintf(charvalue,"%d",(index-ebp));
        tab_inst_addline("AFC","R0",charvalue,"");
        tab_inst_addline("ADD","R0","R31","R0");
        sprintf(charvalue,"%d",(result-ebp));
        tab_inst_addline("STORE","R31",charvalue,"R0");

        set_isAdress(1);
    }

    free(charvalue);
    return result;
}

int arithmetical_expression(int type){
    int result = -1;
    switch (type) {
        case EQEQ:
            result = arithmetical_E2E(type);
            break;
        case NEQ:
            result = arithmetical_E2E(type);
            break;
        case AND:
            break;
        case OR:
            break;
        case ADD:
            result = arithmetical_E2E(type);
            break;
        case SUB:
            result = arithmetical_E2E(type);
            break;
        case MUL:
            result = arithmetical_E2E(type);
            break;
        case DIV:
            result = arithmetical_E2E(type);
            break;
        case INF:
            result = arithmetical_E2E(type);
            break;
        case SUP:
            result = arithmetical_E2E(type);
            break;
        case INFEQ:
            result = arithmetical_E2E(type);
            break;
        case SUPEQ:
            result = arithmetical_E2E(type);
            break;
        default:
            printf("Make sure you have inserted the right operation type\n");
            printf("It should be of type ==  !=  &&  ||  +  -  *  / <  >  <=  >=\n");
            break;
    }
    return result;
}


/* jump
******************************/
void create_jump_if(){
	char *charvalue=malloc(sizeof(char)*2);

    // asm get _tmp & load value
    sprintf(charvalue,"%d",(compteur_ebp+compteur_tmp-1));
    tab_inst_addline("LOAD","R0","R31",charvalue);
    tab_inst_addline("JMPC","X","R0","");//R0=cond

	// remove condition
	compteur_tmp--;

    free(charvalue);
}

void set_jump(int asmline){
	char *charvalue=malloc(sizeof(char)*2);

    // set at next asm line
    sprintf(charvalue,"%d",get_asmline());
    tab_inst_set_reg1(asmline-1,charvalue);
    printf(MAGENTA"Set jump of asm_line %d destination:%s\n"RESET, asmline, charvalue);
    free(charvalue);
}

void set_jump_fin_if(int asmline){
    tab_inst_addline("JMP","X","","");
    set_jump(asmline);
}

void set_jump_fin_else(int asmline){
    set_jump(asmline);
}

void create_jump_while(){
	create_jump_if();
}

void set_while_jump(int asmline_before_cond, int asmline_after_jmpc){
	char *charvalue=malloc(sizeof(char)*2);

	// set JMP for begin cond
	sprintf(charvalue,"%d",asmline_before_cond);
    tab_inst_addline("JMP",charvalue,"","");

    // set JMPC
    set_jump(asmline_after_jmpc);

    free(charvalue);
}

/* function
******************************/
void set_entry_main(){
    char *charvalue=malloc(sizeof(char)*2);

    sprintf(charvalue,"%d",get_asmline());
    tab_inst_set_reg1(1, charvalue);

    free(charvalue);
}

/* define part of the funtion
* when we jump at the first line of a function,
* we supporse there are already oldebp, return address, all argument value in the memory
* and the memory begin at the new "ebp", which can change at evey call of funtion,
* with that, we're not crashing any existing data, especially in recursive call
* in our case, ebp is store in R31 */
int define_function(char *id){
    int index;

    if (find_func(id) != -1){
        return -1;
    }

    // add this function in to tab_func
    tab_func_add(id);
    // prepare the C environnement and let the compiler know there are already these values
    // [ebp + 0] = old ebp
    index = tab_var_add("_ebp", TYPE_NORMAL);
    tabvar[index].init = 1;
    // [ebp + 1] = return address
    index = tab_var_add("_adr", TYPE_NORMAL);
    tabvar[index].init = 1;

    return 0;
}

// [ebp + 2] = 1st arg
void add_arg_function(char *var1, int type){
    int index;

    tab_func_nbarg_add1();
    // it is just like we have define some variable before arrive the body of our function
    index = tab_var_add(var1, type);
    if (index >= 0){
        tabvar[index].init = 1;
        tabvar[index].type = type;
    }

    printf("Add arg function %s. index %d\n",var1, index);
    set_isAdress(0);
}

/* at the end of the function, the execution is suppose to return to the old situation,
* so we restore the ebp and jump to the return address.
* we'll also clean the C environnement by set compteur_ebp = 0,
* be ready to begin the define of another function*/
void end_define_function(){
    // add JMP to return address [ebp + 1]
    tab_inst_addline("LOAD","R1","R31","1");
    // restore ebp
    tab_inst_addline("LOAD","R31","R31","0");
    tab_inst_addline("JMPR","R1","","");
    set_compteur_ebp(0);
    ebp = 0;
}

/* call part of the function
* we must prepare ebp and return address at the top of memory before the real call */
void before_call_function(){
    // preparation memoire + variables
    int index;
    char *charvalue=malloc(sizeof(char)*2);

    // [esp] = old ebp
    sprintf(charvalue,"%d",compteur_ebp);
    tab_inst_addline("STORE","R31",charvalue,"R31");
    // ebp = esp (ebp+compteur_ebp)
    tab_inst_addline("AFC","R0",charvalue,"");
    tab_inst_addline("ADD","R31","R31","R0");
    ebp = ebp + compteur_ebp;
    compteur_ebp = 0;
    // tabvar + [_ebp]
    index = tab_var_add("_ebp", TYPE_NORMAL);
    tabvar[index].init = 1;
    // [ebp + 1] = return address
    tab_inst_addline("AFC","R0","X","");
    tab_inst_addline("STORE","R31","1","R0");
    // tabvar +[_adr]
    index = tab_var_add("_adr", TYPE_NORMAL);
    tabvar[index].init = 1;

    free(charvalue);

}

void add_param_function(){
    printf(GREEN "ADD param, ebp:%d,compteur_ebp:%d,compt_tmp:%d\n" RESET, ebp, compteur_ebp, compteur_tmp);
    // [ebp + 2] = 1st param
    // the value is already at the right space by using the E expression
    // so we just need to indicate that the _tmp variable is a real variable
    compteur_tmp--;
    compteur_ebp++;
    set_isAdress(0);
}

int call_function(char*id, int asmline_after_before_call){
    int index_func;
    char *charvalue=malloc(sizeof(char)*2);

    index_func = find_func(id);
    if (index_func == -1){
        printf(BOLDYELLOW "warning: calling an not define function\n"RESET);
        return -1;
    }

    if ((compteur_ebp-2)!=tab_func[index_func].nbarg) {
        printf(BOLDYELLOW "warning: calling function without the right nb of argument\n"RESET);
    }

    // affectation @retour
    sprintf(charvalue,"%d",get_asmline()+1);
    tab_inst_set_reg2(asmline_after_before_call - 2, charvalue);
    // jmp @func
    sprintf(charvalue,"%d",tab_func[index_func].begin_asm);
    tab_inst_addline("JMP",charvalue,"","");

    // fin call function
    // esp<-ebp, set_ebp(ebp<-oldebp) is in the code yacc

    free(charvalue);
    return index_func;
}

/******************************
* code func interne
******************************/
void tab_inst_addline(char* inst, char* reg1, char* reg2,char* reg3){
    if (compteur_asm>=MAXTABINSRTUCT){
        printf("WARNING: max tab instuct atteint!\n");
    }

    tab_instruct[compteur_asm].instruct=malloc(sizeof(char)*5);
    tab_instruct[compteur_asm].reg1=malloc(sizeof(char)*4);
    tab_instruct[compteur_asm].reg2=malloc(sizeof(char)*4);
    tab_instruct[compteur_asm].reg3=malloc(sizeof(char)*4);

    (tab_instruct[compteur_asm].instruct)[4]='\0';

    strcpy(tab_instruct[compteur_asm].instruct,inst);
    strcpy(tab_instruct[compteur_asm].reg1,reg1);
    strcpy(tab_instruct[compteur_asm].reg2,reg2);
    strcpy(tab_instruct[compteur_asm].reg3,reg3);

    compteur_asm++;
}

void tab_inst_set_reg1(int asmline, char* reg1){
    strcpy(tab_instruct[asmline].reg1,reg1);
}

void tab_inst_set_reg2(int asmline, char* reg2){
    strcpy(tab_instruct[asmline].reg2,reg2);
}

int tab_var_add(char*id, int type){
    int index = ebp+compteur_ebp;
    tabvar[index].id=id;
    tabvar[index].adresse=TOPMEMO+index;
    tabvar[index].type=type;
    tabvar[index].init=0;
    tabvar[index].depth=current_depth;
    printf(BLUE "Added %s at adress %d, depth=%d.\n", id, ebp+compteur_ebp, current_depth);
    printf(RESET);

    compteur_ebp++;
    return index;
}

int tab_var_addtmp(int val){
    int index = ebp+compteur_ebp+compteur_tmp;
    //no malloc because dont want free
    tabvar[index].id=NULL;
    tabvar[index].adresse=TOPMEMO+index;
    tabvar[index].type=TYPE_TMP;
    printf("Added temporary %s at index %d with value %d.\n", tabvar[index].id, index, val);

    compteur_tmp++;
    return index;
}

/* return index of var, or -1 not find*/
int find_var(char*var){
    int index;
    for(index=ebp+compteur_ebp-1;index>=0;index--){
        if(strcmp(tabvar[index].id,var)==0){
            break;
        }
    }
    return index;
}

void tab_func_add(char*id){
    tab_func[compteur_func].id = id;
    tab_func[compteur_func].nbarg = 0;
    tab_func[compteur_func].begin_asm = get_asmline();
    compteur_func++;
}

void tab_func_nbarg_add1(){
    tab_func[compteur_func-1].nbarg++;
}

/* return index of func, or -1 not find*/
int find_func(char*id){
    int index;
    for(index=compteur_func-1;index>=0;index--){
        if(strcmp(tab_func[index].id,id)==0){
            break;
        }
    }
    return index;
}

int arithmetical_E2E(int type){
    int index=ebp+compteur_ebp+(compteur_tmp-2);
    int result = 0;
    char *charvalue=malloc(sizeof(char)*2);

    sprintf(charvalue,"%d",(index-ebp+1));
    tab_inst_addline("LOAD","R1","R31",charvalue);
    sprintf(charvalue,"%d",(index-ebp));
    tab_inst_addline("LOAD","R0","R31",charvalue);
    switch (type) {
        case EQEQ:
            tab_inst_addline("EQU","R0","R0","R1");
            break;
        case NEQ:
            // result = EQ - 1, if EQ -> res = 0
            tab_inst_addline("EQU","R0","R1","R0");
            tab_inst_addline("AFC","R1","1","");
            tab_inst_addline("SUB","R0","R1","R0");
            break;
        case ADD:
            tab_inst_addline("ADD","R0","R0","R1");
            break;
        case SUB:
            tab_inst_addline("SUB","R0","R0","R1");
            break;
        case MUL:
            tab_inst_addline("MUL","R0","R0","R1");
            break;
        case DIV:
            tab_inst_addline("DIV","R0","R0","R1");
            break;
        case INF:
        	tab_inst_addline("INF","R0","R0","R1");
            break;
        case SUP:
            tab_inst_addline("SUP","R0","R0","R1");
            break;
        case INFEQ:
            tab_inst_addline("INFE","R0","R0","R1");
            break;
        case SUPEQ:
            tab_inst_addline("SUPE","R0","R0","R1");
            break;
        default:
            return -1;
            break;
     }

    //sprintf(charvalue,"%d",(index-ebp));
    tab_inst_addline("STORE","R31",charvalue,"R0");
    compteur_tmp--;

    free(charvalue);
    return index;
}
