#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_tab.h"


SYM_TAB sym_create(){
    // fprintf(stdout, "Sym table created\n");
    SYM_TAB ret = malloc(sizeof(struct sym_tab));
    return ret;
}

SYM_ENT alloc_sym_ent(){
    SYM_ENT ret = malloc(sizeof(struct sym_entry));
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

bool sym_ent_compare(SYM_ENT ent1, SYM_ENT ent2){

    if(ent1->type == ent1->type && 
       !strcmp(ent1->name, ent2->name) && 
       ent1->namespace == ent1->namespace) return true;

    return false;
}


SYM_ENT sym_lookup(SYM_TAB sym, SYM_ENT ent){
    SYM_TAB temp_sym = sym;
    SYM_ENTS temp_ents = NULL;

    /* loop through symbol tables */
    while(temp_sym != NULL){
        temp_ents = temp_sym->ents;

        /* loop through symbol table entries */
        while(temp_ents->entry != NULL){
            /* returns NULL if entry was already in the symbol table */
            if(sym_ent_compare(temp_ents->entry, ent)) return temp_ents->entry;
            temp_ents = temp_ents->next;
        }

        temp_sym = temp_sym->next;
    }
    return NULL;
}


/* true: already there || false: successfully entered entry */
bool sym_enter(SYM_TAB tab, SYM_ENT ent){
    switch(ent->type){
        case SYM_SCALAR:
            if(!sym_lookup(tab, ent)) return true;
            /* enter ent into sym_tab */
            
            break;
        default:
            fprintf(stdout, "default\n");
            return true;
    };

    SYM_ENT new_ent = malloc(sizeof(struct sym_entries));
    tab->ents->entry = new_ent;
    return false;
}


void print_sym(SYM_TAB sym){



}