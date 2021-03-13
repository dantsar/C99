#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "def.h"
#include "ast.h"
// #include "parser.tab.h"

typedef struct sym_tab* SYM_TAB;
typedef enum {false, true} bool;


SYM_TAB sym_create();
// SYM_TAB sym_destory(SYM_TAB sym);
// SYM_TAB sym_lookup(SYM_TAB); 
// int sym_enter(GYM_TAB tab, struct sym_entry *ent);



struct var_att{
    ASTNODE type;
    int stg_class;
    int offset;     /* offset in stackframe: only for type auto */
};

struct func_att{
    // type 
    int stg_class;
    bool inline_spec;
    bool def_seen;
};

struct struct_union_tag{
    SYM_TAB mem_def;
    bool def_complete;
};

struct struct_union_mem{
    ASTNODE type;
    int offset; /* only for structs */
    int bitfield, bitwidth;
};

struct enum_tag{
    bool def_comp;
};

struct enum_const{
    int val;
};

struct statement_label{
    // IR_CODE ir_code;
    bool seen; /* placeholder */
};

struct typedef_name{
    ASTNODE eq_type;
};

struct sym_entry{
    char *filename;
    int lineno;

    int namespace;
    int type;
    union{ /* attributes */
        struct var_att              var;
        struct func_att             func;
        struct struct_union_tag     su_tag;
        struct struct_union_mem     su_mem;
        struct enum_tag             en_tag;
        struct enum_const           en_val;
        struct statement_label      stmt_l;
        struct typedef_name         t_def;
    };
};


/* linked list of scopes */
struct sym_scope{
    int scope_type;
    SYM_TAB cur;
    SYM_TAB next;
};

struct sym_tab{

    /*  linked list of arrays... yes this is harder than just a linked list, but I want to try out new things :^) */
    struct entries{ 
        int num;
        struct entry *list[16];
        struct entries *next;
    }ents;
};


#endif