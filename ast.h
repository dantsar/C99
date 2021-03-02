#ifndef __AST_H
#define __AST_H

typedef struct astnode* ASTNODE;

ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2);
void print_ast();

/* Abstract Symbol Table node types */
enum {AST_BINOP=0, AST_IDENT, AST_NUM, AST_SIZEOF, AST_FCN, AST_UNOP};

struct astnode_binop{
    int op;
    struct astnode *left;
    struct astnode *right;
};

struct astnode_ident{
    char* ident;
};

struct astnode_num{
    int numtype;
    unsigned long long value;
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
    }n;
};

struct ast{
    int n;
};

#endif