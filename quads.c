#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "quads.h"
#include "sym_tab.h"

extern int lineno; 
extern char filename[256];
extern SYM_TAB curr_scope;

static int bblock_count, temp_count;

QUAD alloc_quad(int opcode){
    QUAD quad = calloc(1, sizeof(struct quad));
    quad->opcode = opcode;
    return quad;
}


void gen_quads(ASTNODE extern_def){
    /* either function or declaration */

    /* for declaration: get quad of declaration and add to list of starting quads, only important if handeling initalizers */
    if(extern_def->type == AST_FUNC){
        quad_func(extern_def);
    } else {
        quad_declaration(extern_def);
    }

    /* print quads that were generated */

}

/* kind of useless for NOW since I am not implementing initalizers FOR NOW */
QUAD quad_declaration(ASTNODE declaration)
{
    QUAD quad_dec = alloc_quad(OP_ADD);
    return quad_dec;
}

QUAD quad_func(ASTNODE func_def)
{
    QUAD func = alloc_quad(OP_ADD);

    return func;
}

// QUAD gen_rvalue(){


// }

/* for expressions: when a variable is encountred, generate a mov in the next available temporary register
    then assign a new temprorary variable to every subexpresssion 
*/



