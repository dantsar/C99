#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/def.h>
#include <parser/ast.h>

extern void yyerror(const char* msg);
extern void yyerror_die(const char* msg);

/* kludge for setting stack offsets */
bool in_func_declaration;
int stack_offset;

/* compares the whole variable, including pointer chain */
bool ast_compare_type(struct astnode *t1, struct astnode *t2)
{
    struct astnode *temp;
    if(t1 == NULL && t2 == NULL) return true; /* should be error? ¯\_(ツ)_/¯ */
    /* there is probably a more elegant method, but don't care! */
    do{
        /* compare type: should only be of three types: 
           AST_PTR, AST_ARRAY, or AST_TYPE */
        if(t1->type == t2->type){
            if(t1->type == AST_TYPE){
                /* compare types of variable */
                if(t1->var_type.stg_class != t2->var_type.stg_class) return false;
                if(t1->var_type.type_qualif != t2->var_type.type_qualif) return false;
                if(t1->var_type.type != t2->var_type.type) return false;
                if(t1->var_type.type == AST_ST_UN){
                    /* only compare struct names */
                    if(strcmp(t1->var_type.st_un->st_un.name, t2->var_type.st_un->st_un.name)) return false;
                } else { 
                    if(t1->var_type.is_unsigned != t2->var_type.is_unsigned) return false;
                    if(t1->var_type.type_spec != t2->var_type.type_spec) return false;
                    if(t1->var_type.is_inline != t2->var_type.is_inline) return false;
                }
            }
        } else {
            return false;
        }
    }while((t1 = next_ptr(t1)) && (t2 = next_ptr(t2)));

    return true;
}

struct astnode *astnode_alloc(int astnode_type)
{
    struct astnode *ret = calloc(1, sizeof(struct astnode));
    ret->type = astnode_type;
    return ret;
}

struct astnode *alloc_num(unsigned long long int_num, long double real, int type, int sign)
{
    struct astnode *ret = astnode_alloc(AST_NUM);
    ret->num.int_num = int_num;
    ret->num.real = real;
    ret->num.type = type;
    ret->num.sign = sign;
    return ret;
}

struct astnode *alloc_unary(int op, struct astnode *expr)
{
    struct astnode *ret = astnode_alloc(AST_UNARY);
    ret->unary.op = op;
    ret->unary.expr = expr;
    return ret;
}

struct astnode *alloc_binary(int type, struct astnode *val1, int op, struct astnode *val2)
{
    struct astnode *ret = astnode_alloc(AST_BINARY);
    ret->binary.op = op;
    ret->binary.op_type = type;
    ret->binary.left = val1;
    ret->binary.right = val2;
    return ret;
}

struct astnode *alloc_ternary(struct astnode *cond, struct astnode *true, struct astnode *false)
{
    struct astnode *ret = astnode_alloc(AST_TERNARY);
    ret->ternary.cond = cond;
    ret->ternary.true = true;
    ret->ternary.false = false;
    return ret;
}

struct astnode *alloc_and_expand_assignment(struct astnode *val1, int op, struct astnode *val2)
{
    struct astnode *ret1 = alloc_binary(BINOP, val1, op, val2);
    struct astnode *ret2 = alloc_binary(ASSIGN, val1, '=', ret1);
    return ret2;
}

struct astnode *alloc_ident(char *ident)
{
    struct astnode *ret = astnode_alloc(AST_IDENT);
    ret->ident.ident = ident;
    return ret;
}

struct astnode *alloc_charlit(char charlit)
{
    struct astnode *ret = astnode_alloc(AST_CHARLIT);
    ret->charlit.charlit = charlit;
    return ret;
}

struct astnode *alloc_string(char* string, int len)
{
    struct astnode *ret = astnode_alloc(AST_STRING);
    ret->string.string = string;
    ret->string.len = len;
    return ret;
}

/* params is assumed to be a binop astnode */
/* unnecessarily complicated... will be replaced with ast_list and append...*/
struct astnode *alloc_fncall(struct astnode *name, struct astnode *params)
{
    struct astnode *ast_ret = astnode_alloc(AST_FNCALL);
    ast_ret->fncall.name = name;
    if(params == NULL){
        ast_ret->fncall.num_param = 0;
        return ast_ret;
    }

    /* temporary variables */
    struct fncall_params *list,*temp;
    struct astnode *ast_temp = params;

    list = malloc(sizeof(struct fncall_params));
    list->next = NULL;

