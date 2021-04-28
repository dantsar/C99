#ifndef AST_H
#define AST_H

#include "def.h"
#include "char_util.h"
#include "parser.tab.h"
#include "sym_tab.h"

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
    AST_FUNC, 
    AST_LIST, 
    AST_DECLARATION, 
    AST_DECL_SPEC, 
    AST_DECL_STG, AST_DECL_TYPE_SPEC, AST_DECL_TYPE_QUALIF, AST_DECL_FUNC_SPEC, /* used for simplification not an acutal node type */
    AST_COMPOUND, 
    AST_SELECT_STMNT,
    AST_IF_STMNT, 
    AST_SWITCH_STMNT, 
    AST_ITERAT_STMNT,
    AST_DO_STMNT, 
    AST_WHILE_STMNT, 
    AST_FOR_STMNT,
    AST_LABEL_STMNT, 
    AST_LABEL, AST_LABEL_CASE, AST_LABEL_DEFAULT,
    AST_JUMP_STMNT, 
    AST_GOTO, 
    AST_CONTINUE, 
    AST_BREAK, 
    AST_RETURN,
    AST_TEMP /* assignment 5 temporary register */
};

/* enum for binary types in ast */
enum AST_BIN_TYPE{BINOP=0, COMP, ASSIGN};


struct astnode_unary{
    int op;
    ASTNODE expr;
};

struct astnode_binary{
    int op;
    int op_type;
    ASTNODE left;
    ASTNODE right;
};

struct astnode_ternary{
    ASTNODE cond;
    ASTNODE true;
    ASTNODE false;
};

struct astnode_ident{
    char* ident;
    SYM_ENT entry;
};

struct astnode_charlit{
    char charlit;
};

struct astnode_string{
    char* string;
    int len;
};

struct astnode_num{
    int type;
    int sign;
    unsigned long long int_num;
    long double real;
};

struct astnode_fncall{
    ASTNODE name;
    int num_param;

    struct fncall_params{ /* linked list of params */
        ASTNODE param;
        struct fncall_params* next;
    } *params;
};

struct astnode_sizeof{
    ASTNODE expr;
};

/* from a struct/union dot op or idsel */
struct astnode_select{
    ASTNODE expr;
    ASTNODE tag;
};

/* meant to hold two lists: list of decl_spec and a list of declarators */
/* used as a temporary storage before the declaration gets processed */
struct astnode_declaration{
    ASTNODE var_type, declaration;
};

struct astnode_type{ 
    int stg_class;
    int type_qualif; /* quietly ignore thoo */
    int type; /* either st_un or scalar */
    union{
        /* for structs */
        struct{
            ASTNODE st_un;
            // SYM_ENT def;
        };
        /* for scalars */
        struct{
            bool is_unsigned;
            int type_spec;
            bool is_inline;
        };
    };
    ASTNODE list; /* original list, good to have around... "for now" */
};

struct astnode_pointer{
    // ASTNODE spec;
    ASTNODE ptr_to;
};

struct astnode_array{
    // ASTNODE spec;
    ASTNODE ptr_to;
    ASTNODE size;
    // int size;
}; 

struct astnode_st_un{
    int type; 
    bool def_complete;
    char* name; /* if NULL then anonymous struct/union */
    SYM_TAB mini_tab;
};

struct astnode_func{
    ASTNODE name; /* ASTNODE ident */
    ASTNODE ret;
    ASTNODE args; /* list of arguments */
    ASTNODE block;
    SYM_TAB sym;  /* associated symbol table */
};

struct astnode_list{
    ASTNODE elem, next;
};

struct astnode_decl_spec{
    int decl_spec;
    int type; /* type spec/qualif, func spec, storage class */
};

struct astnode_compound{
    ASTNODE states; /* list of statements */
    SYM_TAB tab;
};

struct astnode_select_stmnt{
    int type; /* either an AST_IF_STMNT or AST_SWITCH_STMNT */
    ASTNODE cond, then, else_stmnt;
};

struct astnode_iterat_stmnt{
    int type; /* three types AST_DO_STMNT, AST_WHILE_STMNT, AST_FOR_STMNT */
    ASTNODE cond, stmnt;
    /* only used for for-loops */
    ASTNODE init, update;
};

struct astnode_label_stmnt{
    int type; /* goto label, case, switch */
    ASTNODE stmnt; 
    char* label; /* used for goto labels(meant store ident) */
    ASTNODE cond; /* used for case */
};

struct astnode_jump_stmnt{
    int type;
    char* goto_label;
    ASTNODE ret_expr;
};

// struct astnode_temp{
//     int temp_count;
// };

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
        int                         temp;
    };
};

bool ast_compare_type(ASTNODE t1, ASTNODE t2);
/* TO DO: FIX alloc_num, alloc_str to not be so verbose and accept struct num && struct str */
void print_ast(ASTNODE ast);
/* helper functions for assignment three 3: expressions */
ASTNODE astnode_alloc(int ast_type);
ASTNODE alloc_unary(int op, ASTNODE expr);
ASTNODE alloc_binary(int type, ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_ternary(ASTNODE cond, ASTNODE true, ASTNODE false);
ASTNODE alloc_and_expand_assignment(ASTNODE val1, int op, ASTNODE val2);
ASTNODE alloc_ident(char* ident);
ASTNODE alloc_num(unsigned long long int_num, long double real, int type, int sign);
ASTNODE alloc_charlit(char charlit);
ASTNODE alloc_string(char* string, int len);
ASTNODE alloc_fncall(ASTNODE name, ASTNODE params);
ASTNODE alloc_sizeof(ASTNODE expr);
ASTNODE alloc_select(ASTNODE expr, char* ident);
ASTNODE alloc_list(ASTNODE elem);

/* helper functions for dealing with lists */
ASTNODE list_last(ASTNODE list);
ASTNODE list_append_elem(ASTNODE elem, ASTNODE list);
ASTNODE list_append(ASTNODE list1, ASTNODE list2);
int list_size(ASTNODE list);
ASTNODE next_ptr(ASTNODE ptr_chain);
ASTNODE last_ptr(ASTNODE ptr_chain);
ASTNODE list_to_ptr_chain(ASTNODE list);

/* new functions for assignment 3 */
ASTNODE alloc_type(ASTNODE decl_specs);
ASTNODE alloc_declaration(ASTNODE qualif, ASTNODE decl);
ASTNODE alloc_decl_spec(int decl_spec, int type);
ASTNODE alloc_ptr(ASTNODE ptr_to);
ASTNODE alloc_array(ASTNODE array_of, ASTNODE size);
ASTNODE alloc_st_un(int type, int scope);
ASTNODE alloc_func(ASTNODE name, ASTNODE arg_list);

/* new functions for assignment 4 */
ASTNODE alloc_compound(ASTNODE exprs, SYM_TAB tab);
ASTNODE alloc_select_stmnt(int type, ASTNODE cond, ASTNODE then, ASTNODE else_stmnt);
ASTNODE alloc_iterat_stmnt(int type, ASTNODE cont, ASTNODE stmnt, ASTNODE init, ASTNODE update);
ASTNODE alloc_label_stmnt(int type, ASTNODE stmnt, char* label, ASTNODE cond);
ASTNODE alloc_jump_stmnt(int type, char* label, ASTNODE ret_expr);

ASTNODE alloc_temp(int temp_count);

#endif
