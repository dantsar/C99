#include "ast.h"
#include "def.h"
#include "sym_tab.h"

enum OP_CODES{
    OP_LOAD,
    OP_STORE,
    OP_CMP,
    OP_CALL,
    OP_BR,
    OP_BREQ,
    OP_BRNEQ,
    OP_BRLT,
    OP_BRGT,
    /* need unsigned variant */
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

enum ADDRESSING_MODES{ MODE_DIRECT, MODE_INDIRECT };

/* doubly linked list in quads or in bblock?? */
struct quad{
    /* doubly linked list of quads */
    struct quad *next, *prev;

    int opcode;
    /* ASTNODE or seperate thing */
    ASTNODE res,src1,src2; /* lval, rval, rval */
};
/* linked list of quads */
struct quad_list{
    struct quad *next, *me;
};

union generic_node{
    /* type/width of the node */
    int type;  
    ASTNODE ast;
    /* BLAH */
};

struct bblock{
    unsigned int func_count, bblock_count;

};
/* linked list of basic blocks */
struct bblock_list{
    struct bblock *next, *me;
};

QUAD alloc_quad(int opcode);
void gen_quads(ASTNODE extern_def);
QUAD quad_declaration(ASTNODE declaration);
QUAD quad_func(ASTNODE func_def);

void quad_binary(ASTNODE node);
ASTNODE gen_rvalue(ASTNODE node, ASTNODE target);
