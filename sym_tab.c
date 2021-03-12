#include <stdio.h>
#include <stdlib.h>

#include "sym_tab.h"

SYM_TAB sym_create(){
    SYM_TAB ret = malloc(sizeof(struct sym_tab));
    return ret;
}