    int count;
    for(count = 1; ast_temp->binary.op == ','; count++){
        list->param = ast_temp->binary.right;
        temp = malloc(sizeof(struct fncall_params));
        temp->next = list;
        list = temp;

        ast_temp = ast_temp->binary.left;
    }
    list->param = ast_temp;

    ast_ret->fncall.num_param = count;
    ast_ret->fncall.params = list;
    return ast_ret;
}

struct astnode *alloc_sizeof(struct astnode *expr)
{
    struct astnode *ret = astnode_alloc(AST_SIZEOF);
    ret->a_sizeof.expr = expr;
    return ret;
}

struct astnode *alloc_select(struct astnode *expr, char* ident)
{
    struct astnode *tag = astnode_alloc(AST_IDENT);
    tag->ident.ident = ident;

    struct astnode *ret = astnode_alloc(AST_SELECT);
    ret->select.expr = expr;
    ret->select.tag = tag;
    return ret;
}

struct astnode *alloc_list(struct astnode *elem)
{
    // if(elem == NULL) return NULL;
    struct astnode *ret = astnode_alloc(AST_LIST);
    ret->list.elem = elem;
    ret->list.next = NULL;
    return ret;
}

/* next pointer in pointer chain: eg next array or actual pointer */
struct astnode *next_ptr(struct astnode *ptr_chain)
{
    if(ptr_chain->type == AST_PTR){
        return ptr_chain->ptr.ptr_to;
    }else if(ptr_chain->type == AST_ARRAY){
        return ptr_chain->array.ptr_to;
    } 
    return NULL;
}

/* last ptr/array in chain */
struct astnode *last_ptr(struct astnode *ptr_chain)
{
    if(!ptr_chain) return NULL;

    struct astnode *last_elem;
    while(ptr_chain != NULL && (ptr_chain->type == AST_PTR || ptr_chain->type == AST_ARRAY)){
        last_elem = ptr_chain;
        if(ptr_chain->type == AST_PTR){
            ptr_chain = ptr_chain->ptr.ptr_to;
        }else if(ptr_chain->type == AST_ARRAY){
            ptr_chain = ptr_chain->array.ptr_to;
        } 
    }
    return last_elem;
}

/* might destroy the list... again, memory managment is a meme :^) */
struct astnode *list_to_ptr_chain(struct astnode *list)
{
    /* check if is not NULL, or else a bad time... */
    if(list == NULL) return NULL;

    int type = list->list.elem->type;
    struct astnode *ptr_chain = list->list.elem; // = list->list.elem;
    struct astnode *ret = ptr_chain; /* head of pointer chain */

    list = list->list.next;
    while(list != NULL){

        if(type == AST_PTR){
            ptr_chain->ptr.ptr_to = list->list.elem;
        }else if(type == AST_ARRAY){
            ptr_chain->array.ptr_to = list->list.elem;
        }

        /* type of previous node in ptr_chain */
        ptr_chain = list->list.elem;
        type = list->list.elem->type;
        list = list->list.next;
    }

    return ret;
}

/* get the last element of a list */
struct astnode *list_last(struct astnode *list)
{
    while(list->list.next != NULL)
        list = list->list.next;
    return list;
}

/* add an astnode to the end of list */
struct astnode *list_append_elem(struct astnode *elem, struct astnode *list)
{
    if(elem == NULL) return NULL;
    if(list == NULL)
        return alloc_list(elem);

    struct astnode *temp = list;
    struct astnode *new_elem = alloc_list(elem); 
    while(temp->list.next != NULL) temp = temp->list.next; /* go to last elem */
    temp->list.next = new_elem;
    return list;
}

/* append list1 to list2 (list2 -> list1) */
struct astnode *list_append(struct astnode *list1, struct astnode *list2)
{
    if(list1 == NULL || list2 == NULL) 
        return NULL;
    struct astnode *ret = list2;
    list2 = list_last(list2);
    list2->list.next = list1;
    return ret;
}

/* mainly for debugging for now */
int list_size(struct astnode *list)
{
    int count = 0;
    while(list!= NULL){
        count++;
        list = list->list.next;
    }
    return count;
}

struct astnode *alloc_type(struct astnode *decl_specs)
{
    struct astnode *ret = astnode_alloc(AST_TYPE);
    int long_count = 0;
    bool def_int = true; /* used to throw error if long is found after "non long declaration" (ex char, or short), a KLUDGE */

