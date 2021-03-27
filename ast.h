#ifndef AST_H
#define AST_H

#include "def.h"
#include "sym_tab.h"

/* Abstract Symbol Table node types */
enum AST_TYPE{ 
      AST_UNARY=0, 
      AST_BINARY, 
      AST_TERNARY, 
      AST_IDENT, 
      AST_NUM, 
      AST_SIZEOF, 
      AST_FNCALL, 
      AST_CHARLIT, 
      AST_STRING, 
      AST_SELECT
};
/* enum for binary types in ast */
enum AST_BIN_TYPE{BINOP=0, COMP, ASSIGN};

ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_unary(int op, ASTNODE expr);
ASTNODE alloc_binary(int type, ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_ternary(ASTNODE cond, ASTNODE true, ASTNODE false);
ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_ident(char* ident);
ASTNODE alloc_num(unsigned long long int_num, long double real, int type, int sign);
ASTNODE alloc_charlit(char charlit);
ASTNODE alloc_string(char* string, int len);
ASTNODE alloc_fncall(ASTNODE name, ASTNODE params);
ASTNODE alloc_sizeof(ASTNODE expr);
ASTNODE alloc_select(ASTNODE expr, char* ident);

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

struct astnode_fncall{
    ASTNODE name;
    int num_param;

    struct fncall_params{ /* linked list of params */
        ASTNODE param;
        struct fncall_params* next;
    } *params;
};

struct astnode_sizeof{
    ASTNODE expr;
};

struct astnode_select{
    ASTNODE expr;
    ASTNODE tag;
};

struct astnode_scalar{ 
    char *filename;
    int lineno;

    int sign;
    int type;
    union{
        unsigned long long int_num;
        long double real;
    };
};

struct astnode_pointer{
    ASTNODE ptr_to;
};

struct astnode_array{
    int size;
    ASTNODE ptr_to;
}; 

struct astnode_func{
    char *filename;
    int lineno;

    ASTNODE ret;
    ASTNODE body;
    SYM_TAB proto;
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

        /* assignment 3 */
        struct astnode_scalar   scalar;
        struct astnode_pointer  pointer;
        struct astnode_array    array;
        struct astnode_func     func;
        // struct astnode_st_un   st_un;
    };
};

#endif