all: lex parser

lex.yy.c: lex.l 
	flex $^ 

lex: lex.yy.c lex_print.c
	gcc lex_print.c -o lex

parser.tab.c: parser.y
	bison parser.y

parser: parser.tab.c
	gcc parser.tab.c -o parser


clean: 
	rm lex.yy.c lex parser.tab.c parser
