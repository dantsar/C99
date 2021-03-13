CFLAGS= -std=gnu99

all: parser

char_util.o: char_util.c char_util.h
	gcc -c -o char_util.o char_util.c

parser.tab.h: parser.y def.h
	bison -vd parser.y

parser.tab.o: parser.tab.h
	gcc $(CFLAGS) -c -o parser.tab.o parser.tab.c

lex.yy.c: lex.l parser.tab.o
	flex lex.l

lex.yy.o: lex.yy.c 
	gcc $(CFLAGS) -c -o lex.yy.o lex.yy.c

lex: lex_print.c lex.yy.o char_util.o   ast.o sym_tab.o
	gcc $(CFLAGS) -DLEXER -c -o parser.tab.o parser.tab.c
	gcc $(CFLAGS) -o lex  $^ parser.tab.o



ast.o: ast.h ast.c
	gcc $(CFLAGS) -c -o ast.o ast.c

sym_tab.o: sym_tab.c sym_tab.h
	gcc $(CFLAGS) -c -o sym_tab.o sym_tab.c

parser: parser.tab.o lex.yy.o ast.o sym_tab.o char_util.o
	gcc $(CFLAGS) -o parser $^



clean: 
	rm *.o lex.yy.* lex parser.tab.* parser parser.output