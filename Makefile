CFLAGS= -std=gnu99

all: parser

parser.tab.h: parser.y
	bison -vd parser.y

parser.tab.o: parser.tab.h
	gcc $(CFLAGS) -c -o parser.tab.o parser.tab.c

lex.yy.c: lex.l parser.tab.o
	flex lex.l

lex.yy.o: lex.yy.c parser.tab.o
	gcc $(CFLAGS) -c -o lex.yy.o lex.yy.c

lex: lex_print.c lex.yy.c
	gcc $(CFLAGS) -o lex lex_print.c parser.tab.o

ast.o: ast.h ast.c
	gcc $(CFLAGS) -c -o ast.o ast.c

parser: parser.tab.o lex.yy.o ast.o
	gcc $(CFLAGS) -o parser parser.tab.o lex.yy.o ast.o


clean: 
	rm *.o lex.yy.* lex parser.tab.* parser parser.output