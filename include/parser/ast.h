#ifndef AST_H
#define AST_H

#include <stddef.h>

#include <common/def.h>
#include <common/char_util.h>
#include <parser.tab.h>
#include <parser/symtab.h>

/* Abstract Syntax Tree node types */
enum AST_TYPE{ 
    AST_UNARY=0, 
    AST_BINARY, 
    AST_TERNARY, 
    AST_IDENT, 
    AST_NUM, 
    AST_SIZEOF, 
    AST_FNCALL,
    AST_CHARLIT, 
    AST_STRING, 
    AST_SELECT,

    AST_TYPE,
    AST_SCALAR, 
    AST_PTR, 
    AST_ARRAY, 
    AST_ST_UN, 
    AST_STRUCT, 
    AST_UNION, 

    AST_FUNC, /* function definition/declaration*/

    AST_LIST, /* internal */

    AST_DECLARATION, 
    AST_DECL_SPEC, 
    AST_DECL_STG, 
    /* used for simplification not an acutal node type */
    AST_DECL_TYPE_SPEC, 
    AST_DECL_TYPE_QUALIF, 
    AST_DECL_FUNC_SPEC, 

    AST_COMPOUND, 

    AST_SELECT_STMNT,
    AST_IF_STMNT, 
    AST_SWITCH_STMNT, 

    AST_ITERAT_STMNT,
    AST_DO_STMNT, 
    AST_WHILE_STMNT, 
    AST_FOR_STMNT,

    AST_LABEL_STMNT, 
    AST_LABEL, 
    AST_LABEL_CASE, 
    AST_LABEL_DEFAULT,

    AST_JUMP_STMNT, 
    AST_GOTO, 
    AST_CONTINUE, 
    AST_BREAK, 
    AST_RETURN,

    AST_TEMP, /* assignment 5 temporary register */
    AST_BB_TEMP,
};

/* enum for binary types in ast */
enum AST_BIN_TYPE{BINOP=0, COMP, ASSIGN};


struct astnode_unary{
    int op;
    struct astnode *expr;
};

struct astnode_binary{
    int op;
    int op_type;
    struct astnode *left;
    struct astnode *right;
};

struct astnode_ternary{
    struct astnode *cond;
    struct astnode *true;
    struct astnode *false;
};

struct astnode_ident{
    char* ident;
    struct sym_entry *  entry;
};

struct astnode_charlit{
    char charlit;
};

struct astnode_string{
    char* string;
    size_t len;

    size_t ro_section; /* place in .rodata section */
};

struct astnode_num{
    int type;
    int sign;
    unsigned long long int_num;
    long double real;
};

struct astnode_fncall{
    struct astnode *name;
    int num_param;

    struct fncall_params{ /* linked list of params */
        struct astnode *param;
        struct fncall_params* next;
    } *params;
};

struct astnode_sizeof{
    struct astnode *expr;
};

/* from a struct/union dot op or idsel */
struct astnode_select{
    struct astnode *expr;
    struct astnode *tag;
};

/* meant to hold two lists: list of decl_spec and a list of declarators */
/* used as a temporary storage before the declaration gets processed */
struct astnode_declaration{
    struct astnode *var_type, *declaration;
};

struct astnode_type{ 
    int stg_class;
    int type_qualif; /* quietly ignore thoo */
    int type; /* either st_un or scalar */
    union{
        /* for structs */
        struct{
            struct astnode *st_un;
            // struct sym_entry *  def;
        };
        /* for scalars */
        struct{
            bool is_unsigned;
            int type_spec;
            bool is_inline;
        };
    };
    struct astnode *list; /* original list, good to have around... "for now" */
};

struct astnode_pointer{
    // struct astnode *spec;
    struct astnode *ptr_to;
};

struct astnode_array{
    // struct astnode *spec;
    struct astnode *ptr_to;
    struct astnode *size;
    // int size;
}; 

struct astnode_st_un{
    int type; 
    bool def_complete;
    char* name; /* if NULL then anonymous struct/union */
    struct symtab *mini_tab;
};

struct astnode_func{
    struct astnode *name; /* struct astnode *ident */
    struct astnode *ret;
    struct astnode *args; /* list of arguments */
    struct astnode *block;
    struct symtab *sym;  /* associated symbol table */
};

struct astnode_list{
    struct astnode *elem, *next;
};

struct astnode_decl_spec{
    int decl_spec;
    int type; /* type spec/qualif, func spec, storage class */
};

struct astnode_compound{
    struct astnode *states; /* list of statements */
    struct symtab *tab;
};

struct astnode_select_stmnt{
    int type; /* either an AST_IF_STMNT or AST_SWITCH_STMNT */
    struct astnode *cond, *then, *else_stmnt;
};

