#ifndef ASM_H
#define ASM_H

#include "ast.h"
#include "def.h"
#include "quads.h"
#include "sym_tab.h"

void gen_asm(BBLOCK_L quads, ASTNODE func_def);

#endif
