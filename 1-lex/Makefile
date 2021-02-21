all: lex.yy.c lex

lex.yy.c: lex.l 
	flex lex.l

lex: lex.yy.c lex_test.c
	gcc lex_test.c -o lex

clean: 
	rm lex.yy.c

remove: 
	rm lex
