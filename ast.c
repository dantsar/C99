#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "def.h"



ASTNODE alloc_and_set_binop(ASTNODE val1, int op, ASTNODE val2){
    ASTNODE ret = astnode_alloc(AST_BINOP);
    ret->binop.op = op;
    ret->binop.left = val1;
    ret->binop.right = val2;
    return ret;
}

ASTNODE alloc_and_set_ident(const char *ident){
    ASTNODE ret = astnode_alloc(AST_IDENT);
    ret->ident.ident = strdup(ident);
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

void print_ast(ASTNODE ast){
    /* int for storing indentation in the output */
    static int space = 0;
    switch(ast->type){
        case AST_BINOP: 
            if(ast->binop.op == '='){
                fprintf(stdout, "ASSIGNMENT\n");
            }else{
                fprintf(stdout, "BINARY OP %c\n", ast->binop.op);
            }
            space++;
            indent(space); print_ast(ast->binop.left);
            indent(space); print_ast(ast->binop.right);
            space--;
            break;
        case AST_NUM: 
            if(ast->num.numtype <= N_LLONG){
                fprintf(stdout, "CONSTANT: (type=int)%lld\n",ast->num.int_num);
            }else{
                fprintf(stdout, "CONSTANT: (type=double)%le\n",ast->num.real);
            }
            break;
        case AST_IDENT: 
            fprintf(stdout, "IDENT %s\n", ast->ident.ident);
            break;
        case AST_SIZEOF: 
            break;
        case AST_FCN: 
            break;

    }
}