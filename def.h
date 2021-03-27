#ifndef DEF_H
#define DEF_H

extern char filename[256];
extern int lineno;

typedef enum {false, true} bool;

typedef struct astnode*       ASTNODE;
typedef struct sym_tab*       SYM_TAB;
typedef struct sym_entry*     SYM_ENT;
typedef struct sym_entries*   SYM_ENTS;

/* enums for NUMS */
enum N_SIGN {N_UNSIGNED=0, N_SIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};


#endif