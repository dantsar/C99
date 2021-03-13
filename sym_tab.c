#include <stdio.h>
#include <stdlib.h>

#include "sym_tab.h"


struct sym_scope sym_scopes;


SYM_TAB sym_create(){
    fprintf(stdout, "Sym table created\n");
    SYM_TAB ret = malloc(sizeof(struct sym_tab));
    return ret;
}


// int sym_enter(SYM_TAB tab, struct sym_entry *ent){

//     int i =0;
//     return i;
// }