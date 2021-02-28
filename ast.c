#include <stdio.h>
#include <stdlib.h>

#include "ast.h"

struct astnode* astnode_alloc(int astnode_type){
    struct astnode* ret = malloc(sizeof(struct astnode));
    ret->type = astnode_type;
    return ret;
}


void print_ast(){
    fprintf(stdout, "printing ast...\n");
}