#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <asm/asm.h>
#include <parser/ast.h>
#include <quads/quads.h>
#include <quads/quads_print.h>
#include <parser/sym_tab.h>

extern struct symbol_table *curr_scope;

char    *func_name;          /* inidicate the name of the current function */
static  size_t bblock_count; /* the bblock in the function: e.g. .BB.main.1 */
static  size_t string_ro;    /* how many strings have be seen */
static  size_t stack_offset; /* offset in stack of local variable */
static  bool useful = false; /* flag to show ifexpression is usefull or not */
static  bool is_returned;    /* flag to indicate whether return was provided */
int     temp_count = 1;      /* how many temporary registers have been used*/


struct astnode *string_l = NULL;            /* list of strings for .rodata section */
struct bblock * bblock_tree;         /* global linked list of bblocks */
struct bblock * curr_bblock;         /* most recent bblock (tail of bblock_tree) */
struct bblock_list * bblock_l;           /* list of all bblocks created: easier printing */

struct loop *   curr_loop;           /* stack of loops */

struct astnode *gen_condexpr(struct astnode *if_node, struct bblock *bblock_trye, struct bblock *bblock_false);
void link_bb(int cc, struct bblock *bblock_default, struct bblock *bblock_cond);

struct quad_list * alloc_quad_l(void){
    struct quad_list * quad_l = calloc(1, sizeof(struct quad_list));
    return quad_l;
}

struct bblock_list * alloc_bblock_list(struct bblock *bblock)
{
    struct bblock_list * ret = calloc(1, sizeof(struct bblock_list));
    ret->elem = bblock;
    return ret;
}

struct bblock *alloc_bblock(void){
    struct bblock *bblock = calloc(1, sizeof(struct bblock));
    // fprintf(stderr, "FUNC_NAME: %s.%d\n", func_name, bblock_count);
    bblock->name = strdup(func_name);
    bblock->func_name = strdup(func_name);
    bblock->bblock_count = bblock_count++;
    bblock->quads = alloc_quad_l();

    /* add new bblock to bblock list */
    /* TERRRIBLY inefficient, BUT "robust" */
    struct bblock_list * new = alloc_bblock_list(bblock);

    /* add to the end */
    struct bblock_list * temp = bblock_l;
    while(temp->next != NULL) 
     temp = temp->next;

    temp->next = new;
    
    return bblock;
}

/* appends provided quad to curr_bblock */
void bblock_append_quad(struct quad * emit_quad)
{
    if(curr_bblock == NULL)
    {
        curr_bblock = alloc_bblock();
        curr_bblock->quads->elem = emit_quad;
        return;
    }

    /* get last element */
    struct quad_list * temp = curr_bblock->quads;
    while(temp->next != NULL) temp = temp->next; 

    struct quad_list * new_elem = calloc(1, sizeof(struct quad_list));
    new_elem->elem = emit_quad;
    temp->next = new_elem;
}

bool is_pointer(struct astnode *test)
{
    if(test->type != AST_IDENT || test->ident.entry->att_type != ENT_VAR)
        return false;
        
    test = test->ident.entry->var.type; 
    if(test->type == AST_ARRAY || test->type == AST_PTR)
        return true;
    return false;
}

struct quad * alloc_quad(int opcode)
{
    struct quad * quad = calloc(1, sizeof(struct quad));
    quad->opcode = opcode;
    return quad;
}

struct loop *alloc_loop(void)
{
    struct loop *loop = calloc(1, sizeof(struct loop));
    loop->prev = curr_loop;
    return loop;
}

/* create a struct quad * and append it to the struct quad_list * in the current bblock */
void emit_quad(int op, struct astnode *left, struct astnode *right, struct astnode *target)
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
        case '|':   opcode = OP_OR;  break;
        case '^':   opcode = OP_XOR; break;
        case '&':   opcode = OP_AND; break;
        default:    opcode = op;
    }

    struct quad * emit_quad = alloc_quad(opcode);
    emit_quad->src1 = left;
    emit_quad->src2 = right;
    emit_quad->res  = target;

    /* append emit_quad to curr_bblock */
    bblock_append_quad(emit_quad);
}

/* -------------------------------------------------------------------------- */
/* expression generation portion */

struct astnode *gen_rvalue(struct astnode *node, struct astnode *target)
{
    struct astnode *left, *right, *addr;
    struct astnode *dst, *tmp, *tmp2;
    int mode, opcode, cond_code; 
    struct fncall_params* temp_param;