    /* a lot of tabs, but don't care! */
    /* very not elegant, there IS a more elegant way, but I don't have the brain power right now */
    struct astnode *temp = decl_specs;
    while(temp != NULL)
    {
        decl_specs = temp->list.elem;

        if(decl_specs->type == AST_ST_UN)
        {
            if(ret->var_type.type != 0){
                yyerror_die("invalid struct/union variable declaration");
            }
            ret->var_type.type = AST_ST_UN;
            ret->var_type.st_un = decl_specs;

            temp = temp->list.next;
            continue;
        }
        if(ret->var_type.type == AST_ST_UN)
            yyerror_die("incorrect variable declaration, struct/union and type specifiers found");

        /* relatively harmless assumption */
        switch(decl_specs->decl_spec.type)
        {
            case AST_DECL_STG:
                if(ret->var_type.stg_class != 0){
                    yyerror_die("too many storage types in variable declaration");
                }
                ret->var_type.stg_class = decl_specs->decl_spec.decl_spec;
                break;
            case AST_DECL_TYPE_QUALIF:
                /* Quietly ignore... that's right! go crazy with them, I don't care! I'll just take one */
                switch(decl_specs->decl_spec.decl_spec)
                { 
                    case QUALIF_CONST:       ret->var_type.type_qualif = QUALIF_CONST; break;
                    case QUALIF_RESTRICT:    ret->var_type.type_qualif = QUALIF_RESTRICT; break;
                    case QUALIF_VOLATILE:    ret->var_type.type_qualif = QUALIF_VOLATILE; break;
                }
                break;
            case AST_DECL_FUNC_SPEC:
                ret->var_type.is_inline = true;
                /* error? ¯\_(ツ)_/¯ */
                break;
            case AST_DECL_TYPE_SPEC:
                ret->var_type.type = AST_SCALAR;
                switch(decl_specs->decl_spec.decl_spec) /* what a tongue twister */
                { 
                    case TYPE_UNSIGNED: /* won't handle the case "unsigned unsigned" (I'll just pretend that it's just unsigned) */
                        fprintf(stdout, "HUZZAH\n");
                        ret->var_type.is_unsigned = true; /* not really necessary but ¯\_(ツ)_/¯ what the heck */
                        break;
                    case TYPE_LONG:
                        if(long_count == 0){
                            // def_int = true;
                            ret->var_type.type_spec = TYPE_LONG;
                            long_count++;
                        }else if(long_count == 1){
                            ret->var_type.type_spec = TYPE_LLONG;
                            long_count++;
                        }else{
                            yyerror_die("too many long specifiers in variable declaration");
                        }

                        if(ret->var_type.type_spec == TYPE_LDOUBLE){
                            yyerror_die("too many long specifiers in variable declaration");
                        }else if(ret->var_type.type_spec == TYPE_DOUBLE){
                            ret->var_type.type_spec = TYPE_LDOUBLE;
                        } else if(def_int == false){
                            yyerror_die("invalid type specifiers variable declaration");
                        }
                        break;
                    case TYPE_DOUBLE:
                        if(long_count == 1)
                            ret->var_type.type_spec = TYPE_LDOUBLE;
                        else if(long_count == 2){
                            yyerror_die("too many long specifiers in variable declaration for declaring double");
                        } else 
                            ret->var_type.type_spec = TYPE_LDOUBLE;
                        break; 
                    case TYPE_INT:
                        if(long_count != 0)
                            break;

                        ret->var_type.type_spec = TYPE_INT;
                        break; 
                    case TYPE_CHAR:
                        if(long_count != 0)
                            yyerror_die("conflicting types in variable declaration because of long");

                        ret->var_type.type_spec = TYPE_CHAR;
                        break; 
                    default:
                        if(long_count != 0){
                            yyerror_die("conflicting types in variable declaration because of long");
                        } else if(ret->var_type.type_spec != 0){
                            yyerror_die("conflicting types in variable declaration");
                        }
                        def_int = false;
                        ret->var_type.type_spec = decl_specs->decl_spec.decl_spec;
                        break; 
                }
                break;
        }
        temp = temp->list.next;
    }
    return ret;
}

struct astnode *alloc_declaration(struct astnode *qualif, struct astnode *decl)
{
    struct astnode *ret = astnode_alloc(AST_DECLARATION);
    ret->declaration.declaration = decl;
    if(qualif->type == AST_LIST){
        ret->declaration.var_type = alloc_type(qualif);
    } else {
        ret->declaration.var_type = qualif;
    }
    return ret;
}

