#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "quads.h"
#include "quads_print.h"
#include "sym_tab.h"

void quad_error(const char* msg){
    fprintf(stderr, "ERROR: %s\n", msg);
    exit(-1);
}

void print_opcode(int opcode)
{
    switch(opcode){
        case OP_ADD:    fprintf(stderr, "ADD "); break; 
        case OP_SUB:    fprintf(stderr, "SUB "); break; 
        case OP_MUL:    fprintf(stderr, "MUL "); break; 
        case OP_DIV:    fprintf(stderr, "DIV "); break; 
        case OP_MOD:    fprintf(stderr, "MOD "); break; 
        case OP_SHR:    fprintf(stderr, "SHR "); break; 
        case OP_SHL:    fprintf(stderr, "SHL "); break; 
        case OP_XOR:    fprintf(stderr, "XOR "); break; 
        case OP_OR:     fprintf(stderr, "OR ");  break;
        case OP_AND:    fprintf(stderr, "AND "); break;
        case OP_LOAD:   fprintf(stderr, "LOAD "); break;
        case OP_STORE:  fprintf(stderr, "STORE "); break;
        case OP_LEA:    fprintf(stderr, "LEA "); break;
        case OP_MOV:    fprintf(stderr, "MOV "); break;
        case OP_CMP:    fprintf(stderr, "CMP "); break;
        case OP_BR:     fprintf(stderr, "BR "); break;
        case OP_BRL:    fprintf(stderr, "BRL "); break;
        case OP_BRLE:   fprintf(stderr, "BRLE "); break;
        case OP_BRG:    fprintf(stderr, "BRG "); break;
        case OP_BRGE:   fprintf(stderr, "BRGE "); break;
        case OP_BRE:    fprintf(stderr, "BRE "); break;
        case OP_BRNE:   fprintf(stderr, "BRNE "); break;
        case OP_PUSH:   fprintf(stderr, "PUSH "); break;
        case OP_CALL:   fprintf(stderr, "CALL "); break;
        case OP_RET:    fprintf(stderr, "RET "); break;
    }
}

void print_src_param(ASTNODE src_param)
{
    if(src_param == NULL) return;

    switch(src_param->type){
        case AST_IDENT:     fprintf(stderr, "%s", src_param->ident.ident); break;
        case AST_STRING:    fprintf(stderr, ".STR%zu", src_param->string.ro_section); break;
        case AST_NUM:       fprintf(stderr, "%lld", src_param->num.int_num); break; /* only worrying about integer numbers */ 
        case AST_TEMP:      fprintf(stderr, "%%T%d", src_param->temp.temp); break;
        case AST_CHARLIT: 
            fprintf(stderr,"%c",'\''); 
            print_char(src_param->charlit.charlit); 
            fprintf(stderr,"%c",'\''); 
            break;
        case AST_BB_TEMP: fprintf(stderr, "%s", src_param->bb_temp.full_name); break;

        default:
            fprintf(stderr, "UH OH THERE PARTNER!!!\n");
            print_ast(src_param);
            exit(42);
    }
}

void print_quad(QUAD quad)
{
    if(quad == NULL) return;

    if(quad->res != NULL){
        fprintf(stderr, "\t");
        print_src_param(quad->res);  
        fprintf(stderr, "=\t");

    } else {
        fprintf(stderr,"%c",'\t');
    }
    print_opcode(quad->opcode);  fprintf(stderr,"%c",' ');
    if(quad->src1 != NULL){
        print_src_param(quad->src1); 
    }
    if(quad->src2 == NULL){ 
        fprintf(stderr,"%c",'\n'); 
        return; 
    }
    if(quad->src1 != NULL)
        fprintf(stderr,"%c",',');
    print_src_param(quad->src2); fprintf(stderr,"%c",'\n');
}

void print_bblock(BBLOCK bblock)
{
    // if(block == NULL) quad_error("empty basic block");
    if(bblock == NULL) return;
    fprintf(stderr, ".BB.%s.%d:\n", bblock->name, bblock->bblock_count);
    
    QUAD_L temp = bblock->quads;
    while(temp != NULL){
        print_quad(temp->elem);
        temp = temp->next;
    }
}

void print_bblock_l(BBLOCK_L bblock_l){
    BBLOCK_L temp = bblock_l;
    while(temp != NULL){
        print_bblock(temp->elem);
        temp = temp->next;
    }
}
