#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"
#include "ast.h"
#include "parser.tab.h"


ASTNODE alloc_and_set_num(unsigned long long int_num, long double real, int type, int sign){
    ASTNODE ret = astnode_alloc(AST_NUM);
    ret->num.int_num = int_num;
    ret->num.real = real;
    ret->num.type = type;
    ret->num.sign = sign;
    return ret;
}

ASTNODE alloc_and_set_unary(int op, ASTNODE expr){
    ASTNODE ret = astnode_alloc(AST_UNARY);
    ret->unary.op = op;
    ret->unary.expr = expr;
    return ret;
}

ASTNODE alloc_and_set_binary(int type, ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret = astnode_alloc(AST_BINARY);
    ret->binary.op = op;
    ret->binary.op_type = type;
    ret->binary.left = val1;
    ret->binary.right = val2;
    return ret;
}

ASTNODE alloc_and_set_ternary(ASTNODE cond, ASTNODE true, ASTNODE false){
    ASTNODE ret = astnode_alloc(AST_TERNARY);
    ret->ternary.cond = cond;
    ret->ternary.true = true;
    ret->ternary.false = false;
    return ret;
}

ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret1 = alloc_and_set_binary(BINOP, val1, op, val2);
    ASTNODE ret2 = alloc_and_set_binary(ASSIGN, val1, '=', ret1);
    return ret2;
}

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

/* params is assumed to be a binop astnode */
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

ASTNODE alloc_and_set_sizeof(ASTNODE expr){
    ASTNODE ret = astnode_alloc(AST_SIZEOF);
    ret->a_sizeof.expr = expr;
    return ret;
}

ASTNODE alloc_and_set_select(ASTNODE expr, char* ident){
    ASTNODE tag = astnode_alloc(AST_IDENT);
    tag->ident.ident = ident;

    ASTNODE ret = astnode_alloc(AST_SELECT);
    ret->select.expr = expr;
    ret->select.tag = tag;
    return ret;
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
                fprintf(stdout, "BINARY OP ", ast->binary.op);
                print_op(ast->binary.op);
                putchar('\n');
            }else if(ast->binary.op_type == COMP){
                fprintf(stdout, "COMPARISON ", ast->binary.op);
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
            fprintf(stdout, "SIZEOF\n");
            indent(++space); print_ast(ast->a_sizeof.expr); space--;
            break;
        case AST_SELECT: 
            fprintf(stdout, "SELECT\n");
            indent(++space); print_ast(ast->select.expr); space--;
            indent(++space); print_ast(ast->select.tag); space--;
            break;
    }
}