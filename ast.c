#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "ast.h"

bool ast_compare_type(ASTNODE t1, ASTNODE t2){
    ASTNODE temp;
    if(t1 == NULL && t2 == NULL) return true; /* should be error? ¯\_(ツ)_/¯ */
    /* there is probably a more elegant method, but don't care! */
    do{
        /* compare type: should only be of three types: 
           AST_PTR, AST_ARRAY, or AST_LIST(of decl_spec) */
        if(t1->type == t2->type){
            if(t1->type == AST_LIST){
                if(t1->list.elem->decl_spec.decl_spec == t2->list.elem->decl_spec.decl_spec)
                    continue;
                else
                    return false;
            }
        } else{
            return false;
        }
    }while((t1 = next_ptr(t1)) &&  (t2 = next_ptr(t2)));

    return true;
}

ASTNODE astnode_alloc(int astnode_type){
    ASTNODE ret = calloc(1, sizeof(struct astnode));
    ret->type = astnode_type;
    return ret;
}

ASTNODE alloc_num(unsigned long long int_num, long double real, int type, int sign){
    ASTNODE ret = astnode_alloc(AST_NUM);
    ret->num.int_num = int_num;
    ret->num.real = real;
    ret->num.type = type;
    ret->num.sign = sign;
    return ret;
}

ASTNODE alloc_unary(int op, ASTNODE expr){
    ASTNODE ret = astnode_alloc(AST_UNARY);
    ret->unary.op = op;
    ret->unary.expr = expr;
    return ret;
}

ASTNODE alloc_binary(int type, ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret = astnode_alloc(AST_BINARY);
    ret->binary.op = op;
    ret->binary.op_type = type;
    ret->binary.left = val1;
    ret->binary.right = val2;
    return ret;
}

ASTNODE alloc_ternary(ASTNODE cond, ASTNODE true, ASTNODE false){
    ASTNODE ret = astnode_alloc(AST_TERNARY);
    ret->ternary.cond = cond;
    ret->ternary.true = true;
    ret->ternary.false = false;
    return ret;
}

ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret1 = alloc_binary(BINOP, val1, op, val2);
    ASTNODE ret2 = alloc_binary(ASSIGN, val1, '=', ret1);
    return ret2;
}

ASTNODE alloc_ident(char *ident){
    ASTNODE ret = astnode_alloc(AST_IDENT);
    ret->ident.ident = ident;
    return ret;
}

ASTNODE alloc_charlit(char charlit){
    ASTNODE ret = astnode_alloc(AST_CHARLIT);
    ret->charlit.charlit = charlit;
    return ret;
}

ASTNODE alloc_string(char* string, int len){
    ASTNODE ret = astnode_alloc(AST_STRING);
    ret->string.string = string;
    ret->string.len = len;
    return ret;
}

/* params is assumed to be a binop astnode */
/* unnecessarily complicated... will be replaced with ast_list and append...*/
ASTNODE alloc_fncall(ASTNODE name, ASTNODE params){
    ASTNODE ast_ret = astnode_alloc(AST_FNCALL);
    ast_ret->fncall.name = name;
    if(params == NULL){
        ast_ret->fncall.num_param = 0;
        return ast_ret;
    }

    /* temporary variables */
    struct fncall_params *list,*temp;
    ASTNODE ast_temp = params;

    list = malloc(sizeof(struct fncall_params));
    list->next = NULL;

    int count;
    for(count = 1; ast_temp->binary.op == ','; count++){
        list->param = ast_temp->binary.right;
        temp = malloc(sizeof(struct fncall_params));
        temp->next = list;
        list = temp;

        ast_temp = ast_temp->binary.left;
    }
    list->param = ast_temp;

    ast_ret->fncall.num_param = count;
    ast_ret->fncall.params = list;
    return ast_ret;
}

