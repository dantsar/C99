#ifndef DEF_H
#define DEF_H

extern char filename[256];
extern int lineno;

typedef enum {false, true} bool;

/* enums for NUMS */
enum N_SIGN {N_SIGNED=0, N_UNSIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

#endif
