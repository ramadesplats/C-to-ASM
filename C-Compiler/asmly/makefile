parser: y.tab.c lex.yy.c asmfonctions.c asmfonctions.h
	gcc y.tab.c lex.yy.c asmfonctions.c -ll -o interpreteur

lex.yy.c: asm.l y.tab.h
	lex asm.l

y.tab.c: asm.y asm.l
	yacc -d asm.y

clean:
	rm y.tab.c y.tab.h lex.yy.c
	rm interpreteur
