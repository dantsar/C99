%{
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "sym_tab.h"
#include "ast.h"



/* stuff from lex */
extern int yylex();
extern char filename[256];
extern int lineno;

/* stuff for symbol table */
SYM_TAB curr_scope;

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
%right<c>   '=' PLUSEQ MINUSEQ TIMESEQ DIVEQ MODEQ SHLEQ SHREQ ANDEQ XOREQ OREQ
%right<c>   '?' ':'
%left<c>    LOGOR
%left<c>    LOGAND
%left<c>    '|'
%left<c>    '^'
%left<c>    '&'
%left<c>    EQEQ NOTEQ
%left<c>    '<' LTEQ '>' GTEQ
%left<c>    SHR SHL
%left<c>    '+' '-'
%left<c>    '*' '/' '%'
%left<c>    '~' '!'
%left<c>     PLUSPLUS MINUSMINUS '(' ')' '.' '[' ']' INDSEL

%type<ident>        IDENT 
%type<num>          NUMBER 
%type<charlit>      CHARLIT
%type<str>          STRING
%type<astnode_p>    expr assign_expr unary_expr cond_expr arith_expr cast_expr postfix_expr prim_expr

%%

statement:        expr ';'                                  {print_ast($1); putchar('\n'); sym_create();}
                | statement expr ';'                        {print_ast($2); putchar('\n');}
                ;

expr:             assign_expr                               {$$=$1;}
                | expr ',' assign_expr                      {$$=alloc_binary(BINOP, $1, ',', $3);}
                ;

assign_expr:      unary_expr '=' assign_expr                {$$=alloc_binary(ASSIGN, $1, '=', $3);} 
                | unary_expr PLUSEQ assign_expr             {$$=alloc_and_expand_assignment($1, '+', $3);} 
                | unary_expr MINUSEQ assign_expr            {$$=alloc_and_expand_assignment($1, '-', $3);}     
                | unary_expr TIMESEQ assign_expr            {$$=alloc_and_expand_assignment($1, '*', $3);}     
                | unary_expr DIVEQ assign_expr              {$$=alloc_and_expand_assignment($1, '/', $3);}     
                | unary_expr MODEQ assign_expr              {$$=alloc_and_expand_assignment($1, '%', $3);}     
                | unary_expr SHLEQ assign_expr              {$$=alloc_and_expand_assignment($1, SHL, $3);}     
                | unary_expr SHREQ assign_expr              {$$=alloc_and_expand_assignment($1, SHR, $3);}     
                | unary_expr ANDEQ assign_expr              {$$=alloc_and_expand_assignment($1, '&', $3);}     
                | unary_expr XOREQ assign_expr              {$$=alloc_and_expand_assignment($1, '^', $3);}     
                | unary_expr OREQ assign_expr               {$$=alloc_and_expand_assignment($1, '|', $3);}     
                | cond_expr                                 {$$=$1;}
                ;

unary_expr:       postfix_expr                              {$$=$1;}
                | PLUSPLUS unary_expr                       {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                $$=alloc_and_expand_assignment($2, '+', temp);}
                | MINUSMINUS unary_expr                     {ASTNODE temp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                                                                $$=alloc_and_expand_assignment($2, '-', temp);}
                | SIZEOF unary_expr                         {$$=alloc_sizeof($2);}
                | SIZEOF '(' unary_expr ')'                 {$$=alloc_sizeof($3);}
                | '&' cast_expr                             {$$=alloc_unary('&',$2);}
                | '*' cast_expr                             {$$=alloc_unary('*',$2);}
                | '+' cast_expr                             {$$=alloc_unary('+',$2);}
                | '-' cast_expr                             {$$=alloc_unary('-',$2);}
                | '~' cast_expr                             {$$=alloc_unary('~',$2);}
                | '!' cast_expr                             {$$=alloc_unary('!',$2);}
                ;

cond_expr:        arith_expr                                {$$=$1;}
                | arith_expr '?' expr ':' cond_expr         {$$=alloc_ternary($1, $3, $5);}
                ;

arith_expr:       arith_expr '+' arith_expr                 {$$=alloc_binary(BINOP,$1, '+', $3);} 
                | arith_expr '-' arith_expr                 {$$=alloc_binary(BINOP,$1, '-', $3);} 
                | arith_expr '*' arith_expr                 {$$=alloc_binary(BINOP,$1, '*', $3);} 
                | arith_expr '|' arith_expr                 {$$=alloc_binary(BINOP,$1, '|', $3);} 
                | arith_expr '^' arith_expr                 {$$=alloc_binary(BINOP,$1, '^', $3);} 
                | arith_expr '&' arith_expr                 {$$=alloc_binary(BINOP,$1, '&', $3);} 
                | arith_expr '%' arith_expr                 {$$=alloc_binary(BINOP,$1, '%', $3);} 
                | arith_expr '/' arith_expr                 {$$=alloc_binary(BINOP,$1, '/', $3);} 
                | arith_expr SHR arith_expr                 {$$=alloc_binary(BINOP,$1, SHR, $3);} 
                | arith_expr SHL arith_expr                 {$$=alloc_binary(BINOP,$1, SHL, $3);} 
                | arith_expr '<' arith_expr                 {$$=alloc_binary(BINOP,$1, '<', $3);}
                | arith_expr '>' arith_expr                 {$$=alloc_binary(BINOP,$1, '>', $3);}
                | arith_expr LTEQ arith_expr                {$$=alloc_binary(BINOP,$1, LTEQ, $3);}
                | arith_expr GTEQ arith_expr                {$$=alloc_binary(BINOP,$1, GTEQ, $3);}
                | arith_expr EQEQ arith_expr                {$$=alloc_binary(BINOP,$1, EQEQ, $3);}
                | arith_expr NOTEQ arith_expr               {$$=alloc_binary(BINOP,$1, NOTEQ, $3);}
                | arith_expr LOGAND arith_expr              {$$=alloc_binary(BINOP,$1, LOGAND, $3);}
                | arith_expr LOGOR arith_expr               {$$=alloc_binary(BINOP,$1, LOGOR, $3);}
                | arith_expr PLUSPLUS                       {$$=alloc_unary(PLUSPLUS,$1);} 
                | arith_expr MINUSMINUS                     {$$=alloc_unary(MINUSMINUS,$1);} 
                | arith_expr '(' ')'                        {$$=alloc_fncall($1, NULL);}
                | arith_expr '(' expr ')'                   {$$=alloc_fncall($1, $3);}
                | '(' arith_expr ')'                        {$$=$2;}
                | cast_expr                                 {$$=$1;}
                ;

/*blank for now */
cast_expr:        unary_expr                                {$$=$1;}
                ;

postfix_expr:     prim_expr                                 {$$=$1;}
                | postfix_expr '[' expr ']'                 {$$=alloc_binary(BINOP, $1, '+', $3);
                                                                $$=alloc_unary('*', $$);}
                | postfix_expr '.' IDENT                    {$$=alloc_select($1, $3);}
                | postfix_expr INDSEL IDENT                 {$$=alloc_unary('*', $1);
                                                                $$=alloc_select($$, $3);}
                // | '(' type_name ')' '{' init_list '}'       {/* shtuff */}
                // | '(' type_name ')' '{' init_list ',' '}'   {/* shtuff */}
                ;
                    
prim_expr:        IDENT                         {$$=alloc_ident($1);}
                | NUMBER                        {$$=alloc_num($1.int_num, $1.real, $1.type, $1.sign);}
                | CHARLIT                       {$$=alloc_charlit($1);}
                | STRING                        {$$=alloc_string($1.str, $1.len);}
                ;
%% 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s:%d %s\n", filename, lineno, msg);
}

#ifndef LEXER

int main(){
    yyparse();
    return 1;
}

#endif