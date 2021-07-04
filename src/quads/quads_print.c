#include <stdio.h>
#include <stdlib.h>

#include <parser/ast.h>
#include <quads/quads.h>
#include <quads/quads_print.h>
#include <parser/sym_tab.h>

extern FILE* fp;

void quad_error(const char* msg){
    fprintf(fp, "ERROR: %s\n", msg);
    exit(-1);
}

void print_opcode(FILE* fp, int opcode)
{
    switch(opcode){
        case OP_ADD:    fprintf(fp, "ADD "); break; 
        case OP_SUB:    fprintf(fp, "SUB "); break; 
        case OP_MUL:    fprintf(fp, "MUL "); break; 
        case OP_DIV:    fprintf(fp, "DIV "); break; 
        case OP_MOD:    fprintf(fp, "MOD "); break; 
        case OP_SHR:    fprintf(fp, "SHR "); break; 
        case OP_SHL:    fprintf(fp, "SHL "); break; 
        case OP_XOR:    fprintf(fp, "XOR "); break; 
        case OP_OR:     fprintf(fp, "OR ");  break;
        case OP_AND:    fprintf(fp, "AND "); break;
        case OP_LOAD:   fprintf(fp, "LOAD "); break;
        case OP_STORE:  fprintf(fp, "STORE "); break;
        case OP_LEA:    fprintf(fp, "LEA "); break;
        case OP_MOV:    fprintf(fp, "MOV "); break;
        case OP_CMP:    fprintf(fp, "CMP "); break;
        case OP_BR:     fprintf(fp, "BR "); break;
        case OP_BRL:    fprintf(fp, "BRL "); break;
        case OP_BRLE:   fprintf(fp, "BRLE "); break;
        case OP_BRG:    fprintf(fp, "BRG "); break;
        case OP_BRGE:   fprintf(fp, "BRGE "); break;
        case OP_BRE:    fprintf(fp, "BRE "); break;
        case OP_BRNE:   fprintf(fp, "BRNE "); break;
        case OP_PUSH:   fprintf(fp, "PUSH "); break;
        case OP_CALL:   fprintf(fp, "CALL "); break;
        case OP_RET:    fprintf(fp, "RET "); break;
    }
}

void print_src_param(FILE* fp, ASTNODE src_param)
{
    if(src_param == NULL) return;

    switch(src_param->type){
        case AST_IDENT:     
                if(src_param->ident.entry->att_type == ENT_VAR){
                    fprintf(fp, "%s{%d}", src_param->ident.ident, 
                                            src_param->ident.entry->var.offset); 
                } else {
                    fprintf(fp, "%s", src_param->ident.ident);
                }
            break;
        case AST_STRING:    fprintf(fp, ".STR%zu", src_param->string.ro_section); break;
        case AST_NUM:       fprintf(fp, "%lld", src_param->num.int_num); break; /* only worrying about integer numbers */ 
        case AST_TEMP:      fprintf(fp, "%%T%03d.%03d", src_param->temp.temp,4*src_param->temp.temp); break;
        case AST_CHARLIT: 
            fprintf(fp,"%c",'\''); 
            print_char(fp, src_param->charlit.charlit); 
            fprintf(fp,"%c",'\''); 
            break;
        case AST_BB_TEMP: fprintf(fp, "%s", src_param->bb_temp.full_name); break;

        default:
            fprintf(stderr, "UH OH THERE PARTNER!!!\n");
            print_ast(src_param);
            exit(42);
    }
}

void print_quad(FILE* fp, QUAD quad)
{
    if(quad == NULL) return;

    if(quad->res != NULL){
        fprintf(fp, "\t");
        print_src_param(fp, quad->res);  
        fprintf(fp, "=\t");

    } else {
        fprintf(fp,"%c",'\t');
    }
    print_opcode(fp, quad->opcode);  fprintf(fp,"%c",' ');
    if(quad->src1 != NULL){
        print_src_param(fp, quad->src1); 
    }
    if(quad->src2 == NULL){ 
        fprintf(fp,"%c",'\n'); 
        return; 
    }
    if(quad->src1 != NULL)
        fprintf(fp,"%c",',');
    print_src_param(fp, quad->src2); fprintf(fp,"%c",'\n');
}

void print_bblock(FILE* fp, BBLOCK bblock)
{
    // if(block == NULL) quad_error("empty basic block");
    if(bblock == NULL) return;
    fprintf(fp, ".BB.%s.%d:\n", bblock->name, bblock->bblock_count);
    
    QUAD_L temp = bblock->quads;
    while(temp != NULL){
        print_quad(fp, temp->elem);
        temp = temp->next;
    }
}

void print_bblock_l(FILE* fp, BBLOCK_L bblock_l)
{
    BBLOCK_L temp = bblock_l;
    while(temp != NULL){
        print_bblock(fp, temp->elem);
        temp = temp->next;
    }
}
