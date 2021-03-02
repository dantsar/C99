#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret = astnode_alloc(AST_BINOP);
    ret->op = op;
    ret->left = val1;
    ret->right = val2;
}

ASTNODE astnode_alloc(int astnode_type){
    ASTNODE ret = malloc(sizeof(struct astnode));
    ret->type = astnode_type;
    return ret;
}

void print_ast(struct astnode *ast){
    switch(ast->type){
        case AST_BINOP: 
            break;
        case AST_IDENT: 
            break;
        case AST_NUM: 
            break;
        case AST_SIZEOF: 
            break;
        case AST_FCN: 
            break;

    }
    fprintf(stdout, "printing ast...\n");
}