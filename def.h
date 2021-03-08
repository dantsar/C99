#ifndef DEF_H
#define DEF_H

/* enums for NUMS */
enum N_SIGN {N_UNSIGNED=0, N_SIGNED};
enum N_TYPE {N_INT=0, N_LONG, N_LLONG, N_FLOAT, N_DOUBLE, N_LDOUBLE};

/* Abstract Symbol Table node types */
enum{ AST_UNARY=0, 
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
enum{BINOP=0, COMP, ASSIGN};

#endif