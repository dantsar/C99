#ifndef QUADS_PRINT_H
#define QUADS_PRINT_H

#include <common/def.h>

void quad_error(const char* msg);
void print_opcode(FILE* fp, int opcode);
void print_src_param(FILE* fp, ASTNODE src_param);
void print_quad(FILE* fp, QUAD quad);
void print_bblock(FILE* fp, BBLOCK block);
void print_bblock_l(FILE* fp, BBLOCK_L bblock_l);

#endif
