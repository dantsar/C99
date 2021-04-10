#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_tab.h"

extern SYM_TAB curr_scope;
extern char filename[256];
extern int lineno;
extern void yyerror(const char* msg);

SYM_TAB sym_create(int scope_type){
    SYM_TAB ret = calloc(1, sizeof(struct sym_tab));
    ret->scope_type = scope_type;
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
        sym->ent_ll = temp_ent_ll;
    }else{
        sym->last_ent_ll->next = temp_ent_ll;
        sym->last_ent_ll = temp_ent_ll;
    }

    return true;
}


SYM_ENT alloc_sym_ent(char* name, int ent_type, int ent_ns){
    SYM_ENT ret = calloc(sizeof(struct sym_entry),1);
    ret->name = name;
    ret->namespace = ent_ns;
    ret->att_type = ent_type;

    ret->filename = malloc(strlen(filename));
    strcpy(filename, ret->filename);
    ret->lineno = lineno;
    return ret;
}

/**
   this is super convoluted, but basically type is the scalar part of the declaration
   and vars is a list of the pointers and array part of the declaration. I create and enter
   entries into the symbol table. But in the process, I merge type with the corresponding 
   elements in vars
*/
void sym_decl(ASTNODE type, ASTNODE var_list)
{
    /* debugging */
    // fprintf(stdout, "sym_decl\n");
    // fprintf(stdout, "type:\n");
    // print_ast(type);
    // fprintf(stdout, "\n\nvars:\n");
    // print_ast(var_list);
    // exit(-1);

    ASTNODE ptr_chain, var;
    while(var_list != NULL){
        var = var_list->list.elem;
        char *name;
        /* name of variable is the fist element, as a result of grammar structure */
        name = var->list.elem->ident.ident;
        var = var->list.next;

        // fprintf(stdout, "var elem:\n");
        // print_ast(var->list.next);
        ptr_chain = list_to_ptr_chain(var);

        var = last_ptr(ptr_chain);
        if(var->type == AST_PTR){
            var->ptr.ptr_to = type;
        }else if(var->type == AST_ARRAY){
            var->array.ptr_to = type;
        }

        SYM_ENT ent = alloc_sym_ent(name, ENT_VAR, NS_MISC);
        ent->var.type = ptr_chain;
        if(!sym_enter(curr_scope, ent)){
            yyerror("error: redeclaration of variable\n");
            exit(-1);
        }


        // last = var->list.elem;
        // if(last->type != AST_IDENT){
        //     /* get the name from the end */
        //     last = last_ptr(last);
        //     /* merge the two lists...erasing the ident part, but saving the name */
        //     if(last->type == AST_PTR){
        //         name = last->ptr.ptr_to->ident.ident;
        //         last->ptr.ptr_to = type;
        //     }else{
        //         name = last->array.ptr_to->ident.ident;
        //         last->array.ptr_to = type;
        //     }
        //     type = temp->list.elem;
        // } else {
        //     name = temp->list.elem->ident.ident;
        // }

        // SYM_ENT ent = alloc_sym_ent(name, ENT_VAR, NS_MISC);
        // ent->var.type = type;
        // if(!sym_enter(curr_scope, ent)){
        //     yyerror("error: redeclaration of variable\n");
        //     exit(-1);
        // }
        
        var_list = var_list->list.next;
    }

}

void print_sym_stack(SYM_TAB curr_scope){



}

void print_sym(SYM_TAB sym)
{
    SYM_ENT_LL temp = sym->ent_ll;
    while(temp != NULL){
        print_sym_ent(temp->entry);
        temp = temp->next;
    }

}



static void indent(int indent){
    for(int i = 0; i < indent*2; i++)
        putchar(' ');
}
void print_sym_ent(SYM_ENT ent)
{
    static int space = 0;

    /* need to fix this to account for the modified enum tags */
    switch(ent->att_type){
        case ENT_VAR:
            indent(space); fprintf(stdout, "%s:\n", ent->name);
            print_ast(ent->var.type);  /* list should be being passed to print_ast */
            putchar('\n');

            break;
    }

}