#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "def.h"
#include "parser.tab.h"


ASTNODE alloc_and_set_num(unsigned long long int_num, long double real, int type, int sign){
    ASTNODE ret = astnode_alloc(AST_NUM);
    ret->num.int_num = int_num;
    ret->num.real = real;
    ret->num.type = type;
    ret->num.sign = sign;
    return ret;
}

ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret = astnode_alloc(AST_BINOP);
    ret->binop.op = op;
    ret->binop.left = val1;
    ret->binop.right = val2;
    return ret;
}

ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret1 = alloc_and_set_binop(val1, op, val2);
    ASTNODE ret2 = alloc_and_set_binop(val1, '=', ret1);
    return ret2;
}

// ASTNODE alloc_and_expand_shorthand(ASTNODE val1, ASTNODE val2){
//     ASTNODE ret1 = alloc_and_set_binop(val1, op, val2);
//     ASTNODE ret2 = alloc_and_set_binop(val1, '=', ret1);
//     return ret2;
// }

ASTNODE alloc_and_set_ident(char *ident){
    ASTNODE ret = astnode_alloc(AST_IDENT);
    ret->ident.ident = ident;
    return ret;
}

ASTNODE alloc_and_set_charlit(char charlit){
    ASTNODE ret = astnode_alloc(AST_CHARLIT);
    ret->charlit.charlit = charlit;
    return ret;
}

ASTNODE alloc_and_set_string(char* string, int len){
    ASTNODE ret = astnode_alloc(AST_STRING);
    ret->string.string = string;
    ret->string.len = len;
    return ret;
}

ASTNODE alloc_and_set_fncall(ASTNODE name, ASTNODE params){
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
    for(count = 1; ast_temp->binop.op == ','; count++){
        list->param = ast_temp->binop.right;
        temp = malloc(sizeof(struct fncall_params));
        temp->next = list;
        list = temp;

        ast_temp = ast_temp->binop.left;
    }
    list->param = ast_temp;

    ast_ret->fncall.num_param = count;
    ast_ret->fncall.params = list;
    return ast_ret;
}



ASTNODE astnode_alloc(int astnode_type){
    ASTNODE ret = malloc(sizeof(struct astnode));
    ret->type = astnode_type;
    return ret;
}






static void indent(int indent){
    for(int i = 0; i < indent*2; i++){
        putchar(' ');
    }
}

static void print_op(int op){
    if(op < 255){
        putchar(op);
    }else{
        char* op_str;
        switch(op){ 
            case PLUSPLUS:    op_str = "++"; break;
            case MINUSMINUS:  op_str = "--"; break;
            case SHL:         op_str = "<<"; break;
            case SHR:         op_str = ">>"; break;
            case LTEQ:        op_str = "<="; break;  
            case GTEQ:        op_str = ">="; break; 
            case EQEQ:        op_str = "=="; break; 
            case NOTEQ:       op_str = "!="; break;  
            case LOGAND:      op_str = "&&"; break;  
            case LOGOR:       op_str = "||"; break;
            case ELLIPSIS:    op_str = "..."; break;
        }
        fprintf(stdout, "%s", op_str);
    }
}

void print_ast(ASTNODE ast){
    /* int for storing indentation in the output */
    static int space = 0;
    switch(ast->type){
        case AST_BINOP: 
            if(ast->binop.op == '='){
                fprintf(stdout, "ASSIGNMENT\n");
            }else{
                fprintf(stdout, "BINARY OP ", ast->binop.op);
                print_op(ast->binop.op);
                putchar('\n');
            }
            space++;
            indent(space); print_ast(ast->binop.left);
            if(ast->binop.right == NULL){--space; return;}
            indent(space); print_ast(ast->binop.right);
            /* print_binop(op) ==> either print one or two */
            space--;
            break;
        case AST_FNCALL: 
            indent(space);   fprintf(stdout, "FNCALL, %d arguments\n",ast->fncall.num_param); 
            indent(++space); print_ast(ast->fncall.name); --space;
            if(ast->fncall.num_param == 0) return;

            /* print out linked list of args */
            ASTNODE temp = ast;
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
                fprintf(stdout, "CONSTANT: (type=double)%llf\n",ast->num.real);
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
            /* FF said: "BLAH" */
            break;
    }
}