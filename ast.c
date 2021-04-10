#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "ast.h"

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


static void indent(int indent){
    for(int i = 0; i < indent*2; i++){
        putchar(' ');
    }
}

void print_ast(ASTNODE ast){
    /* int for storing indentation in the output */
    static int space = 0;
    ASTNODE temp;
    switch(ast->type){
        case AST_UNARY:
            switch(ast->unary.op){
                case '&':
                    fprintf(stdout, "ADDRESSOF\n");
                    break;
                case '*':
                    fprintf(stdout, "DEREF\n");
                    break;
                case PLUSPLUS:
                    fprintf(stdout, "POSTINC\n");
                    break;
                case MINUSMINUS:
                    fprintf(stdout, "POSTDEC\n");
                    break;
                default:
                    fprintf(stdout, "UNARY OP %c\n",ast->unary.op);
                    break;
            }
            indent(++space); print_ast(ast->unary.expr); space--;
            break;
        case AST_BINARY: 
            if(ast->binary.op_type == ASSIGN){
                fprintf(stdout, "ASSIGNMENT\n");
            }else if(ast->binary.op_type == BINOP){
                fprintf(stdout, "BINARY OP ");
                print_op(ast->binary.op);
                putchar('\n');
            }else if(ast->binary.op_type == COMP){
                fprintf(stdout, "COMPARISON ");
                print_op(ast->binary.op);
                putchar('\n');
            }
            space++;
            indent(space); print_ast(ast->binary.left);
            // if(ast->binary.right == NULL){--space; return;}
            indent(space); print_ast(ast->binary.right);
            space--;
            break;
        case AST_TERNARY:
            fprintf(stdout, "TERNARY OP, IF:\n");

            indent(++space); 
            print_ast(ast->ternary.cond); 
            space--;

            indent(space); 
            fprintf(stdout, "THEN:\n");
            indent(++space); 
            print_ast(ast->ternary.true); 
            space--;

            indent(space); 
            fprintf(stdout, "ELSE:\n");
            indent(++space); 
            print_ast(ast->ternary.false); 
            space--;
            break;
        case AST_FNCALL: 
            fprintf(stdout, "FNCALL, %d arguments\n",ast->fncall.num_param); 
            indent(++space); print_ast(ast->fncall.name); --space;
            if(ast->fncall.num_param == 0) return;

            /* print out linked list of args */
            temp = ast;
            for(int i = 1; temp->fncall.params != NULL; i++){
                indent(space);   fprintf(stdout, "arg #%d=\n",i);
                indent(++space); print_ast(temp->fncall.params->param); space--;
                temp->fncall.params = temp->fncall.params->next;
            }
            break;
        case AST_NUM: 
            if(ast->num.type <= N_LLONG){
                fprintf(stdout, "CONSTANT: (type=int)%lld\n",ast->num.int_num);
            }else{
                fprintf(stdout, "CONSTANT: (type=double)%Lf\n",ast->num.real);
            }
            break;
        case AST_IDENT: 
            fprintf(stdout, "IDENT %s\n", ast->ident.ident);
            break;
        case AST_CHARLIT: 
            fprintf(stdout, "CHARLIT %o\n", ast->charlit.charlit);
            break;
        case AST_STRING: 
            fprintf(stdout, "STRING %s\n", ast->string.string);
            break;
        case AST_SIZEOF: 
            fprintf(stdout, "SIZEOF\n");
            indent(++space); print_ast(ast->a_sizeof.expr); space--;
            break;
        case AST_SELECT: 
            fprintf(stdout, "SELECT\n");
            indent(++space); print_ast(ast->select.expr); space--;
            indent(++space); print_ast(ast->select.tag); space--;
            break;
        case AST_LIST:
            fprintf(stdout, "AST_LIST\n");
            temp = ast;
            while(temp != NULL){
                print_ast(temp->list.elem);
                temp = temp->list.next;
            }
            break;
        case AST_PTR:
            fprintf(stdout, "pointer to\n");
            /* to avoid exploding from a NULL pointer */
            if(ast->ptr.ptr_to){
                indent(++space); print_ast(ast->ptr.ptr_to); space--;
            }
            break;
        case AST_ARRAY:
            fprintf(stdout, "array (%d) of \n", ast->array.size);
            /* to avoid exploding from a NULL pointer */
            if(ast->array.ptr_to){
                indent(++space); print_ast(ast->array.ptr_to); space--;
            }
            break;
        case AST_DECL_SPEC:
            switch(ast->decl_spec.decl_spec){
                case TYPE_CHAR:
                    fprintf(stdout, "char ");
                    break;
                case TYPE_SHORT:
                    fprintf(stdout, "short ");
                    break;
                case TYPE_INT:
                    fprintf(stdout, "int ");
                    break;
                case TYPE_LONG:
                    fprintf(stdout, "long ");
                    break;
                case TYPE_FLOAT:
                    fprintf(stdout, "float ");
                    break;
                case TYPE_DOUBLE:
                    fprintf(stdout, "double ");
                    break;
                case TYPE_SIGNED:
                    fprintf(stdout, "signed ");
                    break;
                case TYPE_UNSIGNED:
                    fprintf(stdout, "unsigned ");
                    break;
                case QUALIF_CONST:
                    fprintf(stdout, "const ");
                    break;
                case QUALIF_RESTRICT:
                    fprintf(stdout, "restrict ");
                    break;
                case QUALIF_VOLATILE:
                    fprintf(stdout, "volatile ");
                    break;
                case FUNC_INLINE:
                    fprintf(stdout, "inline ");
                    break;

            }
            break;
    }
}