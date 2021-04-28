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
    /* need unsigned variant? */
    /* binary operators */
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_SHR,
    OP_SHL,
    OP_XOR,
    OP_OR,
    OP_AND,
    /* unary operators */
    OP_NOT,
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
    int opcode;

    /* number of source parameters */
    int param_count; 
    ASTNODE res,src1,src2; /* lval, rval, rval */
};
/* linked list of quads */
struct quad_list{
    struct quad_list *next, *elem;
};

struct bblock{
    unsigned int func_count, bblock_count;
    QUAD_L quad_list;

};
/* linked list of basic blocks */
struct bblock_list{
    struct bblock *next, *elem;
};

QUAD alloc_quad(int opcode);
void gen_quads(ASTNODE extern_def);
void quad_declaration(ASTNODE declaration);
void quad_func(ASTNODE func_def);

void quad_binary(ASTNODE node);
ASTNODE gen_rvalue(ASTNODE node, ASTNODE target);
ASTNODE gen_lvalue(ASTNODE node, int* mode);

void emit_quad(int opcode, ASTNODE left, ASTNODE right, ASTNODE target);

BBLOCK alloc_bblock();
void bblock_append_quad(QUAD emit_quad);

void print_opcode(int opcode);
void print_src_param(ASTNODE src_param);
void print_quad(QUAD quad);