    /* for conditional expressions */
    struct bblock *bblock_true, *bblock_false, *bblock_eval;

    if(!node) return NULL; /* prevent explosion */

    switch(node->type)
    {
        /* add string to strings */
        case AST_STRING:
            /* add string to string_l */
            node->string.ro_section = string_ro++;
            if(!string_l) 
                string_l = alloc_list(node);
            else
                list_append_elem(node, string_l);
            // return gen_lvalue(node, &mode);
            return node;
        case AST_NUM:       
        case AST_CHARLIT:   
            if(target){
                emit_quad(OP_MOV, node, NULL, target);
            }

            return node;

        /* NOT handeling structs and unions, things WILLLLL break if you use 
           them...but I don't care :^) */
        case AST_SCALAR:    
            return node;
        case AST_IDENT:
            /* subject to change */
            if(!target) target=alloc_temp(temp_count++);
            emit_quad(OP_MOV, node, NULL, target);
            return target; 
            // return node;
        case AST_UNARY:
            /* dereference */
            switch(node->unary.op){
                case '*':
                case '&':
                    opcode = (node->unary.op == '&') ? OP_LEA : OP_LOAD;
                    addr = gen_rvalue(node->unary.expr, NULL);
                    if(!target) target=alloc_temp(temp_count++);
                    emit_quad(opcode, addr, NULL, target);
                    return target;
                /* NOPE!! */
                case PLUSPLUS: 
                case MINUSMINUS: 
                case '!': 
                case '~':
                    return NULL;
            }
            return NULL;

        case AST_BINARY:    
            if(node->binary.op == '=') return gen_assign(node, target); 

            left = gen_rvalue(node->binary.left, NULL);
            right = gen_rvalue(node->binary.right, NULL);

            if(node->binary.op == '+'){
                /* switch left && right so pointer in front */
                if(is_pointer(right)){
                    tmp = left;
                    left = right;
                    right = tmp;
                }

                /* UH OH */
                if(is_pointer(left) && is_pointer(right)){ 
                    quad_error("invalid pointer + pointer"); 
                    return NULL; 
                }

                /* pointer + int: remember, only handeling ints and pointers :^) */
                if(is_pointer(left)){
                    tmp = alloc_temp(temp_count++);
                    tmp2 = alloc_num((int)size_of(right), 0, N_INT, N_SIGNED);
                    emit_quad(OP_MUL, tmp2, right, tmp);
                    right = tmp;
                }

            }
            /* relational operators */
            switch(node->binary.op){
                case EQEQ:  
                case NOTEQ: 
                case '<':   
                case LTEQ:  
                case '>':   
                case GTEQ:  
                    bblock_true = alloc_bblock();
                    bblock_false = alloc_bblock();
                    bblock_eval = alloc_bblock();
                    gen_condexpr(node, bblock_true, bblock_false);

                    if(!target) target=alloc_temp(temp_count++);

                    curr_bblock = bblock_true;
                    tmp = alloc_num(1, 0.0, N_INT, N_SIGNED);
                    emit_quad(OP_MOV, tmp, NULL, target);
                    link_bb(CC_ALWAYS, bblock_eval, NULL);

                    curr_bblock = bblock_false;
                    tmp = alloc_num(0, 0.0, N_INT, N_SIGNED);
                    emit_quad(OP_MOV, tmp, NULL, target);
                    link_bb(CC_ALWAYS, bblock_eval, NULL);

                    curr_bblock = bblock_eval;
                    return target;
            }

            if(!target) target=alloc_temp(temp_count++);
            emit_quad(node->binary.op, left, right, target);
            return target;

        case AST_FNCALL:
            /* I will only handle direct function calls f(2); */

            /* this is disgusting */
            if(node->fncall.num_param > 0){

                /* reverse params */
                temp_param = node->fncall.params;
                tmp = alloc_list(NULL);
                while (temp_param != NULL) { 
                    /* convoluted and not worth documenting: works!*/
                    tmp = list_append(tmp, alloc_list(temp_param->param));
                    temp_param = temp_param->next;
                }

                while (tmp != NULL) { 
                    if(tmp->list.elem == NULL)
                        break;
                    left = gen_rvalue(tmp->list.elem, NULL);
                    emit_quad(OP_PUSH, left, NULL, NULL);

                    tmp = tmp->list.next;
                }

            }
            left = node->fncall.name;
            emit_quad(OP_CALL, left, NULL, NULL);



            return target;
        default:
            return node;
    }
}

