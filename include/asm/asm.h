#ifndef ASM_H
#define ASM_H

#include <parser/ast.h>
#include <common/def.h>
#include <quads/quads.h>
#include <parser/symtab.h>

void gen_asm(struct bblock_list * quads, struct astnode *func_def);

#endif
