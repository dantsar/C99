#include <stdio.h>
#include <stdlib.h>

#include "ast.h"
#include "quads.h"
#include "quads_print.h"
#include "sym_tab.h"

void print_opcode(int opcode)
{
    switch(opcode){
        case OP_ADD:    fprintf(stdout, "ADD "); break; 
        case OP_SUB:    fprintf(stdout, "SUB "); break; 
        case OP_MUL:    fprintf(stdout, "MUL "); break; 
        case OP_DIV:    fprintf(stdout, "DIV "); break; 
        case OP_MOD:    fprintf(stdout, "MOD "); break; 
        case OP_SHR:    fprintf(stdout, "SHR "); break; 
        case OP_SHL:    fprintf(stdout, "SHL "); break; 
        case OP_XOR:    fprintf(stdout, "XOR "); break; 
        case OP_OR:     fprintf(stdout, "OR ");  break;
        case OP_AND:    fprintf(stdout, "AND "); break;
        case OP_LOAD:   fprintf(stdout, "LOAD "); break;
        case OP_STORE:  fprintf(stdout, "STORE "); break;
    }
}

void print_src_param(ASTNODE src_param)
{
    if(src_param == NULL) return;

    switch(src_param->type){
        case AST_IDENT: fprintf(stdout, "%s", src_param->ident.ident); break;
        case AST_NUM: fprintf(stdout, "%lld", src_param->num.int_num); break; /* only worrying about integer numbers */ 
        case AST_CHARLIT: 
            putchar('\''); print_char(src_param->charlit.charlit); putchar('\''); 
            break;
        case AST_TEMP: fprintf(stdout, "%%T%d", src_param->temp); break;
        default:
            fprintf(stdout, "UH OH THERE PARTNER!!!\n");
            print_ast(src_param);
            exit(42);
    }
}

void print_quad(QUAD quad)
{
    print_src_param(quad->res);  fprintf(stdout, "=\t");
    print_opcode(quad->opcode);  putchar(' ');
    print_src_param(quad->src1); 
    if(quad->src2 == NULL){
        putchar('\n'); 
        return;
    }
    putchar(',');
    print_src_param(quad->src2); putchar('\n');
}

void print_bblock(BBLOCK block)
{
    QUAD_L temp = block->quads;
    while(temp != NULL){
        print_quad(temp->elem);
        temp = temp->next;
    }
}
