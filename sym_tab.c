#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_tab.h"

extern char filename[256];
extern int lineno;
extern void yyerror(const char* msg);

SYM_TAB sym_tab_create(int scope_type){
    SYM_TAB ret = calloc(1, sizeof(struct sym_tab));
    ret->scope_type = scope_type;
    return ret;
}

void sym_tab_destroy(SYM_TAB sym_tab){
    /* figure this out later: I have 32G of RAM, so I don't care :^) */
    free(sym_tab);
}

SYM_TAB sym_tab_push(int scope_type, SYM_TAB sym_tab){
    SYM_TAB new_tab = sym_tab_create(scope_type);
    new_tab->next = sym_tab;
    return new_tab;
}

SYM_TAB sym_tab_pop(SYM_TAB stack){
    /* free current scope? ... probably not... */
    return stack->next;
}

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


/* TRUE: successfully entered entry | FALSE: already there */
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


SYM_ENT alloc_sym_ent(char* name, int ent_type, int ent_ns)
{
    SYM_ENT ret = calloc(sizeof(struct sym_entry),1);
    ret->name = name;
    ret->namespace = ent_ns;
    ret->att_type = ent_type;

    ret->filename = strdup(filename);
    ret->lineno = lineno;
    return ret;
}

/** 
 * function that declares a list of variables with their corresponding declarators 
 * and enteres the variables into the symbol table. This function takes two lists
 * type: list of decl_specs|| var_list: list of decalrators 
 */
void sym_declaration(ASTNODE declaration, SYM_TAB tab)
{
    ASTNODE type = declaration->declaration.qualif;
    ASTNODE var_list = declaration->declaration.declaration;
    ASTNODE ptr_chain, var;
    while(var_list != NULL)
    {
        var = var_list->list.elem;
        char *name;

        /* name of variable is the fist element, as a result of grammar structure */
        name = var->list.elem->ident.ident;

        /* check if there is to the declaration */
        if(var->list.next != NULL){
            /* skipping over ident */
            var = var->list.next;
            ptr_chain = list_to_ptr_chain(var);

            /* add type to the end of the ptr_chain */
            var = last_ptr(ptr_chain);
            if(var->type == AST_PTR){
                var->ptr.ptr_to = type;
            }else if(var->type == AST_ARRAY){
                var->array.ptr_to = type;
            }
        } else {
            ptr_chain = type;
        }

        SYM_ENT ent = alloc_sym_ent(name, ENT_VAR, NS_MISC);
        ent->var.type = ptr_chain;
        if(!sym_enter(tab, ent)){
            yyerror("error: redeclaration of variable\n");
            exit(-1);
        }
        var_list = var_list->list.next;
    }
}

void sym_struct_define(ASTNODE st_un, ASTNODE decl_list)
{
    st_un->st_un.def_complete = true;
    /* place holder nodes for readability */
    ASTNODE qualif, declaration;
    while(decl_list != NULL){
        qualif = decl_list->list.elem->declaration.qualif;
        declaration = decl_list->list.elem->declaration.declaration;

        /* TO DO: in sym_declaration make sure to figure out the symbol table and enter the appropriate namespace */
        sym_declaration(alloc_declaration(qualif, declaration), st_un->st_un.mini_tab);
        decl_list = decl_list->list.next;
    }
}

void sym_struct_declare(char* name, ASTNODE st_un, SYM_TAB tab)
{
    st_un->st_un.name = name;
    SYM_ENT ent = alloc_sym_ent(name, ENT_SU_TAG, NS_SU);
    ent->name = name;
    ent->su_tag.st_un = st_un;
    if(!sym_enter(tab, ent)){
        yyerror("error: redeclaration of variable\n");
        exit(-1);
    }
}

void sym_func_def(ASTNODE func_def, SYM_TAB tab){
    if(tab->scope_type != SCOPE_GLOBAL){
        yyerror("function definition not in global scope");
        exit(-1);
    }

    SYM_ENT ent = alloc_sym_ent(func_def->func.name->ident.ident, ENT_FUNC, NS_MISC);
    ent->func.stg_class = STG_EXTERN;
    ent->func.def_seen = true;
    ent->func.inline_spec = false;
    ent->func.func_def = func_def;
    
    if(!sym_enter(tab, ent)){
        yyerror("error: redeclaration of variable\n");
        exit(-1);
    }
}