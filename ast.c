#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

struct astnode* astnode_alloc(int astnode_type){
    struct astnode* ret = malloc(sizeof(struct astnode));
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