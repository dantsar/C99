%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"

extern int yylex();
void yyerror(const char*);

%}

%union {
    struct Str{
        char *str;
        int len;
    }str;

    struct Num{
        unsigned long long int_num;
        long double real;
        int type;
        int sign;
    }num;

    char*   ident;
    char    charlit;
}


%token IDENT CHARLIT STRING NUMBER INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ 
%token EQEQ NOTEQ LOGAND LOGOR ELLIPSIS TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ 
%token SHREQ ANDEQ OREQ XOREQ AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE 
%token ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN 
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE 
%token WHILE _BOOL _COMPLEX _IMAGINARY

%%

expr: '(' expr ')'
    | expr '+' expr 
    | NUMBER
    | IDENT
    ;

%% 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s\n", msg);
}


int main(){

    fprintf(stdout, "parser.y main\n");
    yyparse();

    return 1;
}