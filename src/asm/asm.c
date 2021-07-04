
#include <stdio.h>

#include <asm/asm.h>
#include <parser/ast.h>
#include <quads/quads.h>
#include <quads/quads_print.h>
#include <parser/sym_tab.h>

extern FILE* fp;
extern ASTNODE string_l;
extern SYM_TAB curr_scope;
extern int temp_count;

static bool once = true;
extern char* func_name;
int stack_size = 0;
bool is_ret = false;

void asm_print_src(ASTNODE src)
{
    if(!src) return; /* NO BOOM */
    
    switch(src->type){
        case AST_NUM:       fprintf(fp, "$%llu", src->num.int_num); break;
        case AST_CHARLIT:   fprintf(fp, "$%d'", src->charlit.charlit); break;
        case AST_STRING:    fprintf(fp, "$.STR%zu", src->string.ro_section); break;
        case AST_BB_TEMP:   fprintf(fp, "%s", src->bb_temp.full_name); break;
        case AST_TEMP: 
            fprintf(fp, "-%d(%%ebp)", ((stack_size-(4*temp_count))+(4*src->temp.temp) ));
            break;
        case AST_IDENT:
            if(src->ident.entry->att_type == ENT_VAR){
                if (src->ident.entry->var.is_local) {
                    fprintf(fp, "%d(%%ebp)", src->ident.entry->var.offset);
                } else {
                    /* else global */
                    fprintf(fp, "%s", src->ident.ident);

                }

            }else{
                fprintf(fp, "%s",src->ident.ident);
            }

            break;
        default:
            /* error ? */
            break;

    }
}

void asm_quad(QUAD quad)
{
    if(quad == NULL) return;

    char* op;
    char* reg;

    fprintf(fp, "  #");
    print_quad(fp, quad);

    fprintf(fp, "\t");
    switch(quad->opcode) {
        case OP_MUL: 
                /* movl src1, edx */
                fprintf(fp, "movl ");
                asm_print_src(quad->src1);
                fprintf(fp, ", %%edx\n");

                /* movl src2, eax */
                fprintf(fp, "\tmovl ");
                asm_print_src(quad->src2);
                fprintf(fp, ", %%eax\n");

                fprintf(fp, "\timull %%edx, %%eax\n");

                /* movl %eax, res */
                fprintf(fp, "\tmovl %%eax, ");
                asm_print_src(quad->res);
                fprintf(fp, "\n");
                break;
        case OP_DIV: 
                /* movl src1, eax */
                fprintf(fp, "movl ");
                asm_print_src(quad->src1);
                fprintf(fp, ", %%eax\n");

                /* movl src2, ebx */
                fprintf(fp, "\tmovl ");
                asm_print_src(quad->src2);
                fprintf(fp, ", %%ecx\n");

                /* do the division */
                fprintf(fp, "\tcltd\n");
                fprintf(fp, "\tidivl %%ecx\n");

                /* movl %eax, res */
                fprintf(fp, "\tmovl %%eax, ");
                asm_print_src(quad->res);
                fprintf(fp, "\n");
            break;
        case OP_ADD: op = "addl"; goto binop_asm; 
        case OP_SUB: op = "subl"; goto binop_asm; 
        case OP_MOD: op = "modl"; goto binop_asm; 
        binop_asm:
            /* movl src1, eax */
            fprintf(fp, "movl ");
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            /* op src2, eax */
            fprintf(fp, "\t%s ", op);
            asm_print_src(quad->src2);
            fprintf(fp, ", %%eax\n");

            /* movl eax, result */
            fprintf(fp, "\tmovl %%eax, ");
            asm_print_src(quad->res);
            fprintf(fp, "\n");
            break;

        case OP_MOV:
            /* movl src1, eax */
            fprintf(fp, "movl "); 
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            /* movl eax, res */
            fprintf(fp, "\tmovl %%eax, "); 
            asm_print_src(quad->res);
            fprintf(fp, "\n");
            break;
        case OP_STORE:
            /* movl src1, eax */
            fprintf(fp, "movl "); 
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            fprintf(fp, "\tlea ");
            asm_print_src(quad->res);
            fprintf(fp, ", %%ecx\n");

            fprintf(fp, "\tmovl %%eax, (%%ecx)\n");
            break; 
        case OP_LEA:
            /* lea src1, eax */
            fprintf(fp, "lea ");
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            /* movl eax, res */
            fprintf(fp, "\tmovl %%eax, ");
            asm_print_src(quad->res);
            fprintf(fp, "\n");
            break;
        case OP_LOAD:
            /* movl src1, eax*/
            fprintf(fp, "movl ");
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            /* movl (eax), ebx */
            fprintf(fp, "\tmovl (%%eax), %%ecx\n");

            /* movl ebx, res */
            fprintf(fp, "\tmovl %%ecx, ");
            asm_print_src(quad->res);
            fprintf(fp, "\n");
            break;
        case OP_CMP:
            fprintf(fp, "movl ");
            asm_print_src(quad->src1);
            fprintf(fp, ", %%eax\n");

            fprintf(fp, "\tmovl ");
            asm_print_src(quad->src2);
            fprintf(fp, ", %%ecx\n");

            // fprintf(fp, "\tcmp %%eax, %%ecx\n");
            fprintf(fp, "\tcmp %%ecx, %%eax\n");
            break;
        
        case OP_BR:     op = "jmp"; goto br_set;             
        case OP_BRE:    op = "je";  goto br_cond_set;
        case OP_BRNE:   op = "jne"; goto br_cond_set;             
        case OP_BRL:    op = "jl";  goto br_cond_set;
        case OP_BRLE:   op = "jle"; goto br_cond_set;             
        case OP_BRG:    op = "jg";  goto br_cond_set;
        case OP_BRGE:   op = "jge"; goto br_cond_set;             
        br_set:
            fprintf(fp, "jmp %s\n", quad->src1->bb_temp.full_name);
            break;
        br_cond_set:
            fprintf(fp, "%s %s\n", op, quad->src1->bb_temp.full_name);
            fprintf(fp, "\tjmp %s\n", quad->src2->bb_temp.full_name);
            break;

        /* func call */
        case OP_PUSH:
            fprintf(fp, "pushl ");
            asm_print_src(quad->src1);
            fprintf(fp, "\n");
            break;
        case OP_CALL:
            fprintf(fp, "call ");
            asm_print_src(quad->src1);
            fprintf(fp, "\n");
            break;
        case OP_RET:
            if (quad->src1) {
                fprintf(fp, "movl ");
                asm_print_src(quad->src1);
                fprintf(fp, ", %%eax\n\t");
            }
            fprintf(fp, "leave\n");
            fprintf(fp, "\tret\n");
            is_ret = true;
            break;
    }
}

