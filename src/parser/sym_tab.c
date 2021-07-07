#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <parser/symtab.h>

extern char filename[256];
extern int lineno;
extern void yyerror(const char* msg);
extern void yyerror_die(const char* msg);

extern int stack_offset;
extern bool in_func_declaration;
extern bool in_func;

extern struct symtab *curr_scope;

struct symtab *symtab_create(int scope_type)
{
    struct symtab *ret = calloc(1, sizeof(struct symtab));
    ret->scope_type = scope_type;
    return ret;
}

void symtab_destroy(struct symtab *symtab)
{
    /* figure this out later: I have 32G of RAM, so I don't care :^) */
    free(symtab);
}

struct symtab *symtab_push(int scope_type, struct symtab *symtab)
{
    struct symtab *new_tab = symtab_create(scope_type);
    new_tab->next = symtab;
    return new_tab;
}

struct symtab *symtab_push_on(struct symtab *curr_scope, struct symtab *new)
{
    new->next = curr_scope;
    return new;
}

struct symtab *symtab_pop(struct symtab *stack)
{
    /* free current scope? ... probably not... */
    return stack->next;
}

bool sym_ent_compare(struct sym_entry *  ent1, struct sym_entry *  ent2)
{
    if(!strcmp(ent1->name, ent2->name) && ent1->namespace == ent2->namespace){
        return true;
    }

    return false;
}

/* returns the entry in the symbol table if present. ELSE returns NULL */
struct sym_entry *  sym_lookup(struct symtab *sym, struct sym_entry *  ent)
{
    struct symtab *temp_sym = sym;
    struct sym_entries *  temp_ent_ll;

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
struct sym_entry *  sym_lookup_local(struct symtab *sym, struct sym_entry *  ent)
{
    struct sym_entries *  temp_ent_ll = sym->ent_ll;
    /* loop through symbol table entries */
    while(temp_ent_ll != NULL){
        if(temp_ent_ll->entry != NULL && sym_ent_compare(temp_ent_ll->entry, ent)) 
            return temp_ent_ll->entry;

        temp_ent_ll = temp_ent_ll->next;
    }

    return NULL;
}

/* TRUE: successfully entered entry | FALSE: already there */
bool sym_enter(struct symtab *sym, struct sym_entry *  ent)
{
    struct sym_entry *  temp;
    if((temp = sym_lookup_local(sym, ent)))
    {
        /* allow same variable redeclaration in Global Scope */
        if(sym->scope_type == SCOPE_GLOBAL && ent->att_type == ENT_VAR)
            if(ast_compare_type(temp->var.type, ent->var.type))
                return true;

        return false;
    } 

    struct sym_entries *  temp_ent_ll = calloc(sizeof(struct sym_entries),1);
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


struct sym_entry *alloc_sym_ent(char* name, int ent_type, int ent_ns)
{
    struct sym_entry *  ret = calloc(sizeof(struct sym_entry),1);
    ret->name = name;
    ret->namespace = ent_ns;
    ret->att_type = ent_type;

    ret->filename = strdup(filename);
    ret->lineno = lineno;
    return ret;
}

/* 
 * function that declares a list of variables with their corresponding declarators 
 * and enteres the variables into the symbol table. This function takes two lists
 * type: list of decl_specs|| var_list: list of decalrators 
 */
void sym_declaration(struct astnode *declaration, struct symtab *tab)
{
    struct astnode *type = declaration->declaration.var_type;
    struct astnode *var_list = declaration->declaration.declaration;
    struct astnode *ptr_chain, *var;

    int is_var = false;

    /* loops over the list of idents in ex. int a,b,c; */
    while(var_list != NULL)
    {
        char *name;
        var = var_list->list.elem;
        /*  
            name of variable is the fist element, as a result of grammar structure 
            but in a different place for function declarations and regular function declarations
            because, c doesn't allow int func(int a,b,c) {...} 
        */
        if(var->type == AST_IDENT){
            /* being in this state implies that this is a function declaration */
            name = var->ident.ident;
            var = var_list;
        }else{
            name = var->list.elem->ident.ident;
            is_var = true;
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

        /* as per the standard register or auto storage specifier is invalid in the gloabl scope */
        if(is_var && tab->scope_type == SCOPE_GLOBAL){
            switch(type->var_type.stg_class){
                case STG_AUTO:
                case STG_REGISTER:
                    yyerror_die("invalid storage specifer in global scope");
            }
        }

        /* enter variable into the provided symbol table */
        struct sym_entry *  ent = alloc_sym_ent(name, ENT_VAR, NS_MISC);
        ent->var.type = ptr_chain;
        if(!sym_enter(tab, ent)){
            yyerror_die("error: redeclaration of variable\n");
        }

        /* setting stack offset */
        if (in_func_declaration) {
            ent->var.offset = stack_offset;
            ent->var.is_local = true;
        } else if(curr_scope->scope_type != SCOPE_GLOBAL) {
            ent->var.offset = stack_offset;
            stack_offset -= 4;
            ent->var.is_local = true;
        }

        if(var_list->list.elem->type != AST_LIST)
            return;

        var_list = var_list->list.next;
    }
}

void sym_struct_define(struct astnode *st_un, struct astnode *decl_list)
{
    st_un->st_un.def_complete = true;
    /* place holder nodes for readability */
    struct astnode *var_type, *declaration;
    while(decl_list != NULL){
        var_type = decl_list->list.elem->declaration.var_type;
        declaration = decl_list->list.elem->declaration.declaration;

        sym_declaration(alloc_declaration(var_type, declaration), st_un->st_un.mini_tab);
        decl_list = decl_list->list.next;
    }
}

void sym_struct_declare(char* name, struct astnode *st_un, struct symtab *tab)
{
    st_un->st_un.name = name;
    struct sym_entry *  ent = alloc_sym_ent(name, ENT_SU_TAG, NS_SU);
    ent->name = name;
    ent->su_tag.st_un = st_un;

    /* if a struct/union is defined in ANOTHER struct/union, get out of it */
    while(tab->scope_type == SCOPE_MINI) tab = tab->next;
    if(!sym_enter(tab, ent)){
        yyerror_die("error: redeclaration of variable\n");
    }
}

/* insert label into the function scope */
void sym_label(struct astnode *label, struct symtab *tab)
{
    while(tab->scope_type != SCOPE_FUNC) tab = tab->next;

    if(!sym_enter(tab, alloc_sym_ent(label->label_stmnt.label, ENT_STMNT_LABEL, NS_LABEL))){
        yyerror_die("redeclaration of label\n");
    }

}

void sym_func_def(struct astnode *func_def, struct symtab *tab)
{
    if(tab->scope_type != SCOPE_GLOBAL){
        yyerror_die("function definition not in global scope");
    }

    struct sym_entry *  ent = alloc_sym_ent(func_def->func.name->ident.ident, ENT_FUNC, NS_MISC);
    ent->func.stg_class = STG_EXTERN;
    ent->func.def_seen = true;
    ent->func.inline_spec = false;
    ent->func.func_def = func_def;
    
    /* enter function definition into symbol table */
    if(!sym_enter(tab, ent)){
        yyerror_die("error: redeclaration of variable\n");
    }
}
