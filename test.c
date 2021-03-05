#include "ast.h"
#include "def.h"


int main(){

    ASTNODE t,l,r,t2,l2;
    t = astnode_alloc(AST_BINOP);
    l = astnode_alloc(AST_IDENT);
    r = astnode_alloc(AST_NUM);
    t2 = astnode_alloc(AST_BINOP);
    l2 = astnode_alloc(AST_IDENT);

    t->binop.op = '+';
    r->num.numtype = N_INT;
    r->num.int_num = 42069;
    l->ident.ident = "abc";
    l2->ident.ident = "xyz";

    t->binop.left = l;
    t->binop.right = r;

    t2->binop.op = '=';
    t2->binop.left = l2;
    t2->binop.right = t;
    print_ast(t2);


    return 1;
}