#ifndef ASM_H
#define ASM_H

#include <parser/ast.h>
#include <common/def.h>
#include <quads/quads.h>
#include <parser/sym_tab.h>

void gen_asm(BBLOCK_L quads, ASTNODE func_def);

#endif