void asm_bblock(BBLOCK bblock)
{
    /* print out label of basic block */
    fprintf(fp, "\n.BB.%s.%d:\n", bblock->name, bblock->bblock_count);

    QUAD_L temp = bblock->quads;
    while (temp != NULL) {
        asm_quad(temp->elem);
        temp = temp->next;
    }
}

void gen_asm(BBLOCK_L bblock_l, ASTNODE func_def) 
{
    SYM_ENT_LL ent_l;
    SYM_ENT temp_ent;
    /* allocate global variables */
    if(once){
        once = false;
        ent_l = curr_scope->ent_ll;
        int globl_size;
        while(ent_l != NULL){
            if (ent_l->entry->att_type == ENT_VAR) {
                if(!ent_l->entry->name) continue;
                globl_size = size_of(ent_l->entry->var.type);
                fprintf(fp, "\t.comm %s, %d, %d\n", ent_l->entry->name, 
                                                    globl_size,
                                                    (globl_size == 1)? 1 : 4);
            }
            ent_l = ent_l->next;
        }
    }

    /* allocate stack for local variables and temp */
    ent_l = func_def->func.sym->ent_ll;
    int size;
    while(ent_l != NULL){
        if (ent_l->entry->att_type == ENT_VAR) {
            if(!ent_l->entry->name) continue;
            if(ent_l->entry->var.is_local)
                stack_size += 4;
        }
        ent_l = ent_l->next;
    }

    /* allign to 4 byte boundary */
    while((stack_size % 4) != 0) stack_size++;

    /* for temporary variables */
    stack_size += (temp_count*4);

    fprintf(fp, "\t.text\n");

    fprintf(fp, ".globl\t%s\n", func_name);
    fprintf(fp, ".type\t%s, @function\n", func_name);
    fprintf(fp, "%s:\n", func_name);

    fprintf(fp, "\tpushl %%ebp\n");
    fprintf(fp, "\tmovl %%esp, %%ebp\n");
    fprintf(fp, "\tsubl $%d, %%esp\n", stack_size);
    BBLOCK_L temp = bblock_l;
    while(temp != NULL){
        asm_bblock(temp->elem);
        temp = temp->next;
    }

    if(!is_ret)
    {
        fprintf(fp, "\tleave\n");
        fprintf(fp, "\tret\n");
        is_ret = false;
    }
}
