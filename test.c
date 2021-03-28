#include <stdio.h>

#include "ast.h"
#include "def.h"
#include "sym_tab.h"

void test_sym_ent(SYM_TAB tab, SYM_ENT ent)
{
    if(sym_enter(tab, ent))
        fprintf(stdout, "SUCCESS\n");
    else
        fprintf(stdout, "FAILED TO ENTER\n");
}

int main(){

    SYM_TAB tab = sym_create(SCOPE_GLOBAL);

    SYM_ENT ent = alloc_sym_ent("a", ENT_SCALAR, NS_MISC);
    test_sym_ent(tab, ent);

    ent = alloc_sym_ent("a", ENT_SCALAR, NS_MISC);
    test_sym_ent(tab, ent);

    ent = alloc_sym_ent("b", ENT_SCALAR, NS_MISC);
    test_sym_ent(tab, ent);

    return 1;
}