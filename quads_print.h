#ifndef QUADS_PRINT_H
#define QUADS_PRINT_H

#include "def.h"

void quad_error(const char* msg);
void print_opcode(int opcode);
void print_src_param(ASTNODE src_param);
void print_quad(QUAD quad);
void print_bblock(BBLOCK block);
void print_bblock_l(BBLOCK_L bblock_l);

#endif
