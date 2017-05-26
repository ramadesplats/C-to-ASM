parser: y.tab.c lex.yy.c 
	gcc y.tab.c lex.yy.c -ll -o asm2op

lex.yy.c: asm2op.l y.tab.h
	lex asm2op.l

y.tab.c: asm2op.y asm2op.l
	yacc -d asm2op.y

clean:
	rm y.tab.c y.tab.h lex.yy.c
	rm asm2op
