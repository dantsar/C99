#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_tab.h"


SYM_TAB sym_create(int scope_type){
    SYM_TAB ret = calloc(sizeof(struct sym_tab), 1);
    ret->scope_type = scope_type;
    return ret;
}

SYM_ENT alloc_sym_ent(char* name, int ent_type, int ent_ns){
    SYM_ENT ret = calloc(sizeof(struct sym_entry),1);
    ret->name = name;
    ret->namespace = ent_ns;
    ret->att_type = ent_type;
    return ret;
}

void sym_destroy(SYM_TAB sym_tab){
    /* figure this out later: I have 32G of RAM, so I don't care :^) */
    free(sym_tab);
}

// SYM_TAB sym_push(SYM_TAB stack, SYM_TAB sym){


// }

// SYM_TAB sym_pop(SYM_TAB stack){


// }

bool sym_ent_compare(SYM_ENT ent1, SYM_ENT ent2)
{
    if(!strcmp(ent1->name, ent2->name) && ent1->namespace == ent2->namespace){
        return true;
    }

    return false;
}


/* returns the entry in the symbol table if present. ELSE returns NULL */
SYM_ENT sym_lookup(SYM_TAB sym, SYM_ENT ent)
{
    SYM_TAB temp_sym = sym;
    SYM_ENT_LL temp_ent_ll;

    /* loop through symbol tables */
    while(temp_sym != NULL){
        temp_ent_ll = temp_sym->ent_ll;

        /* loop through symbol table entries */
        while(temp_ent_ll != NULL){
            if(temp_ent_ll->entry != NULL && sym_ent_compare(temp_ent_ll->entry, ent)) 
                return temp_ent_ll->entry;

            temp_ent_ll = temp_ent_ll->next;
        }

        temp_sym = temp_sym->next;
    }
    return NULL;
}


/* TRUE: successfully entered entry | FALSE: already there*/
bool sym_enter(SYM_TAB sym, SYM_ENT ent)
{
    if(sym_lookup(sym, ent))
        return false;

    SYM_ENT_LL temp_ent_ll = calloc(sizeof(struct sym_entries),1);

    temp_ent_ll->entry = ent;
    temp_ent_ll->entry->name  = ent->name;
    temp_ent_ll->entry->namespace = ent->namespace;

    if(sym->ent_ll == NULL){
        sym->last_ent_ll = temp_ent_ll;
    }else{
        sym->last_ent_ll->next = temp_ent_ll;
        sym->last_ent_ll = temp_ent_ll;
    }

    // sym->ent_ll->entry = ent;
    // sym->ent_ll->entry->name = ent->name;
    // sym->ent_ll->entry->namespace = ent->namespace;

    // sym->last_ent_ll->next = temp_ent_ll;
    // sym->last_ent_ll = temp_ent_ll;
    // sym->ent_ll->next = NULL;

    return true;
}

void print_sym_stack(SYM_TAB curr_scope){



}

void print_sym(SYM_TAB sym){


}
static void indent(int indent){
    for(int i = 0; i < indent*2; i++){
        putchar(' ');
    }
}
static void print_sym_ent(SYM_ENT ent)
{
    static int space = 1;

    switch(ent->att-type){
        case ENT_SCALAR:
            indent(space); fprintf(stdout, "%s: SCALAR");
            break;


    }

}