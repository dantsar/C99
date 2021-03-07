#ifndef __AST_H
#define __AST_H

#include "def.h"

typedef struct astnode* ASTNODE;

ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_and_set_ident(char* ident);
ASTNODE alloc_and_set_num(unsigned long long int_num, long double real, int type, int sign);
ASTNODE alloc_and_set_charlit(char charlit);
ASTNODE alloc_and_set_string(char* string, int len);
ASTNODE alloc_and_set_fncall(ASTNODE name, ASTNODE params);

void print_ast(ASTNODE ast);

struct astnode_binop{
    int op;
    ASTNODE left;
    ASTNODE right;
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

// struct astnode_sizeof{
//     struct astnode_binop exp;
// };

// struct astnode_ifstmt{
//     struct astnode_binop;

// };

struct astnode{
    int type;
    union{
        struct astnode_binop    binop;
        struct astnode_ident    ident;
        struct astnode_num      num;
        struct astnode_charlit  charlit;
        struct astnode_string   string;
        struct astnode_fncall   fncall;
        // struct astnode_sizeof   ast_sizeof;
        // struct astnode_ifstmt   ifstmt;
    };
};

#endif