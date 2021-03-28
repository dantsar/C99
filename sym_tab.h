#ifndef SYM_TAB_H
#define SYM_TAB_H

#include "def.h"
#include "ast.h"

enum SCOPES{
      SCOPE_GLOBAL=0, 
      SCOPE_FUNC, 
      SCOPE_BLOCK, 
      SCOPE_PROTO, 
      SCOPE_MINI /* only for structs and unions */
}; 

enum SYM_ENT_TYPE{
      ENT_SCALAR=0,
      ENT_PTR
};

enum NAMESPACES{
    NS_SU=0, /* struct/union */
    NS_SU_TAG,
    NS_LABEL,
    NS_MISC
};

/* the different storages classes */
enum STG_CLASS{
    STG_AUTO=0,
    STG_STATIC,
    STG_EXTERN,
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

/* size of scalars. Used for sizeof operator */
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


SYM_TAB sym_create(int att_type);
SYM_ENT alloc_sym_ent(char* name, int ent_type, int ent_ns);

void sym_destory(SYM_TAB sym);
void sym_push(SYM_TAB stack, SYM_TAB sym);
void sym_pop(SYM_TAB stack);
bool sym_enter(SYM_TAB tab, SYM_ENT ent);
SYM_ENT sym_lookup(SYM_TAB sym, SYM_ENT ent); 

void print_sym(SYM_TAB sym);
void print_sym_stack(SYM_TAB curr_scope);



/* variable attributes */
struct var_att{
    // ASTNODE val;
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
    ASTNODE body;
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

    char* name;
    int namespace;
    // ASTNODE ast_node;

    int att_type;
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
    SYM_TAB curr_scope;
    SYM_TAB next;

    /* linked list of symbol table entries */
    SYM_ENT_LL first_ent_ll;
    SYM_ENT_LL last_ent_ll;
    struct sym_entries{ 
        SYM_ENT entry;
        struct sym_entries *next;
    }*ent_ll;
};


#endif