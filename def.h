#ifndef DEF_H
#define DEF_H

/* enums for NUMS */
enum N_SIGN {N_UNSIGNED=0, N_SIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

/* Abstract Symbol Table node types */
enum {AST_BINOP=0, AST_IDENT, AST_NUM, AST_SIZEOF, AST_FCN, AST_UNOP, AST_CHARLIT, AST_STRING};


// struct Num{
//         unsigned long long int_num;
//         long double real;
//         int type;
//         int sign;
// };

#endif