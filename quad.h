#include "ast.h"

enum OP_CODES{
    OP_LOAD,
    OP_STORE,
    OP_CMP,
    OP_CALL,
    OP_BR,
    /* also need to do unsigned varient */
    OP_BREQ,
    OP_BRNEQ,
    OP_BRLT,
    OP_BRGT,
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_SHR,
    OP_SHL,
    OP_NOT,
    OP_XOR,
    OP_OR,
    OP_AND,
    /* add more */
};

enum GEN_NODE_TYPE{
    GEN_AST, 
    GEN_CONST,
    GEN_QUAD
};

struct quad{
    /* doubly linked list of quads */
    struct quad *next, *prev;

    int opcode;
    union generic_node *res,*src1, *src2;
};

union generic_node{
    int type;
    ASTNODE ast;
    /* BLAH */
};

struct bblock{
    unsigned int func_count, bblock_count;

};
