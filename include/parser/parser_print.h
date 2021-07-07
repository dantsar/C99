#include <common/def.h>
#include <parser.tab.h>
#include <parser/ast.h>
#include <parser/sym_tab.h>

void indent(int space);
void print_ast(struct astnode *ast);
void print_sym(struct sym_tab *sym);
void print_sym_ent(struct sym_entry *  ent);