ASTNODE alloc_sizeof(ASTNODE expr){
    ASTNODE ret = astnode_alloc(AST_SIZEOF);
    ret->a_sizeof.expr = expr;
    return ret;
}

ASTNODE alloc_select(ASTNODE expr, char* ident){
    ASTNODE tag = astnode_alloc(AST_IDENT);
    tag->ident.ident = ident;

    ASTNODE ret = astnode_alloc(AST_SELECT);
    ret->select.expr = expr;
    ret->select.tag = tag;
    return ret;
}

ASTNODE alloc_list(ASTNODE elem){
    if(elem == NULL) return NULL;
    ASTNODE ret = astnode_alloc(AST_LIST);
    ret->list.elem = elem;
    ret->list.next = NULL;
    return ret;
}

/* next pointer in pointer chain: eg next array or actual pointer */
ASTNODE next_ptr(ASTNODE ptr_chain){
    if(ptr_chain->type == AST_PTR){
        return ptr_chain->ptr.ptr_to;
    }else if(ptr_chain->type == AST_ARRAY){
        return ptr_chain->array.ptr_to;
    } 
    return NULL;
}

/* last ptr/array in chain */
ASTNODE last_ptr(ASTNODE ptr_chain){
    if(!ptr_chain) return NULL;

    ASTNODE last_elem;
    while(ptr_chain != NULL && (ptr_chain->type == AST_PTR || ptr_chain->type == AST_ARRAY)){
        last_elem = ptr_chain;
        if(ptr_chain->type == AST_PTR){
            ptr_chain = ptr_chain->ptr.ptr_to;
        }else if(ptr_chain->type == AST_ARRAY){
            ptr_chain = ptr_chain->array.ptr_to;
        } 
    }
    return last_elem;
}

/* might destroy the list... again, memory managment is a meme :^) */
ASTNODE list_to_ptr_chain(ASTNODE list)
{
    /* check if is not NULL, or else a bad time... */
    if(list == NULL) return NULL;

    int type = list->list.elem->type;
    ASTNODE ptr_chain = list->list.elem; // = list->list.elem;
    ASTNODE ret = ptr_chain; /* head of pointer chain */

    list = list->list.next;
    while(list != NULL){

        if(type == AST_PTR){
            ptr_chain->ptr.ptr_to = list->list.elem;
        }else if(type == AST_ARRAY){
            ptr_chain->array.ptr_to = list->list.elem;
        }

        /* type of previous node in ptr_chain */
        ptr_chain = list->list.elem;
        type = list->list.elem->type;
        list = list->list.next;
    }

    return ret;
}

/* get the last element of a list */
ASTNODE list_last(ASTNODE list){
    while(list->list.next != NULL)
        list = list->list.next;
    return list;
}

/* add an astnode to the end of list */
ASTNODE list_append_elem(ASTNODE elem, ASTNODE list){
    if(elem == NULL) return NULL;
    if(list == NULL)
        return alloc_list(elem);

    ASTNODE temp = list;
    ASTNODE new_elem = alloc_list(elem); 
    while(temp->list.next != NULL) temp = temp->list.next; /* go to last elem */
    temp->list.next = new_elem;
    return list;
}

/* append list1 to list2 (list2 -> list1) */
ASTNODE list_append(ASTNODE list1, ASTNODE list2){
    if(list1 == NULL || list2 == NULL) 
        return NULL;
    ASTNODE ret = list2;
    list2 = list_last(list2);
    list2->list.next = list1;
    return ret;
}

/* mainly for debugging for now */
int list_size(ASTNODE list){
    int count = 0;
    while(list!= NULL){
        count++;
        list = list->list.next;
    }
    return count;
}

ASTNODE alloc_declaration(ASTNODE qualif, ASTNODE decl){
    ASTNODE ret = astnode_alloc(AST_DECLARATION);
    ret->declaration.declaration = decl;
    ret->declaration.qualif = qualif;
    return ret;
}

