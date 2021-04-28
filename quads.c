#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "quads.h"
#include "quads_print.h"
#include "sym_tab.h"

extern int lineno; 
extern char filename[256];
extern SYM_TAB curr_scope;

static int bblock_count, temp_count;
static bool useful = false; /* used to indicate whether expression is usefull or not */

BBLOCK curr_bblock = NULL;

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
void quad_declaration(ASTNODE declaration)
{
    // QUAD quad_dec = alloc_quad(OP_ADD);
    // return quad_dec;
}

void quad_func(ASTNODE func_def)
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
                quad_binary(node);

                if(useful == true){
                    /* throw warning: useless statement */
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

    print_bblock(curr_bblock);
    // QUAD func = alloc_quad(OP_ADD);
    // return func;
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
    int *mode;
    switch(node->type){
        case AST_SCALAR:    return node;
        case AST_NUM:       return node;
        case AST_CHARLIT:   return node;
        case AST_IDENT:     return node; /* need to emit mov instruction into temp... later! */
        case AST_UNARY:
            /* dereference */
            if(node->unary.op == '*'){
                addr = gen_rvalue(node->unary.expr, NULL);
            }
            if(!target) target=alloc_temp(temp_count++);
            emit_quad(OP_LOAD, addr, NULL, target);
            return target;
                /* standard unary shtuff */
                /* emit opcode and stuff */
            break;
        case AST_BINARY:    
            if(node->binary.op == '=')
                left = gen_lvalue(node->binary.left, mode);
            else
                left = gen_rvalue(node->binary.left, NULL);
            right = gen_rvalue(node->binary.right, NULL);
            if(!target) target=alloc_temp(temp_count++);
            emit_quad(node->binary.op, left, right, target);
            return target;
        default:
            return node;

        
    }
}

/* 
    for expressions: when a variable is encountred, generate a mov in the next available temporary register
    then assign a new temprorary variable to every subexpresssion 
*/
ASTNODE gen_lvalue(ASTNODE node, int* mode)
{
    ASTNODE ret = astnode_alloc(AST_TEMP);
    return ret;
}

void emit_quad(int op, ASTNODE left, ASTNODE right, ASTNODE target)
{

    int opcode = 0;
    switch(op){
        case '+':   opcode = OP_ADD; break;
        case '-':   opcode = OP_SUB; break;
        case '*':   opcode = OP_MUL; break;
        case '/':   opcode = OP_DIV; break;
        case '%':   opcode = OP_MOD; break;
        case SHR:   opcode = OP_SHR; break;
        case SHL:   opcode = OP_SHL; break;
        case '|':   opcode = OP_OR; break;
        case '^':   opcode = OP_XOR; break;
        case '&':   opcode = OP_AND; break;
        default:
            opcode = op;
    }

    QUAD emit_quad = alloc_quad(opcode);
    emit_quad->src1 = left;
    emit_quad->src2 = right;
    emit_quad->res  = target;

    /* append emit_quad to curr_bblock */
    bblock_append_quad(emit_quad);

}

BBLOCK alloc_bblock(void){
    BBLOCK bblock = calloc(1, sizeof(struct bblock));
    return bblock;
}

QUAD_L alloc_quad_l(void){
    QUAD_L quad_l = calloc(1, sizeof(struct quad_list));
    return quad_l;
}

void bblock_append_quad(QUAD emit_quad)
{
    if(curr_bblock == NULL)
    {
        curr_bblock = alloc_bblock();
        curr_bblock->quads = alloc_quad_l();
        curr_bblock->quads->elem = emit_quad;
        return;
    }

    /* get last element */
    QUAD_L temp = curr_bblock->quads;
    while(temp->next != NULL) temp = temp->next; 

    QUAD_L new_elem = calloc(1, sizeof(struct quad_list));
    new_elem->elem = emit_quad;
    temp->next = new_elem;
}
