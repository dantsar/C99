#include "def.h"
#include "parser.tab.h"
#include "ast.h"
#include "sym_tab.h"

void indent(int space);
void print_ast(ASTNODE ast);
void print_sym(SYM_TAB sym);
void print_sym_ent(SYM_ENT ent);
