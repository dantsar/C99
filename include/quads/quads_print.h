#ifndef QUADS_PRINT_H
#define QUADS_PRINT_H

#include <common/def.h>

void quad_error(const char* msg);
void print_opcode(FILE* fp, int opcode);
void print_src_param(FILE* fp, struct astnode *src_param);
void print_quad(FILE* fp, struct quad * quad);
void print_bblock(FILE* fp, struct bblock *block);
void print_bblock_l(FILE* fp, struct bblock_list * bblock_l);

#endif
