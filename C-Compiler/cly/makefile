parser: y.tab.c lex.yy.c fonctions.c fonctions.h
	gcc y.tab.c lex.yy.c fonctions.c -ll -o parser

y.tab.c: compilateur.y
	yacc -d compilateur.y

lex.yy.c: compilateur.l y.tab.h
	lex compilateur.l

clean:
	rm y.tab.c y.tab.h lex.yy.c
	rm parser
