all: lex 

parser.tab.h: parser.y
	bison -vd parser.y

parser.tab.o: parser.tab.h 
	gcc -c -o parser.tab.o parser.tab.c

lex.yy.c: lex.l parser.tab.o
	flex lex.l

lex.yy.o: lex.yy.c parser.tab.o
	gcc -c -o lex.yy.o lex.yy.c parser.tab.o

lex: lex_print.c lex.yy.c
	gcc -o lex lex_print.c parser.tab.o

parser.tab.c: parser.y
	bison parser.y

parser: parser.tab.o lex.yy.o
	gcc -o parser parser.tab.o lex.yy.o


clean: 
	rm *.o lex.yy.* lex parser.tab.* parser parser.output
