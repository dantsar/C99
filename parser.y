%{
#include <stdio.h>
#include <stdlib.h>

#include "def.h"
#include "sym_tab.h"
#include "ast.h"
#include "parser.tab.h"

/* stuff from lex */
extern int yylex();
extern char filename[256];
extern int lineno;

/* stuff for symbol table */
SYM_TAB curr_scope;

/* global variable for distinguishing between block and function scopes */
bool in_func = false;

void yyerror(const char*);
void yyerror_die(const char *);

%}

%union {
    /* for single character tokens */
    int c; 

    /* definition in def.h */
    struct Str str;
    struct Num num;

    char*  ident;
    char   charlit;
    struct astnode *astnode_p; /* definition in ast.h */
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

%left IF
%left ELSE

/* values */
%type<ident>        IDENT 
%type<num>          NUMBER 
%type<charlit>      CHARLIT
%type<str>          STRING
// %type<astnode_p>    constant

/* expressions */
%type<astnode_p>    expr
%type<astnode_p>    const_expr 
%type<astnode_p>    assign_expr unary_expr cond_expr arith_expr cast_expr postfix_expr prim_expr //func_call

/* declarations */
%type<astnode_p>    declaration declaration_list declaration_specs init_decl_list decl 
%type<astnode_p>    direct_decl init_decl pointer param_type_list param_list param_declaration 
%type<astnode_p>    ident_list stg_class_spec type_spec declaration_spec func_spec type_qualif
%type<astnode_p>    struct_union_spec struct_union struct_declaration_list struct_declaration 
%type<astnode_p>    specific_qualif_list struct_decl_list struct_decl

/* statements */
%type<astnode_p>    block_item block_item_list statement expr_stmnt label_stmnt compound_stmnt 
%type<astnode_p>    select_stmnt iterat_stmnt jump_stmnt expr_opt 

/* External Definitions */
%type<astnode_p>    translation_unit extern_declaration func_def

%%
/* (6.9) */
translation_unit:     extern_declaration                                {print_sym(curr_scope);} 
                    | translation_unit extern_declaration               {print_sym(curr_scope);}
                    ;
/* (6.9) */
extern_declaration:   declaration                                       {sym_declaration($1, curr_scope);}
                    | func_def                                          {sym_func_def($1, curr_scope);}
                                                                                     
                    ;
/* (6.5.1) */
prim_expr:            IDENT                         {$$=alloc_ident($1);}
                    | NUMBER                        {$$=alloc_num($1.int_num, $1.real, $1.type, $1.sign);}
                    | CHARLIT                       {$$=alloc_charlit($1);}
                    | STRING                        {$$=alloc_string($1.str, $1.len);}
                    ;
/* (6.5.2) */
postfix_expr:         prim_expr                                 {$$=$1;}
                    | postfix_expr '[' expr ']'                 {$$=alloc_binary(BINOP, $1, '+', $3);
                                                                    $$=alloc_unary('*', $$);}
                    | postfix_expr '.' IDENT                    {$$=alloc_select($1, $3);}
                    | postfix_expr INDSEL IDENT                 {$$=alloc_unary('*', $1);
                                                                    $$=alloc_select($$, $3);}
                    | postfix_expr '(' ')'                      {$$=alloc_fncall($1, NULL);}
                    | postfix_expr '(' expr ')'                 {$$=alloc_fncall($1, $3);}
                    // | '(' type_name ')' '{' init_list '}'       {/* shtuff */}
                    // | '(' type_name ')' '{' init_list ',' '}'   {/* shtuff */}
                    ;
// constant:             NUMBER                        {$$=alloc_num($1.int_num, $1.real, $1.type, $1.sign);}
//                     | CHARLIT                       {$$=alloc_charlit($1);}
//                     ; 
// /* (6.5.16) */
assign_expr:          unary_expr '=' assign_expr                {$$=alloc_binary(ASSIGN, $1, '=', $3);} 
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
/* (6.5.3) */
unary_expr:           postfix_expr                              {$$=$1;}
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
/* (6.5.15) */
cond_expr:            arith_expr                                {$$=$1;}
                    | arith_expr '?' expr ':' cond_expr         {$$=alloc_ternary($1, $3, $5);}
                    ;
/* (6.5.17) */
expr:                 assign_expr                               {$$=$1;}
                    | expr ',' assign_expr                      {$$=alloc_binary(BINOP, $1, ',', $3);}
                    ;
/* (6.6) */
const_expr:           cond_expr                                 {$$=$1;}
                    ;
/* (6.5.5 - 6.5.16) */
arith_expr:           arith_expr '+' arith_expr                 {$$=alloc_binary(BINOP,$1, '+', $3);} 
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
                    | '(' arith_expr ')'                        {$$=$2;}
                    | cast_expr                                 {$$=$1;}
                    ;
/*blank for now */
cast_expr:            unary_expr                                {$$=$1;}
                    ;
/* (6.7) */
declaration:          declaration_specs ';'                         {$$=alloc_declaration($1, NULL);}
                    | declaration_specs init_decl_list ';'          {$$=alloc_declaration($1, $2);}
                    ;   
/* (6.7) */
/* slight deviation from the c standard, but this is to avoid shit reduce conflicts */
declaration_specs:    declaration_spec                          {$$=alloc_list($1);}
                    | declaration_specs declaration_spec        {$$=list_append_elem($2, $1);}
                    ;
/* (6.7) */
declaration_spec:     stg_class_spec                            {$$=$1;}
                    | type_spec                                 {$$=$1;}
                    | type_qualif                               {$$=$1;} /* going to be ignored */
                    | func_spec                                 {$$=$1;}
                    ;
/* (6.7) */
init_decl_list:       init_decl                                          {$$=alloc_list($1);}
                    | init_decl_list ',' init_decl                       {$$=$1; list_append_elem($3, $1);}
                    ;
/* (6.7) */
init_decl:            decl                                      {$$=$1;}            
                    // | decl '=' init /* not handling initializers ... */ {}
                    ;
/* (6.7.1) */
stg_class_spec:       AUTO                                      {$$=alloc_decl_spec(STG_AUTO, AST_DECL_STG);    }
                    | STATIC                                    {$$=alloc_decl_spec(STG_STATIC, AST_DECL_STG);  }
                    | EXTERN                                    {$$=alloc_decl_spec(STG_EXTERN, AST_DECL_STG);  } 
                    | TYPEDEF                                   {$$=alloc_decl_spec(STG_TYPEDEF, AST_DECL_STG); }
                    | REGISTER                                  {$$=alloc_decl_spec(STG_REGISTER, AST_DECL_STG);}
                    ;
/* (6.7.2) */
type_spec:            VOID                                          {$$=alloc_decl_spec(TYPE_VOID, AST_DECL_TYPE_SPEC);    } 
                    | CHAR                                          {$$=alloc_decl_spec(TYPE_CHAR, AST_DECL_TYPE_SPEC);    } 
                    | SHORT                                         {$$=alloc_decl_spec(TYPE_SHORT, AST_DECL_TYPE_SPEC);   }  
                    | INT                                           {$$=alloc_decl_spec(TYPE_INT, AST_DECL_TYPE_SPEC);     } 
                    | LONG                                          {$$=alloc_decl_spec(TYPE_LONG, AST_DECL_TYPE_SPEC);    } 
                    | FLOAT                                         {$$=alloc_decl_spec(TYPE_FLOAT, AST_DECL_TYPE_SPEC);   }  
                    | DOUBLE                                        {$$=alloc_decl_spec(TYPE_DOUBLE, AST_DECL_TYPE_SPEC);  }    
                    | SIGNED                                        {$$=alloc_decl_spec(TYPE_SIGNED, AST_DECL_TYPE_SPEC);  }    
                    | UNSIGNED                                      {$$=alloc_decl_spec(TYPE_UNSIGNED, AST_DECL_TYPE_SPEC);}      
                    | _BOOL                                         {$$=alloc_decl_spec(TYPE__BOOL, AST_DECL_TYPE_SPEC);   }  
                    | _COMPLEX                                      {$$=alloc_decl_spec(TYPE__COMPLEX, AST_DECL_TYPE_SPEC);}      
                    | struct_union_spec                             {$$=$1;}
                    // | enum_spec    /* nope!. */
                    // | typedef_name /* heck nope! */
                    ; 
/* (6.7.2.1) */
struct_union_spec:    struct_union '{' struct_declaration_list '}'              {$$=$1; sym_struct_define($1, $3);}
                    | struct_union IDENT '{' struct_declaration_list '}'        {$$=$1; 
                                                                                 sym_struct_define($1, $4);
                                                                                 sym_struct_declare($2, $1, curr_scope);
                                                                                } 
                    | struct_union IDENT                                        { /* either a forward declartion or getting the type (I will be ignoring/not handling forward declarations) */
                                                                                  SYM_ENT temp = alloc_sym_ent($2, ENT_SU_TAG, NS_SU);
                                                                                  $$ = (temp = sym_lookup(curr_scope, temp)) ? temp->su_tag.st_un : $1;
                                                                                } 
                    ;
/* (6.7.2.1) */
struct_union:         STRUCT    {$$=alloc_st_un(AST_STRUCT, curr_scope->scope_type);}
                    | UNION     {$$=alloc_st_un(AST_UNION, curr_scope->scope_type);}
                    ;
/* (6.7.2.1) */
struct_declaration_list:      struct_declaration                            {$$=alloc_list($1);}
                            | struct_declaration_list struct_declaration    {$$=list_append_elem($2, $1);}
                            ;
/* (6.7.2.1) */
struct_declaration:   specific_qualif_list struct_decl_list ';'         {$$=alloc_declaration($1, $2);}
                    ;
/* (6.7.2.1) */
specific_qualif_list:     type_spec                         {$$=alloc_list($1);}
                        | specific_qualif_list type_spec    {$$=list_append_elem($2, $1);}
                        | type_qualif                       {$$=alloc_list($1);}
                        | specific_qualif_list type_qualif  {$$=list_append_elem($2, $1);}
                        ;
/* (6.7.2.1) */
struct_decl_list:     struct_decl                               {$$=alloc_list($1);}
                    | struct_decl_list ',' struct_decl          {$$=list_append_elem($3, $1);}
                    ;
/* (6.7.2.1) */
struct_decl:          decl                          {$$=$1;}
                    // | ':' const_expr                {$$=$2;} /* not implementing bit fields */
                    // | decl ':' const_expr           {$$=$1;} /* no bitfields for you */
                    ;
/* (6.7.3) */
/* not handling type qualifiers and inline func specifier, but still supporing it in grammar */
type_qualif:          CONST                                     {$$=alloc_decl_spec(QUALIF_CONST, AST_DECL_TYPE_QUALIF);}
                    | RESTRICT                                  {$$=alloc_decl_spec(QUALIF_RESTRICT, AST_DECL_TYPE_QUALIF);}
                    | VOLATILE                                  {$$=alloc_decl_spec(QUALIF_VOLATILE, AST_DECL_TYPE_QUALIF);}
                    ;
/* (6.7.4) */
func_spec:            INLINE                                    {$$=alloc_decl_spec(FUNC_INLINE, AST_DECL_FUNC_SPEC);}       
                    ;
/* (6.7.5) */
decl:                 direct_decl                                   {$$=$1;}
                    | pointer direct_decl                           {$$=list_append($1, $2);}
                    ;
/* (6.7.5) */
direct_decl:          IDENT                                         {$$=alloc_list(alloc_ident($1));} //{$$=alloc_list(alloc_ident($1));}
                    | '(' decl ')'                                  {$$=$2;}
                    | direct_decl '[' assign_expr ']'                  {$$=list_append_elem(alloc_array(NULL,$3), $1);}
                    | direct_decl '[' ']'                           {yyerror_die("not supporting variable length arrays");}

                    | direct_decl '(' param_type_list ')'           { /* replace the first element(IDENT) with a ast_func */
                                                                     $$=alloc_list(alloc_func($1->list.elem, $3));
                                                                     $$->list.next = $1->list.next;
                                                                     free($1); /* SOME semblance of memory managment :^) */
                                                                    }
                    | direct_decl '(' ')'                           {$$=alloc_list(alloc_func($1->list.elem, NULL));
                                                                     $$->list.next = $1->list.next;
                                                                     free($1); /* SOME semblance of memory managment :^) */
                                                                    }
                    | direct_decl '(' ident_list ')'                {yyerror_die("Not supporting old c style function definitons :'(");}/* func */
                    ;
/* (6.7.5) */
/* ignoring type qualifieres, but support in grammar */
pointer:              '*'                                           {$$=alloc_list(alloc_ptr(NULL));} 
                    | '*' pointer                                   {$$=list_append_elem(alloc_ptr(NULL), $2);} 
                    | '*' type_qualif_list                          {$$=alloc_list(alloc_ptr(NULL));}  
                    | '*' type_qualif_list pointer                  {$$=list_append_elem(alloc_ptr(NULL), $3);}
                    ;
/* (6.7.5) */
type_qualif_list:     type_qualif                               
                    | type_qualif_list type_qualif              
                    ;
/* (6.7.5) */
param_type_list:      param_list                                {$$=$1;}
                    | param_list ',' ELLIPSIS                   {$$=$1;} /* I will handle this later...maybe... */
                    ;
/* (6.7.5) */
param_list:           param_declaration                         {$$=alloc_list($1);}
                    | param_list ',' param_declaration          {$$=list_append_elem($3, $1);}
                    ;

/* (6.7.5) */
param_declaration:    declaration_specs decl                    {$$=alloc_declaration($1, $2);}
                    | declaration_specs                         {$$=list_last($1); /* KLUDGE!!! -_- there is a bug! can you see it?? */
                                                                 if($$->list.elem->type == AST_DECL_SPEC){
                                                                     if($$->list.elem->decl_spec.decl_spec == TYPE_VOID)
                                                                        $$=alloc_declaration($1, NULL);
                                                                 }else{ 
                                                                     yyerror_die("incomplete function definition"); 
                                                                 }
                                                                } 
                    ;
/* (6.7.5) */
ident_list:           IDENT                         {$$=alloc_list(alloc_ident($1));}
                    | ident_list ',' IDENT          {$$=list_append_elem(alloc_ident($3), $1);} 
                    ;
/* (6.8) */
/* statements... to be worked on later */
statement:            expr_stmnt                                {$$=$1;}
                    | label_stmnt                               {$$=$1;}
                    | compound_stmnt                            {$$=$1;}
                    | select_stmnt                              {$$=$1;}
                    | iterat_stmnt                              {$$=$1;}
                    | jump_stmnt                                {$$=$1;}
                    ;
/* (6.8.1) */
label_stmnt:          IDENT ':' statement                       {$$=alloc_label_stmnt(AST_LABEL, $3, $1, NULL);}
                    | CASE const_expr ':' statement             {$$=alloc_label_stmnt(AST_LABEL_CASE, $4, NULL, $2);}
                    | DEFAULT ':' statement                     {$$=alloc_label_stmnt(AST_LABEL_DEFAULT, $3, NULL, NULL);}
                    ;
/* (6.8.2) */
compound_stmnt:       '{' '}'                   {$$=alloc_compound(NULL, NULL);}
                    | '{' {curr_scope=sym_tab_push(SCOPE_BLOCK, curr_scope);} block_item_list  '}'   {$$=alloc_compound($3, curr_scope); curr_scope=sym_tab_pop(curr_scope);}
                    ;
/* (6.8.2) */
block_item_list:      block_item                    {$$=alloc_list($1);}
                    | block_item_list block_item    {$$=list_append_elem($2, $1);}
                    ;
/* (6.8.2) */
block_item:           declaration                   {$$=$1; sym_declaration($1, curr_scope);}
                    | statement                     {$$=$1;}
                    ;
/* (6.8.3) */
expr_stmnt:           expr ';'                                  {$$=$1;}
                    ;
/* (6.8.4) */
select_stmnt:         IF '(' expr ')' statement                 {$$=alloc_select_stmnt(AST_IF_STMNT, $3, $5, NULL);} 
                    | IF '(' expr ')' statement ELSE statement  {$$=alloc_select_stmnt(AST_IF_STMNT, $3, $5, $7);}         
                    | SWITCH '(' expr ')' statement             {$$=alloc_select_stmnt(AST_SWITCH_STMNT, $3, $5, NULL);}     
                    ;
/* (6.8.5) */
iterat_stmnt:         WHILE '(' expr ')' statement                             {$$=alloc_iterat_stmnt(AST_WHILE_STMNT, $3, $5, NULL, NULL);} 
                    | DO statement WHILE '(' expr ')'  ';'                     {$$=alloc_iterat_stmnt(AST_DO_STMNT, $5, $2, NULL, NULL);}         
                    | FOR '(' {curr_scope=sym_tab_push(SCOPE_BLOCK, curr_scope);} expr_opt ';' expr_opt ';' expr_opt ')' statement {$$=alloc_iterat_stmnt(AST_FOR_STMNT, $6, $10, $4, $8); curr_scope=sym_tab_pop(curr_scope);}                             
                    // | FOR '(' declaration expr_opt ';' expr_opt ')' statement  {}                             
                    ;
expr_opt:             expr            {$$=$1;}
                    | /* empty */       {$$=NULL;}
                    ;
/* (6.8.5) */
jump_stmnt:           GOTO IDENT ';'                        {$$=alloc_jump_stmnt(AST_GOTO, $2, NULL);}         
                    | CONTINUE ';'                          {$$=alloc_jump_stmnt(AST_CONTINUE, NULL, NULL);}      
                    | BREAK ';'                             {$$=alloc_jump_stmnt(AST_BREAK, NULL, NULL);}  
                    | RETURN expr_opt ';'                   {$$=alloc_jump_stmnt(AST_RETURN, NULL, $2);}              
                    ;
/* (6.9.1) */
/* manually change compound scope from block to func */
func_def:              declaration_specs decl compound_stmnt                     { /* populate astnode with elements */
                                                                                    $$=$2->list.elem; /* first element is astnode_func */
                                                                                    $$->func.ret = list_append($1, $2);
                                                                                    $$->func.ret = $$->func.ret->list.next;
                                                                                    $$->func.block = $3;
                                                                                    $$->func.block->comp.tab->scope_type = SCOPE_FUNC;
                                                                                    free($2);
                                                                                }
                    | declaration_specs decl declaration_list compound_stmnt    {yyerror_die("not handling old c style function definitions :'(");}
                    ;
/* (6.9.1) */
declaration_list:     declaration
                    | declaration_list declaration
                    ;
%% 

void yyerror(const char *msg){
    fprintf(stderr, "Error: %s:%d %s\n", filename, lineno, msg);
}
void yyerror_die(const char *msg){
    yyerror(msg);
    exit(-1);
}

int main(){
    /* creating global symbol table */
    curr_scope = sym_tab_create(SCOPE_GLOBAL);

    yyparse();
    return 1;
}