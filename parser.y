%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char*);

%}

%union{
    struct  Str str;
    struct  Num num;
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
    | NUMBER '+' NUMBER
    | NUMBER
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