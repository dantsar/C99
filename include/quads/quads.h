#ifndef QUADS_H
#define QUADS_H

#include <parser/ast.h>
#include <common/def.h>
#include <parser/sym_tab.h>

enum OP_CODES{
    OP_LOAD,
    OP_STORE,
    OP_LEA,

    OP_MOV,

    /* BRANCHING */
    OP_CMP,
    OP_BR,
    OP_BRE,
    OP_BRNE,
    OP_BRL, 
    OP_BRLE,
    OP_BRG, 
    OP_BRGE,

    OP_PUSH,
    OP_CALL,

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

    OP_RET,
};

enum GEN_NODE_TYPE{ GEN_VAR, GEN_TEMP, GEN_CONST, GEN_STRING };
enum ADDRESSING_MODES{ MODE_DIRECT, MODE_INDIRECT };
enum COND_CODE{CC_ALWAYS, CC_UNKNOWN = 0, CC_E, CC_NE, CC_L, CC_LE, CC_G, CC_GE};

/* doubly linked list in quads or in bblock?? */
struct quad{
    int opcode;
    int cond_flag; /* enum COND_CODE: for comparisons */

    ASTNODE res,src1,src2; /* lval, rval, rval */
};
/* linked list of quads */
struct quad_list{
    struct quad* elem;
    struct quad_list* next;
};

struct bblock{
    unsigned int bblock_count;
    char* func_name;
    char* name;

    bool is_done;
    BBLOCK cond, def;   /* conditional and default branches */
    int cond_flag;      /* flag for conditional branch */

    struct quad_list* quads;
};
/* linked list of basic blocks */
struct bblock_list{
    struct bblock *elem;
    struct bblock_list* next;
};

struct loop{
    BBLOCK bb_cont, bb_break;
    LOOP prev; /* for loops in loops */
};

// QUAD    alloc_quad(int opcode);
BBLOCK_L gen_quads(ASTNODE extern_def);
void     quad_statement(ASTNODE stmnt);

/* expression generation */
ASTNODE gen_rvalue(ASTNODE node, ASTNODE target);
ASTNODE gen_lvalue(ASTNODE node, int* mode);
ASTNODE gen_assign(ASTNODE node, ASTNODE target);

/* helpers */
size_t size_of(ASTNODE node);
bool    is_pointer(ASTNODE node);

#endif