struct astnode *alloc_decl_spec(int decl_spec, int type)
{
    struct astnode *ret = astnode_alloc(AST_DECL_SPEC);
    ret->decl_spec.decl_spec = decl_spec;
    ret->decl_spec.type = type;
    return ret;
}

struct astnode *alloc_ptr(struct astnode *ptr_to)
{
    struct astnode *ret = astnode_alloc(AST_PTR);
    ret->ptr.ptr_to = ptr_to;
    return ret;
}

struct astnode *alloc_array(struct astnode *array_of, struct astnode *size)
{
    struct astnode *ret = astnode_alloc(AST_ARRAY);
    ret->array.ptr_to = array_of;
    /* assuming arrays are only defined as constants of unknown */
    if(size)
        ret->array.size = size;
    else 
        ret->array.size = NULL; /* indicates a VLA: this shouldn't be reachable, but just in case */
    return ret;
}

struct astnode *alloc_st_un(int type, int scope)
{
    struct astnode *ret = astnode_alloc(AST_ST_UN);
    ret->st_un.type = type;
    ret->st_un.mini_tab = sym_tab_create(SCOPE_MINI);
    ret->st_un.def_complete = false;
    return ret; 
}

struct astnode *alloc_func(struct astnode *name, struct astnode *arg_list)
{
    struct astnode *ret = astnode_alloc(AST_FUNC);
    /* really should be a prototype scope, but I'm not worrying about that */
    ret->func.sym = sym_tab_create(SCOPE_FUNC); 
    ret->func.name = name;
    ret->func.args = arg_list;

    /* enter arguments into the function's symbol table */
    struct sym_entry *  ent;

    /* horror: hard coding size for stack offset */
    in_func_declaration = true;
    stack_offset = 8;
    while(arg_list != NULL)
    {
        /* kludge for setting stack offsets*/
        sym_declaration(arg_list->list.elem, ret->func.sym);
        stack_offset += 4;
        arg_list = arg_list->list.next;
    }
    in_func_declaration = false;
    stack_offset = -8;
    return ret;
}

struct astnode *alloc_compound(struct astnode *exprs, struct sym_tab *tab)
{
    struct astnode *ret = astnode_alloc(AST_COMPOUND);
    ret->comp.states = exprs;
    ret->comp.tab = tab;
    return ret;
}

struct astnode *alloc_select_stmnt(int type, struct astnode *cond, 
                                   struct astnode *then, struct astnode *else_stmnt)
{
    struct astnode *ret = astnode_alloc(AST_SELECT_STMNT);
    ret->select_stmnt.type = type;
    ret->select_stmnt.cond = cond;
    ret->select_stmnt.then = then;
    ret->select_stmnt.else_stmnt = else_stmnt;
    return ret;
}

struct astnode *alloc_iterat_stmnt(int type, struct astnode *cond, struct astnode *stmnt, 
                                   struct astnode *init, struct astnode *update)
{
    struct astnode *ret = astnode_alloc(AST_ITERAT_STMNT);
    ret->iterat_stmnt.type = type;
    ret->iterat_stmnt.cond = cond;
    ret->iterat_stmnt.stmnt = stmnt;
    ret->iterat_stmnt.init = init;
    ret->iterat_stmnt.update = update;
    return ret;
}

struct astnode *alloc_label_stmnt(int type, struct astnode *stmnt, char* label, 
                                  struct astnode *cond)
{
    struct astnode *ret = astnode_alloc(AST_LABEL_STMNT);
    ret->label_stmnt.type = type;
    ret->label_stmnt.stmnt = stmnt;
    ret->label_stmnt.label = label; 
    ret->label_stmnt.cond = cond;
    return ret;
}

struct astnode *alloc_jump_stmnt(int type, char* label, struct astnode *ret_expr)
{
    struct astnode *ret = astnode_alloc(AST_JUMP_STMNT);
    ret->jump_stmnt.type = type;
    ret->jump_stmnt.goto_label = label;
    ret->jump_stmnt.ret_expr = ret_expr;
    return ret;
}

struct astnode *alloc_temp(int temp_count)
{
    struct astnode *ret = astnode_alloc(AST_TEMP);
    ret->temp.temp = temp_count;
    return ret;
}

struct astnode *alloc_bb_temp(char* func_name, int num)
{
    struct astnode *ret = astnode_alloc(AST_BB_TEMP);
    ret->bb_temp.func_name = func_name;
    ret->bb_temp.num = num;
    snprintf(ret->bb_temp.full_name, 
             sizeof(ret->bb_temp.full_name), 
             ".BB.%s.%d",
             func_name,
             num);
    return ret;
}
