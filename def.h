#ifndef DEF_H
#define DEF_H

extern char filename[256];
extern int lineno;

typedef enum {false, true} bool;

typedef struct astnode*       ASTNODE;
typedef struct sym_tab*       SYM_TAB;
typedef struct sym_entry*     SYM_ENT;
typedef struct sym_entries*   SYM_ENT_LL;

/* enums for NUMS */
enum N_SIGN {N_SIGNED=0, N_UNSIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

struct Str{
    char *str;
    int len;
};

struct Num{
    unsigned long long int_num;
    long double real;
    int type;
    int sign;
};

#endif
