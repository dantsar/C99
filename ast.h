#ifndef __AST_H
#define __AST_H

#include "def.h"

typedef struct astnode* ASTNODE;

ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_and_set_unary(int op, ASTNODE expr);
ASTNODE alloc_and_set_binary(int type, ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_and_set_ternary(ASTNODE cond, ASTNODE true, ASTNODE false);
ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_and_set_ident(char* ident);
ASTNODE alloc_and_set_num(unsigned long long int_num, long double real, int type, int sign);
ASTNODE alloc_and_set_charlit(char charlit);
ASTNODE alloc_and_set_string(char* string, int len);
ASTNODE alloc_and_set_fncall(ASTNODE name, ASTNODE params);
ASTNODE alloc_and_set_sizeof(ASTNODE expr);
ASTNODE alloc_and_set_select(ASTNODE expr, char* ident);

void print_ast(ASTNODE ast);

struct astnode_unary{
    int op;
    ASTNODE expr;
};

struct astnode_binary{
    int op;
    int op_type;
    ASTNODE left;
    ASTNODE right;
};

struct astnode_ternary{
    ASTNODE cond;
    ASTNODE true;
    ASTNODE false;
};

struct astnode_ident{
    char* ident;
};

struct astnode_charlit{
    char charlit;
};

struct astnode_string{
    char* string;
    int len;
};

struct astnode_num{
    int type;
    int sign;
    unsigned long long int_num;
    long double real;
};

struct fncall_params{ /* linked list of params */
    ASTNODE param;
    struct fncall_params* next;
};
struct astnode_fncall{
    ASTNODE name;
    int num_param;
    struct fncall_params* params;
};

struct astnode_sizeof{
    ASTNODE expr;
};

struct astnode_select{
    ASTNODE expr;
    ASTNODE tag;
};

struct astnode{
    int type;
    union{
        struct astnode_unary    unary;
        struct astnode_binary   binary;
        struct astnode_ternary  ternary;
        struct astnode_ident    ident;
        struct astnode_num      num;
        struct astnode_charlit  charlit;
        struct astnode_string   string;
        struct astnode_fncall   fncall;
        struct astnode_sizeof   a_sizeof;
        struct astnode_select   select;
    };
};

#endif