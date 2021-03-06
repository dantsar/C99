%{
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
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
%type<str>          STRING
%type<astnode_p>    binop value short_assign

%%

statement:        expr ';'              {}
                | statement expr ';'    {}
                ;

expr:           binop                   {print_ast($1);}
                ;

binop:            binop ',' binop       {$$=alloc_and_set_binop($1, ',', $3);}
                | binop '=' binop       {$$=alloc_and_set_binop($1, '=', $3);}
                | binop '+' binop       {$$=alloc_and_set_binop($1, '+', $3);} 
                | binop '-' binop       {$$=alloc_and_set_binop($1, '-', $3);} 
                | binop '*' binop       {$$=alloc_and_set_binop($1, '*', $3);} 
                | binop '|' binop       {$$=alloc_and_set_binop($1, '|', $3);} 
                | binop '^' binop       {$$=alloc_and_set_binop($1, '^', $3);} 
                | binop '&' binop       {$$=alloc_and_set_binop($1, '&', $3);} 
                | binop '%' binop       {$$=alloc_and_set_binop($1, '%', $3);} 
                | binop '/' binop       {$$=alloc_and_set_binop($1, '/', $3);} 
                | '(' binop ')'         {$$=$2;}
                | short_assign          {$$=$1;}
                | value
                ;

    /* TO DO: IMPLEMENT SHIFT LEFT AND RIGHT */
short_assign:     binop PLUSEQ binop    {$$=alloc_and_expand_assignment($1, '+', $3);} 
                | binop MINUSEQ binop   {$$=alloc_and_expand_assignment($1, '-', $3);}     
                | binop TIMESEQ binop   {$$=alloc_and_expand_assignment($1, '*', $3);}     
                | binop DIVEQ binop     {$$=alloc_and_expand_assignment($1, '/', $3);}     
                | binop MODEQ binop     {$$=alloc_and_expand_assignment($1, '%', $3);}     
                | binop SHLEQ binop     {$$=alloc_and_expand_assignment($1, '+', $3);}     
                | binop SHREQ binop     {$$=alloc_and_expand_assignment($1, '+', $3);}     
                | binop ANDEQ binop     {$$=alloc_and_expand_assignment($1, '&', $3);}     
                | binop XOREQ binop     {$$=alloc_and_expand_assignment($1, '^', $3);}     
                ;
                    
value:            IDENT                 {$$=alloc_and_set_ident($1);}
                | NUMBER                {$$=alloc_and_set_num($1.int_num, $1.real, $1.type, $1.sign);}
                | CHARLIT               {$$=alloc_and_set_charlit($1);}
                | STRING                {$$=alloc_and_set_string($1.str, $1.len);}
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
*/