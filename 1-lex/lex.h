#ifndef __LEX_H
#define __LEX_H

#include "tokens-manual.h"

void set_yylval_int(unsigned long long num, int type, int sign);

enum N_SIGN {N_UNSIGNED=0, N_SIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

struct Num{
    unsigned long long int_num;
    long double real;
    int type;
    int sign;
};

struct Str{
    char string_literal[4096];
    int len;
};

typedef union{
    struct Str str;
    struct Num num;
    char charlit;
    char* ident;
} YYSTYPE;

YYSTYPE yylval;


#endif
