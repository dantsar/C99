#include <common/def.h>
#include <parser.tab.h>
#include <parser/ast.h>
#include <parser/symtab.h>

void indent(int space);
void print_ast(struct astnode *ast);
void print_sym(struct symtab *sym);
void print_sym_ent(struct sym_entry *  ent);
