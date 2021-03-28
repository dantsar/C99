#include <stdio.h>

#include "ast.h"
#include "def.h"
#include "sym_tab.h"


int main(){

    SYM_TAB tab = sym_create(SCOPE_GLOBAL);

    SYM_ENT ent = alloc_sym_ent("a", ENT_SCALAR, NS_MISC);
    ent->var.stg_class = auto;
    ent->var.type->scalar.type = N_INT;


    ent->var.val = alloc_num(100, 0.0, S_INT, N_SIGNED);
    print_ast(ent->var.val);
    if(sym_enter(tab, ent))
        fprintf(stdout, "SUCCESS\n");
    else 
        return 0;

    ent = alloc_sym_ent("b", ENT_SCALAR, NS_MISC);
    ent->var.val = alloc_num(100, 0.0, S_INT, N_SIGNED);
    if(sym_enter(tab, ent))
        fprintf(stdout, "SUCCESS\n");
    else
        fprintf(stdout, "FAILED TO ENTER\n");

    ent = alloc_sym_ent("a", ENT_SCALAR, NS_MISC);
    ent->var.val = alloc_num(100, 0.0, S_INT, N_SIGNED);
    if(sym_enter(tab, ent))
        fprintf(stdout, "SUCCESS\n");
    else
        fprintf(stdout, "FAILED TO ENTER\n");



    return 1;
}