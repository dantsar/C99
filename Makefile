all: lex

lex.yy.c: ./lexer/lex.l 
	flex $^ 

lex: lex.yy.c ./lexer/lex_print.c
	gcc ./lexer/lex_print.c -o lex

clean: 
	rm lex.yy.c lex

remove: 
	rm lex
