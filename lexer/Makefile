all: lex

lex.yy.c: lex.l 
	flex $^ 

lex: lex.yy.c lex_print.c
	gcc lex_print.c -o lex

clean: 
	rm lex.yy.c lex

remove: 
	rm lex