struct astnode_iterat_stmnt{
    int type; /* three types AST_DO_STMNT, AST_WHILE_STMNT, AST_FOR_STMNT */
    struct astnode *cond, *stmnt;
    /* only used for for-loops */
    struct astnode *init, *update;
};

struct astnode_label_stmnt{
    int type; /* goto label, case, switch */
    struct astnode *stmnt; 
    char* label; /* used for goto labels(meant store ident) */
    struct astnode *cond; /* used for case */
};

struct astnode_jump_stmnt{
    int type;
    char* goto_label;
    struct astnode *ret_expr;
};

struct astnode_temp{
    int temp;
};

struct astnode_bb_temp{
    char *func_name;
    int num;
    char full_name[16];
};

struct astnode{
    int type;
    union{
        /* assignment 2: expressions */
        struct astnode_unary        unary;
        struct astnode_binary       binary;
        struct astnode_ternary      ternary;
        struct astnode_ident        ident;
        struct astnode_num          num;
        struct astnode_charlit      charlit;
        struct astnode_string       string;
        struct astnode_fncall       fncall;
        struct astnode_sizeof       a_sizeof;
        struct astnode_select       select;
        struct astnode_list         list;

        /* assignment 3: declarations and functions (pain)*/
        struct astnode_type         var_type;
        struct astnode_declaration  declaration;
        struct astnode_decl_spec    decl_spec;
        struct astnode_pointer      ptr;
        struct astnode_array        array;
        struct astnode_func         func;
        struct astnode_st_un        st_un; /* struct_union */
        
        /* assignment 4: statements */
        struct astnode_compound     comp;
        struct astnode_select_stmnt select_stmnt;
        struct astnode_iterat_stmnt iterat_stmnt;
        struct astnode_label_stmnt  label_stmnt;
        struct astnode_jump_stmnt   jump_stmnt;

        /* assignment 5: quads */
        struct astnode_temp         temp;
        struct astnode_bb_temp      bb_temp;
    };
};

bool    ast_compare_type(struct astnode *t1, struct astnode *t2);
void    print_ast(struct astnode *ast);

/* helper functions for assignment three 3: expressions */
struct astnode *astnode_alloc(int ast_type);
struct astnode *alloc_unary(int op, struct astnode *expr);
struct astnode *alloc_binary(int type, struct astnode *val1, int op, struct astnode *val2);
struct astnode *alloc_ternary(struct astnode *cond, struct astnode *true, struct astnode *false);
struct astnode *alloc_and_expand_assignment(struct astnode *val1, int op, struct astnode *val2);
struct astnode *alloc_ident(char* ident);
struct astnode *alloc_num(unsigned long long int_num, long double real, int type, int sign);
struct astnode *alloc_charlit(char charlit);
struct astnode *alloc_string(char* string, int len);
struct astnode *alloc_fncall(struct astnode *name, struct astnode *params);
struct astnode *alloc_sizeof(struct astnode *expr);
struct astnode *alloc_select(struct astnode *expr, char* ident);
struct astnode *alloc_list(struct astnode *elem);

/* helper functions for dealing with lists */
struct astnode *list_last(struct astnode *list);
struct astnode *list_append_elem(struct astnode *elem, struct astnode *list);
struct astnode *list_append(struct astnode *list1, struct astnode *list2);
int     list_size(struct astnode *list);
struct astnode *next_ptr(struct astnode *ptr_chain);
struct astnode *last_ptr(struct astnode *ptr_chain);
struct astnode *list_to_ptr_chain(struct astnode *list);

/* new functions for assignment 3 */
struct astnode *alloc_type(struct astnode *decl_specs);
struct astnode *alloc_declaration(struct astnode *qualif, struct astnode *decl);
struct astnode *alloc_decl_spec(int decl_spec, int type);
struct astnode *alloc_ptr(struct astnode *ptr_to);
struct astnode *alloc_array(struct astnode *array_of, struct astnode *size);
struct astnode *alloc_st_un(int type, int scope);
struct astnode *alloc_func(struct astnode *name, struct astnode *arg_list);

/* new functions for assignment 4 */
struct astnode *alloc_compound(struct astnode *exprs, struct symtab *tab);
struct astnode *alloc_select_stmnt(int type, struct astnode *cond, struct astnode *then, struct astnode *else_stmnt);
struct astnode *alloc_iterat_stmnt(int type, struct astnode *cont, struct astnode *stmnt, struct astnode *init, struct astnode *update);
struct astnode *alloc_label_stmnt(int type, struct astnode *stmnt, char* label, struct astnode *cond);
struct astnode *alloc_jump_stmnt(int type, char* label, struct astnode *ret_expr);

struct astnode *alloc_temp(int temp_count);
struct astnode *alloc_bb_temp(char* func_name, int num);

#endif