struct astnode *gen_lvalue(struct astnode *node, int* mode)
{
    struct astnode *tmp, target;
    switch(node->type){
        case AST_NUM:
        case AST_CHARLIT:
        case AST_STRING:
            quad_error("invalid lvalue");
            return NULL;
        
        case AST_UNARY:
            if(node->unary.op != '*')
                quad_error("invalid lvalue, from unary op");

            *mode = MODE_INDIRECT;
            return gen_rvalue(node->unary.expr, NULL);

        case AST_IDENT:
            *mode = MODE_DIRECT; 
            return node;
    }
    return NULL;
}

struct astnode *gen_assign(struct astnode *node, struct astnode *target)
{
    struct astnode *dst, *src;
    int dstmode;

    /* no explosion for you */ 
    if(!node){ fprintf(stderr, "GEN ASSIGN: NULL\n"); return NULL; }

    /* 
       ANOTHER memory leak && ANOTHER GOD DAMN KLUDGE. 
       I should be shot for this...
       while on the surface this doesn't do anything, 
       it solves an alignment issue. I don't know why there is an alignment 
       issue, and I don't have the time or evergy to fix it
    */
    // malloc(1); //fixed but keeping it because it's so funny

    /* generate lvalue and die if invalid lvalue encountered */
    dst = gen_lvalue(node->binary.left, &dstmode);
    if(dst == NULL) quad_error("invalid lvalue");
   
    if(dstmode==MODE_DIRECT){
        src = gen_rvalue(node->binary.right, NULL);
        if(src->type == AST_STRING){
            // if(!target) target=alloc_temp(temp_count++);
            emit_quad(OP_LEA, src, NULL, dst);
        } else {
            emit_quad(OP_MOV, src, NULL, dst);
        }
    } else {
        src = gen_rvalue(node->binary.right, NULL);
        emit_quad(OP_STORE, src, NULL, dst);
    }

    return src;
}

/* -------------------------------------------------------------------------- */
/* branching */

// int cond_code_inv(int cond_code){
//     switch(cond_code){
//         case CC_E:  return CC_NE;
//         case CC_NE: return CC_E;
//         case CC_L:  return CC_GE;
//         case CC_LE: return CC_G;
//         case CC_G:  return CC_LE;
//         case CC_GE: return CC_L;
//         default:    return cond_code;
//     }
// }

void link_bb(int cc, struct bblock *bblock_default, struct bblock *bblock_cond)
{
    if(curr_bblock->is_done)
        /* block is finalized so don't care */
        return;

    curr_bblock->cond_flag = cc;
    
    /* 
       emit branching quads after linking, can do this because being here 
       implies that the bblock is finalized 
    */
    struct astnode *temp1, *temp2;
    temp1 = alloc_bb_temp(func_name, bblock_default->bblock_count);
    if (bblock_cond != NULL && cc != CC_ALWAYS) {
        temp2 = alloc_bb_temp(func_name, bblock_cond->bblock_count);
        emit_quad(OP_BR+cc, temp1, temp2, NULL);
    } else {
        emit_quad(OP_BR, temp1, NULL, NULL);
    }

    curr_bblock->def = bblock_default;
    curr_bblock->cond = bblock_cond;

    curr_bblock->is_done = 1;
}

void quad_if_else(struct astnode *if_node)
{
    struct bblock *bblock_true, *bblock_false, *bblock_eval;
    bblock_true = alloc_bblock();
    bblock_false = alloc_bblock();

    if(if_node->select_stmnt.else_stmnt != NULL){
        bblock_eval = alloc_bblock();
    } else{
        bblock_eval = bblock_false;
    }

    gen_condexpr(if_node->select_stmnt.cond, bblock_true, bblock_false);
    curr_bblock = bblock_true;
    quad_statement(if_node->select_stmnt.then);

    link_bb(CC_ALWAYS, bblock_eval, bblock_true);

    if(if_node->select_stmnt.else_stmnt != NULL){
        curr_bblock = bblock_false;
        quad_statement(if_node->select_stmnt.else_stmnt);
        link_bb(CC_ALWAYS, bblock_eval, bblock_true);
    }

    curr_bblock = bblock_eval;
}

struct astnode *gen_condexpr(struct astnode *expr, struct bblock *bblock_true, struct bblock *bblock_false)
{
    struct astnode *left, *right;
    int cond_code;

