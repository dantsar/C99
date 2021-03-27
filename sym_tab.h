#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "def.h"
#include "ast.h"

enum SCOPES{
      GLOB_SCOP=0, 
      FUNC_SCOP, 
      BLOCK_SCOP, 
      PROTO_SCOP, 
      MINI_SCOP /* only for structs and unions */
}; 

/* types of scalars */
enum S_SCALAR{
      S_CHAR, 
      S_SHORT, 
      S_INT,
      S_LONG,
      S_LLONG,
      S_FLOAT,
      S_DOUBLE,
      S_LDOUBLE
};

/* size of scalars */
enum SS_SCALAR{
      SS_CHAR=1,
      SS_SHORT=2,
      SS_INT=4,
      SS_LONG=4,
      SS_LLONG=8,
      SS_FLOAT=4,
      SS_DOUBLE=8,
      SS_LDOUBLE=16
};

enum SYM_TYPE{
      SYM_SCALAR=0,
      SYM_PTR
};


SYM_TAB sym_create();
void sym_destory(SYM_TAB sym);
void sym_push(SYM_TAB stack, SYM_TAB sym);
void sym_pop(SYM_TAB stack);
SYM_ENT sym_lookup(SYM_TAB sym, SYM_ENT ent); 
bool sym_enter(SYM_TAB tab, SYM_ENT ent);
void print_sym(SYM_TAB sym);


/* variable attributes */
struct var_att{
    ASTNODE type;
    int stg_class;
    int offset;     /* offset in stackframe: only for type auto */
};

/* function attributes */
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

    int type;
    char* name;
    int namespace;
    ASTNODE ast_node;
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

struct sym_tab{

    /* stack of symbol table scopes */
    int scope_type;
    SYM_TAB top;
    SYM_TAB next;

    /* linked list of symbol table entries */
    SYM_ENT first_ent;
    SYM_ENT last_ent;
    struct sym_entries{ 
        SYM_ENT entry;
        struct sym_entries *next;
    }*ents;
};


#endif