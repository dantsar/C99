%{
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

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
    struct astnode *astnode_p;
}


%token IDENT CHARLIT STRING NUMBER INDSEL PLUSPLUS MINUSMINUS SHL SHR LTEQ GTEQ 
%token EQEQ NOTEQ LOGAND LOGOR ELLIPSIS TIMESEQ DIVEQ MODEQ PLUSEQ MINUSEQ SHLEQ 
%token SHREQ ANDEQ OREQ XOREQ AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE 
%token ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE INT LONG REGISTER RESTRICT RETURN 
%token SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE 
%token WHILE _BOOL _COMPLEX _IMAGINARY

/* https://en.cppreference.com/w/c/language/operator_precedence */
%left ','
%right '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ
%right '?' ':'
%left LOGOR
%left LOGAND
%left '|'
%left '^'
%left '&'
%left EQEQ NOTEQ
%left '<' LTEQ '>' GTEQ
%left '+' '-'
%left '*' '/' '%'

%type<ident>        IDENT 
%type<num>          NUMBER 
%type<charlit>      CHARLIT
%type<astnode_p>    value binop

%%

statement:        expr ';'              {fprintf(stdout, "parsed an expression\n");}
                | statement expr ';'    {fprintf(stdout, "parsed an expression\n");}
                ;

expr:           binop                   {}
                ;

binop:            binop ',' value       {}
                | binop '=' value       {}
                | binop '+' value       {} 
                | value
                ;

value:            IDENT                 {fprintf(stdout, "Matched: IDENT %s\n", yylval.ident);}
                | NUMBER                {fprintf(stdout, "Matched: NUMBER %d\n", yylval.num.int_num);}
                | CHARLIT               {fprintf(stdout, "Matched: CHARLIT %d\n", yylval.charlit);}
                ;

%% 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s\n", msg);
}

int main(){
    yyparse();
    print_ast();
    return 1;
}

/* 
                | binop '|' value 
                | binop '^' value 
                | binop '&' value 

                | binop '-' value 
                | binop '*' value 
                | binop '/' value 
                | binop '%' value 
                | value ',' value
*/