    switch(expr->type){
        case AST_UNARY: break; /* :shrug:, just don't be fancy! */
        case AST_BINARY:
            left = gen_rvalue(expr->binary.left, NULL);
            right = gen_rvalue(expr->binary.right, NULL);
            emit_quad(OP_CMP, left, right, NULL);
            switch(expr->binary.op){
                case EQEQ:  cond_code = CC_E;   break;
                case NOTEQ: cond_code = CC_NE;  break;
                case '<':   cond_code = CC_L;   break;
                case LTEQ:  cond_code = CC_LE;  break;
                case '>':   cond_code = CC_G;   break;
                case GTEQ:  cond_code = CC_GE;  break;
                default:
                    /* convert to not equal zero */
                    return NULL;
            }
            link_bb(cond_code, bblock_true, bblock_false);


            break;
        case AST_NUM:
        case AST_CHARLIT:
        case AST_IDENT:
            break;
    }

    return NULL;
}

/* -------------------------------------------------------------------------- */
/* looping */

void quad_while(struct astnode *while_loop)
{
    struct bblock *bblock_cond = alloc_bblock();
    struct bblock *bblock_body = alloc_bblock();
    struct bblock *bblock_next = alloc_bblock();

    /* add loop on to loop stack */
    curr_loop = alloc_loop();
    curr_loop->bb_cont = bblock_cond;
    curr_loop->bb_break = bblock_next;

    /* branch from current_bblock to cond */
    link_bb(CC_ALWAYS, bblock_cond, NULL);

    /* conditional branch from condition statement to body of loop */
    curr_bblock = bblock_cond;
    gen_condexpr(while_loop->iterat_stmnt.cond, bblock_body, bblock_next);

    /* 
        generate quads for body and then have an unconditional branch 
        to the condition statement
    */
    curr_bblock = bblock_body;
    quad_statement(while_loop->iterat_stmnt.stmnt);
    link_bb(CC_ALWAYS, bblock_cond, NULL); 
    
    /* pop current loop off of loop stack and proceed from loop */
    curr_loop = curr_loop->prev;
    curr_bblock = bblock_next;
}

void quad_do_while(struct astnode *do_while)
{
    struct bblock *bblock_body = alloc_bblock();
    struct bblock *bblock_cond = alloc_bblock();
    struct bblock *bblock_next = alloc_bblock();

    /* add new loop to loop stack */
    curr_loop = alloc_loop();
    curr_loop->bb_cont = bblock_cond;
    curr_loop->bb_break = bblock_next;

    /* 
        unconditional branch from current basic block to body
        generate quads for body and then unconditional jump 
        to the conditional statement
    */
    link_bb(CC_ALWAYS, bblock_body, NULL);
    curr_bblock = bblock_body;
    quad_statement(do_while->iterat_stmnt.stmnt);
    link_bb(CC_ALWAYS, bblock_cond, NULL);

    /* generate quads and branching for the contional statement */
    curr_bblock = bblock_cond;
    gen_condexpr(do_while->iterat_stmnt.cond, bblock_body, bblock_next);

    /* pop loop off of the loop stack */
    curr_loop = curr_loop->prev;
    curr_bblock = bblock_next;
}

void quad_for(struct astnode *for_loop)
{
    struct bblock *bblock_body = alloc_bblock();
    struct bblock *bblock_cond = alloc_bblock();
    struct bblock *bblock_next = alloc_bblock();

    /* add new loop to loop stack */
    curr_loop = alloc_loop();
    curr_loop->bb_cont = bblock_cond;
    curr_loop->bb_break = bblock_next;

    /* add inital expression in for loop to current basic block */
    gen_rvalue(for_loop->iterat_stmnt.init, NULL);
    gen_condexpr(for_loop->iterat_stmnt.cond, bblock_body, bblock_next);

    curr_bblock = bblock_body;
    quad_statement(for_loop->iterat_stmnt.stmnt);
    
    link_bb(CC_ALWAYS, bblock_cond, NULL);
    curr_bblock = bblock_cond;

    gen_rvalue(for_loop->iterat_stmnt.update, NULL);
    gen_condexpr(for_loop->iterat_stmnt.cond, bblock_body, bblock_next);
    
    /* pop loop off of the loop stack */
    curr_loop = curr_loop->prev;
    curr_bblock = bblock_next;
}


/* -------------------------------------------------------------------------- */
/* jumping */

