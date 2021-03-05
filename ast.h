#ifndef __AST_H
#define __AST_H

#include "def.h"

typedef struct astnode* ASTNODE;

ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_and_set_ident(const char* ident);

void print_ast(ASTNODE ast);




struct astnode_binop{
    int op;
    ASTNODE left;
    ASTNODE right;
};

struct astnode_ident{
    char* ident;
};

struct astnode_num{
    int numtype;
    int sign;
    unsigned long long int_num;
    long double real;
};

// struct astnode_sizeof{
//     int size;
// };

// struct astnode_fnc{
//     char *name;
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
        // struct astnode_sizeof   ast_sizeof;
        // struct astnode_fnc      fnc;
        // struct astnode_ifstmt   ifstmt;
    };
};

#endif