ASTNODE alloc_decl_spec(int decl_spec){
    ASTNODE ret = astnode_alloc(AST_DECL_SPEC);
    ret->decl_spec.decl_spec = decl_spec;
    return ret;
}

/* TO DO: update later to integrate with symbol table */
ASTNODE alloc_scalar(int type){
    ASTNODE ret = astnode_alloc(AST_SCALAR);
    switch(type){
        case TYPE_SIGNED:
            ret->scalar.sign = N_SIGNED;
            break;
        case TYPE_UNSIGNED: 
            ret->scalar.sign = N_UNSIGNED;
            break;
    };
    ret->scalar.type = type;
    return ret;
}

ASTNODE alloc_ptr(ASTNODE ptr_to){
    ASTNODE ret = astnode_alloc(AST_PTR);
    ret->ptr.ptr_to = ptr_to;
    return ret;
}

ASTNODE alloc_array(ASTNODE array_of, ASTNODE size){
    ASTNODE ret = astnode_alloc(AST_ARRAY);
    ret->array.ptr_to = array_of;
    /* assuming arrays are only defined as constants of unknown */
    if(size)
        ret->array.size = size->num.int_num;
    else 
        ret->array.size = 0; /* indicates a VLA: this shouldn't be reachable, but just in case */
    return ret;
}

ASTNODE alloc_st_un(int type, int scope){
    ASTNODE ret = astnode_alloc(AST_ST_UN);
    ret->st_un.type = type;
    ret->st_un.mini_tab = sym_tab_create(SCOPE_MINI);
    ret->st_un.def_complete = false;
    return ret; 
}

ASTNODE alloc_func(ASTNODE name, ASTNODE param_list){
    ASTNODE ret = astnode_alloc(AST_FUNC);
    ret->func.sym = sym_tab_create(SCOPE_FUNC);
    ret->func.name = name;
    ret->func.args = param_list;
    return ret;
}

ASTNODE alloc_compound(ASTNODE exprs, SYM_TAB tab){
    ASTNODE ret = astnode_alloc(AST_COMPOUND);
    ret->comp.states = exprs;
    ret->comp.type = SCOPE_BLOCK;
    ret->comp.tab = tab;
    return ret;
}

ASTNODE alloc_select_stmnt(int type, ASTNODE cond, ASTNODE then, ASTNODE else_stmnt){
    ASTNODE ret = astnode_alloc(AST_SELECT_STMNT);
    ret->select_stmnt.type = type;
    ret->select_stmnt.cond = cond;
    ret->select_stmnt.then = then;
    ret->select_stmnt.else_stmnt = else_stmnt;
    return ret;
}

ASTNODE alloc_iterat_stmnt(int type, ASTNODE cond, ASTNODE stmnt, ASTNODE init, ASTNODE update){
    ASTNODE ret = astnode_alloc(AST_ITERAT_STMNT);
    ret->iterat_stmnt.type = type;
    ret->iterat_stmnt.cond = cond;
    ret->iterat_stmnt.stmnt = stmnt;
    ret->iterat_stmnt.init = init;
    ret->iterat_stmnt.update = update;
    return ret;
}

ASTNODE alloc_label_stmnt(int type, ASTNODE stmnt, char* label, ASTNODE cond){
    ASTNODE ret = astnode_alloc(AST_LABEL_STMNT);
    ret->label_stmnt.type = type;
    ret->label_stmnt.stmnt = stmnt;
    ret->label_stmnt.label = label; 
    ret->label_stmnt.cond = cond;
    return ret;
}

ASTNODE alloc_jump_stmnt(int type, char* label, ASTNODE ret_expr){
    ASTNODE ret = astnode_alloc(AST_JUMP_STMNT);
    ret->jump_stmnt.type = type;
    ret->jump_stmnt.goto_label = label;
    ret->jump_stmnt.ret_expr = ret_expr;
    return ret;
}