void quad_jump_loop(struct astnode *jump)
{
    if(curr_loop == NULL){
        quad_error("continue/break not it loop...now going to DIE");
    }

    if(jump->jump_stmnt.type == AST_CONTINUE) {
        link_bb(CC_ALWAYS, curr_loop->bb_cont, NULL);
    } else if(jump->jump_stmnt.type == AST_BREAK) {
        link_bb(CC_ALWAYS, curr_loop->bb_break, NULL);
    }

}

void quad_return(struct astnode *ret)
{
    if (ret == NULL) {
        emit_quad(OP_RET, NULL, NULL, NULL);
    } else {
        struct astnode *temp = gen_rvalue(ret->jump_stmnt.ret_expr, NULL);
        emit_quad(OP_RET, temp, NULL, NULL);
    }
    is_returned = true;
}

/* -------------------------------------------------------------------------- */
/* generating quads from function */
void quad_statement(struct astnode *stmnt)
{
    /* not a temporary register but a temp variable */
    struct astnode *temp;
    struct sym_entry *  temp_ent;

    switch(stmnt->type){
        case AST_DECLARATION: 
            /* actually important: set the stack offset here */
            // temp_ent = alloc_sym_ent(stmnt->declaration.declaration);
            // temp_ent = sym_lookup(curr_scope, temp_ent);
            break;

        case AST_FUNC: gen_rvalue(stmnt, NULL); break;

        case AST_COMPOUND:
            temp = stmnt->comp.states;
            while(temp != NULL){
                quad_statement(temp->list.elem);
                temp = temp->list.next;
            }
            break;

        /* expressions */
        case AST_UNARY:
        case AST_BINARY:
        case AST_TERNARY:
            /* not worrying about useless expressions!! */
            gen_rvalue(stmnt, NULL);
            break;

        /* conditional branching */
        case AST_SELECT_STMNT:
            if(stmnt->select_stmnt.type == AST_SWITCH_STMNT){
                    fprintf(stderr, "only handeling if statements!");
                    exit(-1);
            }
            quad_if_else(stmnt);
            break;

        /* jump statements: GOTOs RETURN, CONTINUE, BREAK */
        case AST_JUMP_STMNT:
            switch(stmnt->jump_stmnt.type){
                case AST_RETURN:
                    quad_return(stmnt);
                    break;
                case AST_BREAK:
                case AST_CONTINUE:
                    quad_jump_loop(stmnt);
                    break;
            }
            break;

        /* loops */
        case AST_ITERAT_STMNT:
            switch(stmnt->iterat_stmnt.type){
                case AST_WHILE_STMNT:
                    quad_while(stmnt);
                    break;
                case AST_DO_STMNT: 
                    quad_do_while(stmnt);
                    break;
                case AST_FOR_STMNT:
                    quad_for(stmnt);
                    break;
            }
            break;
        case AST_FNCALL:
            gen_rvalue(stmnt, NULL);
            break;

        default: fprintf(stderr, ":Shrug:, error I guess???\n"); break;

    }

}

size_t size_of(struct astnode *node)
{
    int temp;
    switch(node->type){
        case AST_PTR: return 4;
        case AST_ARRAY:
            temp = size_of(node->array.ptr_to) * node->array.size->num.int_num; 
            return temp;
        case AST_IDENT:
            if(node->ident.entry->att_type == ENT_VAR){
                switch(node->ident.entry->var.type->var_type.type_spec){
                    case TYPE_INT:
                        return 4;
                    case TYPE_CHAR:
                        return 1;
                    default: 
                        return 4;
                }
            }
        default: 
            /* invalid but just return 4 */
            return 4;
    }
}

struct bblock_list * gen_quads(struct astnode *func_def)
{
    func_name = strdup(func_def->func.name->ident.ident);
    bblock_count = 1;
    stack_offset = 0;

    /* LMAOOO NO MEMORY MANAGMENT */
    bblock_l = calloc(1, sizeof(struct bblock_list));

    bblock_tree = (curr_bblock = alloc_bblock());
    bblock_l->elem = curr_bblock;
    bblock_l->next = NULL;

    struct bblock_list * ret = bblock_l;
    /* pass func def's compound block which is just a list of statements */
    quad_statement(func_def->func.block);

    /* add ret and leave if not provided in quad */
    if (!is_returned) {
        quad_return(NULL);
        is_returned = false;
    }

    /* print quads that were generated */
    print_bblock_l(stdout, bblock_l);

    return ret;
}
