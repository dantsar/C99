#ifndef DEF_H
#define DEF_H

extern char filename[256];
extern int lineno;

/* enums for NUMS */
enum N_SIGN {N_UNSIGNED=0, N_SIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

/* Abstract Symbol Table node types */
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
      AST_SELECT
};
/* enum for binary types in ast */
enum AST_BIN_TYPE{BINOP=0, COMP, ASSIGN};

/* size of scalars */
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

/* scalar size */
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
#endif