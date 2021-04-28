#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_tab.h"

extern char filename[256];
extern int lineno;
extern void yyerror(const char* msg);
extern void yyerror_die(const char* msg);

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

SYM_TAB sym_tab_push_on(SYM_TAB curr_scope, SYM_TAB new){
    new->next = curr_scope;
    return new;
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

/* does not go down the stack of symbol tables but only looks at the provided one */
SYM_ENT sym_lookup_local(SYM_TAB sym, SYM_ENT ent)
{
    SYM_ENT_LL temp_ent_ll = sym->ent_ll;
    /* loop through symbol table entries */
    while(temp_ent_ll != NULL){
        if(temp_ent_ll->entry != NULL && sym_ent_compare(temp_ent_ll->entry, ent)) 
            return temp_ent_ll->entry;

        temp_ent_ll = temp_ent_ll->next;
    }

    return NULL;
}

/* TRUE: successfully entered entry | FALSE: already there */
bool sym_enter(SYM_TAB sym, SYM_ENT ent)
{
    SYM_ENT temp;
    if((temp = sym_lookup_local(sym, ent)))
    {
        /* allow same variable redeclaration in Global Scope */
        if(sym->scope_type == SCOPE_GLOBAL && ent->att_type == ENT_VAR)
            if(ast_compare_type(temp->var.type, ent->var.type))
                return true;

        return false;
    } 

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
    ASTNODE type = declaration->declaration.var_type;
    ASTNODE var_list = declaration->declaration.declaration;
    ASTNODE ptr_chain, var;

    /* loops over the list of idents in ex. int a,b,c; */
    while(var_list != NULL)
    {
        char *name;
        var = var_list->list.elem;
        /*  name of variable is the fist element, as a result of grammar structure 
            but in a different place for function declarations and regular function declarations
            because, c doesn't allow int func(int a,b,c) {...} */
        if(var->type == AST_IDENT){
            /* being in this state implies that this is a function declaration */
            name = var->ident.ident;
            var = var_list;
        }else{
            name = var->list.elem->ident.ident;
        }

        /* now create pointer chain ex. int *a[2]; ==> [2] -> * -> int */
        /* check if there are declarators in the declaration and create pointer chain */
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
            yyerror_die("error: redeclaration of variable\n");
        }

        if(var_list->list.elem->type != AST_LIST)
            return;

        var_list = var_list->list.next;
    }
}

void sym_struct_define(ASTNODE st_un, ASTNODE decl_list)
{
    st_un->st_un.def_complete = true;
    /* place holder nodes for readability */
    ASTNODE var_type, declaration;
    while(decl_list != NULL){
        var_type = decl_list->list.elem->declaration.var_type;
        declaration = decl_list->list.elem->declaration.declaration;

        sym_declaration(alloc_declaration(var_type, declaration), st_un->st_un.mini_tab);
        decl_list = decl_list->list.next;
    }
}

void sym_struct_declare(char* name, ASTNODE st_un, SYM_TAB tab)
{
    st_un->st_un.name = name;
    SYM_ENT ent = alloc_sym_ent(name, ENT_SU_TAG, NS_SU);
    ent->name = name;
    ent->su_tag.st_un = st_un;

    /* if a struct/union is defined in ANOTHER struct/union, get out of it */
    while(tab->scope_type == SCOPE_MINI) tab = tab->next;
    if(!sym_enter(tab, ent)){
        yyerror_die("error: redeclaration of variable\n");
    }
}

void sym_func_def(ASTNODE func_def, SYM_TAB tab)
{
    if(tab->scope_type != SCOPE_GLOBAL){
        yyerror_die("function definition not in global scope");
    }

    SYM_ENT ent = alloc_sym_ent(func_def->func.name->ident.ident, ENT_FUNC, NS_MISC);
    ent->func.stg_class = STG_EXTERN;
    ent->func.def_seen = true;
    ent->func.inline_spec = false;
    ent->func.func_def = func_def;
    
    /* enter function definition into symbol table */
    if(!sym_enter(tab, ent)){
        yyerror_die("error: redeclaration of variable\n");
    }
}
