#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "quads.h"
#include "sym_tab.h"

extern int lineno; 
extern char filename[256];
extern SYM_TAB curr_scope;

static int bblock_count, temp_count;
static bool useful = false; /* used to indicate whether expression is usefull or not */

QUAD alloc_quad(int opcode)
{
    QUAD quad = calloc(1, sizeof(struct quad));
    quad->opcode = opcode;
    return quad;
}


void gen_quads(ASTNODE extern_def)
{
    /* either function or declaration */

    /* for declaration: get quad of declaration and add to list of starting quads, only important if handeling initalizers */
    if(extern_def->type == AST_FUNC){
        quad_func(extern_def);
    } else {
        quad_declaration(extern_def);
    }

    /* print quads that were generated */

}

/* kind of useless for NOW since I am not implementing initalizers...FOR NOW!! */
QUAD quad_declaration(ASTNODE declaration)
{
    QUAD quad_dec = alloc_quad(OP_ADD);
    return quad_dec;
}

QUAD quad_func(ASTNODE func_def)
{
    /* set flag for being in loop to off */

    /* loop through list of statements */
    ASTNODE temp = func_def->func.block->comp.states;
    /* will probably make this its own function. something called quad_compound or something */
    while(temp != NULL){
        /* perform conditional checks on the type of the statement */
        /* will probably make this its own function. something called quad_statement or something... */
        ASTNODE node = temp->list.elem;
        switch(node->type){
            case AST_DECLARATION:
                /* currently blank because I am not handling initializers. That may change in the future! */
                break;
            case AST_UNARY:
                /* warning: useless statement? */
                break;
            case AST_BINARY:
                /* quad_binary(node); usefulness is set by the function, if an assignment is seen else useless */

                if(useful == true){
                    /* warning: useless statement */
                }
                useful = false;
                break;
            case AST_TERNARY:
                /* BLAH */
                break;
            case AST_LABEL_STMNT:
                /* BLAH */
                break;
            case AST_SELECT_STMNT:
                /* quad_select_stmnt(node); */
                break;
            case AST_ITERAT_STMNT:
                /* oh lord, please help me on this one... */
                /* quad_loop(node); */
                break;
            case AST_FNCALL:
                /* quad_fncall(node); */
                break;
            case AST_COMPOUND:
                /* quad_compound(node); */
                break;
            default:
                /* check if AST_BREAK || AST_CONTINUE and not in loop */
                /* throw error is break or continue is encountered and not in a loop */
                /* possibly check a set global flag */

                /* else check */
                /* for IDENT, NUM, CHARLIT, SIZEOF ... a whole bunch of expressions that by themselves don't have a meaningfull effect  */
                /* warning: useless statement */
                break;

        };


        temp = temp->list.next;
    }



    QUAD func = alloc_quad(OP_ADD);
    return func;
}
void quad_binary(ASTNODE node)
{
    gen_rvalue(node, NULL);
    // QUAD quad = gen_rvalue(node, NULL);
    // return quad;
}

ASTNODE gen_rvalue(ASTNODE node, ASTNODE target)
{
    ASTNODE left, right, addr;
    switch(node->type){
        case AST_SCALAR:    return node;
        case AST_NUM:       return node;
        case AST_CHARLIT:   return node;
        case AST_UNARY:
            if(node->unary.op == '*'){
                addr = gen_rvalue(node->unary.expr, NULL);
            }
            if(addr){

            } 
                /* standard unary shtuff */
                /* emit opcode and stuff */
            break;
        case AST_BINARY:    

            break;

    }

    // QUAD quad = alloc_quad(OP_ADD);
    // return quad;
    return node;
}

/* for expressions: when a variable is encountred, generate a mov in the next available temporary register
    then assign a new temprorary variable to every subexpresssion 
*/
