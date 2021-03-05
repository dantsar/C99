%{
#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

extern int yylex();
void yyerror(const char*);

%}

%union {
    /* for single character tokens */
    int c; 

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
%left<c>    ','
%right<c>   '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ
%right<c>   '?' ':'
%left<c>    LOGOR
%left<c>    LOGAND
%left<c>    '|'
%left<c>    '^'
%left<c>    '&'
%left<c>    EQEQ NOTEQ
%left<c>    '<' LTEQ '>' GTEQ
%left<c>    '+' '-'
%left<c>    '*' '/' '%'

%type<ident>        IDENT 
%type<num>          NUMBER 
%type<charlit>      CHARLIT
%type<astnode_p>    binop value 

%%

statement:        expr ';'              {}
                | statement expr ';'    {}
                ;

expr:           binop                   {print_ast($1);}
                ;

binop:            binop ',' binop       {}
                | binop '=' binop       {$$=alloc_and_set_binop($1, '=', $3);}
                | binop '+' binop       {$$=alloc_and_set_binop($1, '+', $3);} 
                | value
                ;

value:            IDENT                 {$$=alloc_and_set_ident($1);}
                | NUMBER                {}
                | CHARLIT               {/* $$=astnode_alloc(AST_CHARLIT); $$=CHARLIT; */}
                ;

%% 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s\n", msg);
}

int main(){
    yyparse();
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