#ifndef SYM_TAB_H
#define SYM_TAB_H

#include <common/def.h>
#include <parser/ast.h>

enum SCOPES{
      SCOPE_GLOBAL=0, 
      SCOPE_FUNC, 
      SCOPE_BLOCK, 
      SCOPE_PROTO, 
      SCOPE_MINI /* only for structs and unions */
}; 

/* used for the setting type in the sym table */
enum SYM_ENT_TYPE{
    ENT_VAR=0,
    ENT_FUNC,
    ENT_SU_TAG,
    ENT_SU_MEM,
    ENT_ENUM_TAG,
    ENUM_CONST,
    ENT_STMNT_LABEL,
    ENT_TYPEDEF_NAME
};

/* namespace types */
enum NAMESPACES{
    NS_SU=0, /* struct/union */
    NS_SU_TAG, NS_LABEL, NS_MISC
};

/* the different storages classes */
enum STG_CLASS{
    STG_AUTO=1, STG_STATIC, STG_EXTERN, STG_TYPEDEF, STG_REGISTER
};

/* types of scalars */
enum TYPE_SPEC{
    TYPE_VOID=STG_REGISTER+1,
    TYPE_CHAR, TYPE_SHORT, TYPE_INT, TYPE_LONG, TYPE_LLONG, TYPE_FLOAT, 
    TYPE_DOUBLE, TYPE_LDOUBLE, TYPE_SIGNED, TYPE_UNSIGNED, TYPE__BOOL, TYPE__COMPLEX
};

/* type qualifier */
enum TYPE_QUALIF{
    QUALIF_CONST=TYPE__COMPLEX+1,
    QUALIF_RESTRICT, 
    QUALIF_VOLATILE
};

/* function specifier */
enum FUNC_SPEC{
    FUNC_INLINE=QUALIF_VOLATILE+1
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

/* variable attributes */
struct var_att{
    struct astnode *type;
    int stg_class;
    int offset;     /* offset in stackframe: only for type auto */
    bool is_local;
    // SYM_ENT ent;
};

/* function attributes */
struct func_att{
    int stg_class;
    bool inline_spec;
    bool def_seen;
    struct astnode *func_def;
};

struct struct_union_tag{
    struct astnode *st_un;
};

struct enum_tag{
    bool def_comp;
};

struct enum_const{
    int val;
};

struct statement_label{
    bool seen; /* placeholder */
};

struct typedef_name{
    struct astnode *eq_type;
};


struct sym_entry{
    /* information for debugging */
    char *filename;
    int lineno;

    /* for distinguishing between symbol table entries */
    char* name;
    int namespace;
    
    /* storing the values for the entry */
    int att_type;
    union{ /* attributes */
        struct var_att              var;
        struct func_att             func;
        struct struct_union_tag     su_tag;
    //     struct enum_tag             en_tag;
    //     struct enum_const           en_val;
    //     struct statement_label      stmt_l;
    //     struct typedef_name         t_def;
    };
};

struct sym_tab {
    /* stack of symbol table scopes */
    int scope_type;
    struct sym_tab *next;

    /* linked list of symbol table entries */
    struct sym_entries *first_ent_ll;
    struct sym_entries *last_ent_ll;
    struct sym_entries{ 
        struct sym_entry *entry;
        struct sym_entries *next;
    } *ent_ll;
};

/* symbol table interface functions */
struct sym_tab *sym_tab_create(int att_type);
void sym_tab_destory(struct sym_tab *sym);
struct sym_tab *sym_tab_push(int scope_type, struct sym_tab *sym_tab);
struct sym_tab *sym_tab_push_on(struct sym_tab *curr_scope, struct sym_tab *new);
struct sym_tab *sym_tab_pop(struct sym_tab *stack);
bool sym_enter(struct sym_tab *tab, struct sym_entry *ent);
struct sym_entry *sym_lookup(struct sym_tab *sym, struct sym_entry *ent); 

void print_sym(struct sym_tab *sym);
void print_sym_ent(struct sym_entry *ent);

/* for populating the symbol table */
struct sym_entry *alloc_sym_ent(char* name, int ent_type, int ent_ns);
// struct sym_entry *alloc_sym_ent_decl(struct astnode *type, struct astnode *ident);

void sym_declaration(struct astnode *declaration, struct sym_tab *tab);
void sym_struct_define(struct astnode *st_un, struct astnode *decl_list);
void sym_struct_declare(char* name, struct astnode *st_un, struct sym_tab *tab);
void sym_label(struct astnode *label, struct sym_tab *tab);
void sym_func_def(struct astnode *func_def, struct sym_tab *tab);

#endif
