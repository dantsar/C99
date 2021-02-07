all: lex


lex.yy.c: lex.l 
	flex $^

lex: lex.yy.c 
	gcc -lfl $^ -o lex

clean: 
	rm *.o 

remove: 
	rm lex
