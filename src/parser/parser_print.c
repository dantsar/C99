#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <parser/parser_print.h>

static int space = 0;

void indent(int indent){
    for(int i = 0; i < indent*2; i++){
        putchar(' ');
    }
}
void print_sym(struct symtab *sym)
{
    if(sym == NULL) return; /* to prevent explosion */

    char* scope;
    switch(sym->scope_type){
        case SCOPE_GLOBAL:      scope = "global";   break;
        case SCOPE_FUNC:        scope = "function"; break;
        case SCOPE_BLOCK:       scope = "block";    break;
        case SCOPE_MINI:        scope = "mini";     break;
    };
    struct sym_entries *  temp = sym->ent_ll;
    while(temp != NULL){
        /* SHHHHH Im hard coding printf */
        if(!strcmp(temp->entry->name, "printf")){temp = temp->next; continue; }

        indent(space);
        fprintf(stdout, "%s is defined at %s:%d (of scope %s) as a\n", temp->entry->name, 
                                                                  temp->entry->filename, 
                                                                  temp->entry->lineno, 
                                                                  scope);
        print_sym_ent(temp->entry);
        temp = temp->next;
    }
}

/* prints the attributes of the symbol table entries */
void print_sym_ent(struct sym_entry *  ent)
{
    switch(ent->att_type){
        case ENT_VAR:
            indent(space); fprintf(stdout, "variable of type\n");
            indent(++space); print_ast(ent->var.type); --space; /* list should be being passed to print_ast */
            putchar('\n');
            break;
        case ENT_SU_TAG:
            indent(space); print_ast(ent->su_tag.st_un); 
            indent(++space); fprintf(stdout, "with elements:\n"); 
            print_sym(ent->su_tag.st_un->st_un.mini_tab); 
            --space;
            break;
        case ENT_STMNT_LABEL:
            indent(space); fprintf(stdout, "label\n");
            break;
        case ENT_FUNC:
            indent(space); fprintf(stdout, "function\n"); 
            indent(++space);

            fprintf(stdout, "taking args\n");
            ++space; print_ast(ent->func.func_def->func.args); --space;

            indent(space); fprintf(stdout, "and returning\n");
            indent(++space); print_ast(ent->func.func_def->func.ret); --space;
            putchar('\n');

            indent(space); fprintf(stdout, "with body\n");
            indent(space++); print_ast(ent->func.func_def->func.block); --space;

            indent(space); fprintf(stdout, "and resulting symbol table\n");
            space++; print_sym(ent->func.func_def->func.block->comp.tab); --space;
            space--;
            break;
    }
}

void print_ast(struct astnode *ast)
{
    if(ast == NULL) return; /* to prevent explosion */

    struct astnode *temp;
    char* temp_str;
    switch(ast->type){
        case AST_UNARY:
            switch(ast->unary.op){
                case '&':           fprintf(stdout, "ADDRESSOF\n"); break;
                case '*':           fprintf(stdout, "DEREF\n"); break;
                case PLUSPLUS:      fprintf(stdout, "POSTINC\n"); break;
                case MINUSMINUS:    fprintf(stdout, "POSTDEC\n"); break;
                default:            fprintf(stdout, "UNARY OP %c\n",ast->unary.op); break;
            }
            indent(++space); print_ast(ast->unary.expr); space--;
            break;
        case AST_BINARY: 
            if(ast->binary.op_type == ASSIGN){
                fprintf(stdout, "ASSIGNMENT\n");
            }else if(ast->binary.op_type == BINOP){
                fprintf(stdout, "BINARY OP ");
                print_op(ast->binary.op);
                putchar('\n');
            }else if(ast->binary.op_type == COMP){
                fprintf(stdout, "COMPARISON ");
                print_op(ast->binary.op);
                putchar('\n');
            }
            space++;
            indent(space); print_ast(ast->binary.left);
            indent(space); print_ast(ast->binary.right);
            space--;
            break;
        case AST_TERNARY:
            fprintf(stdout, "TERNARY OP, IF:\n");
            indent(++space); print_ast(ast->ternary.cond); space--;

            indent(space); 
            fprintf(stdout, "THEN:\n");
            indent(++space); 
            print_ast(ast->ternary.true); 
            space--;

            indent(space); 
            fprintf(stdout, "ELSE:\n");
            indent(++space); 
            print_ast(ast->ternary.false); 
            space--;
            break;
        case AST_FNCALL: 
            fprintf(stdout, "FNCALL, %d arguments\n",ast->fncall.num_param); 
            indent(++space); print_ast(ast->fncall.name); --space;
            if(ast->fncall.num_param == 0) return;

            /* print out linked list of args */
            temp = ast;
            for(int i = 1; temp->fncall.params != NULL; i++){
                indent(space);   fprintf(stdout, "arg #%d=\n",i);
                indent(++space); print_ast(temp->fncall.params->param); space--;
                temp->fncall.params = temp->fncall.params->next;
            }
            break;
        case AST_NUM: 
            if(ast->num.type <= N_LLONG){
                fprintf(stdout, "CONSTANT: (type=int)%lld\n",ast->num.int_num);
            }else{
                fprintf(stdout, "CONSTANT: (type=double)%Lf\n",ast->num.real);
            }
            break;
        case AST_IDENT: 
            fprintf(stdout, "{IDENT %s}\n", ast->ident.ident);
            break;
        case AST_CHARLIT: 
            fprintf(stdout, "CHARLIT %o\n", ast->charlit.charlit);
            break;
        case AST_STRING: 
            fprintf(stdout, "STRING %s\n", ast->string.string);
            break;
        case AST_SIZEOF: 
            fprintf(stdout, "SIZEOF\n");
            indent(++space); print_ast(ast->a_sizeof.expr); space--;
            break;
        case AST_SELECT: 
            fprintf(stdout, "SELECT\n");
            indent(++space); print_ast(ast->select.expr); space--;
            indent(++space); print_ast(ast->select.tag); space--;
            break;
        case AST_LIST:
            // fprintf(stdout, "AST_LIST\n"); /* for debugging */
            temp = ast;
            while(temp != NULL){
                print_ast(temp->list.elem);
                temp = temp->list.next;
            }
            break;
        case AST_PTR:
            fprintf(stdout, "pointer to\n");
            /* to avoid exploding from a NULL pointer */
            if(ast->ptr.ptr_to){
                indent(++space); print_ast(ast->ptr.ptr_to); space--;
            }
            break;
        case AST_ARRAY:
            // fprintf(stdout, "array (%d) of \n", ast->array.size);
            fprintf(stdout, "array of size:\n");
            indent(++space); print_ast(ast->array.size); space--;

            indent(space++); fprintf(stdout, "pointing to:\n"); space--;
            /* to avoid exploding from a NULL pointer */
            if(ast->array.ptr_to){
                indent(++space); print_ast(ast->array.ptr_to); space--;
            }
            break;
        case AST_DECLARATION: /* for debugging */
            // fprintf(stdout, "AST_DECLARATION\n");
            indent(space);
            // fprintf(stdout, "declaration: "); 
            print_ast(ast->declaration.var_type); putchar(' ');
            print_ast(ast->declaration.declaration);
            // space--;
            putchar('\n');
            break;
        case AST_TYPE:
            // fprintf(stdout, "AST_TYPE\n");
            switch(ast->var_type.stg_class)
            {
                case STG_AUTO:              fprintf(stdout, "auto "); break;
                case STG_STATIC:            fprintf(stdout, "static "); break;
                case STG_EXTERN:            fprintf(stdout, "extern "); break;
                case STG_REGISTER:          fprintf(stdout, "register "); break;
                case STG_TYPEDEF:           fprintf(stdout, "typedef "); break;
            }
            /* not really used but here for the future */
            switch(ast->var_type.type_qualif)
            { 
                case QUALIF_CONST:          fprintf(stdout, "const "); break;
                case QUALIF_RESTRICT:       fprintf(stdout, "restrict "); break;
                case QUALIF_VOLATILE:       fprintf(stdout, "volatile "); break;
            }
            if(ast->var_type.type == AST_ST_UN){
                print_ast(ast->var_type.st_un);
            } else{
                if(ast->var_type.is_unsigned){
                    fprintf(stdout, "unsigned ");
                }
                switch(ast->var_type.type_spec)
                {
                    case TYPE_VOID:         fprintf(stdout, "void "); break;
                    case TYPE_CHAR:         fprintf(stdout, "char "); break;
                    case TYPE_SHORT:        fprintf(stdout, "short "); break;
                    case TYPE_INT:          fprintf(stdout, "int "); break;
                    case TYPE_LONG:         fprintf(stdout, "long int"); break;
                    case TYPE_LLONG:        fprintf(stdout, "long long int"); break;
                    case TYPE_FLOAT:        fprintf(stdout, "float "); break;
                    case TYPE_DOUBLE:       fprintf(stdout, "double "); break;
                    case TYPE_LDOUBLE:      fprintf(stdout, "long double "); break;
                    case TYPE_SIGNED:       fprintf(stdout, "signed "); break;
                    case TYPE_UNSIGNED:     fprintf(stdout, "unsigned "); break;
                }
            }
            break;
        case AST_DECL_SPEC:
            // fprintf(stdout, "AST_DECL_SPEC\n"); /* for debugging */
            switch(ast->decl_spec.decl_spec){
                case TYPE_VOID:             fprintf(stdout, "void "); break;
                case TYPE_CHAR:             fprintf(stdout, "char "); break;
                case TYPE_SHORT:            fprintf(stdout, "short "); break;
                case TYPE_INT:              fprintf(stdout, "int "); break;
                case TYPE_LONG:             fprintf(stdout, "long "); break;
                case TYPE_FLOAT:            fprintf(stdout, "float "); break;
                case TYPE_DOUBLE:           fprintf(stdout, "double "); break;
                case TYPE_SIGNED:           fprintf(stdout, "signed "); break;
                case TYPE_UNSIGNED:         fprintf(stdout, "unsigned "); break;
                case QUALIF_CONST:          fprintf(stdout, "const "); break;
                case QUALIF_RESTRICT:       fprintf(stdout, "restrict "); break;
                case QUALIF_VOLATILE:       fprintf(stdout, "volatile "); break;
                case FUNC_INLINE:           fprintf(stdout, "inline "); break;
            }
            break;
        case AST_ST_UN:
            if(ast->st_un.type == AST_STRUCT){
                fprintf(stdout, "struct");
            }else{
                fprintf(stdout, "union");
            }
            fprintf(stdout, " %s\n", ast->st_un.name);
            // print_sym(ast->st_un.mini_tab);
            break;
        case AST_FUNC:
            fprintf(stdout, "function: %s\n taking arguments:\n", ast->func.name->ident.ident);
            indent(++space); print_ast(ast->func.args); space--;
            indent(space); fprintf(stdout, "and returning:\n");
            indent(++space); print_ast(ast->func.ret); space--;
            putchar('\n');
            indent(space); fprintf(stdout, "with body:\n");
            indent(++space); print_ast(ast->func.block); space--;
            break;
        case AST_COMPOUND:
            // fprintf(stdout, "AST_COMPOUND\n");
            if(ast->comp.states == NULL){ 
                fprintf(stdout, "empty block\n");
                return;
            }
            temp = ast->comp.states;
            while(temp != NULL){
                indent(space); print_ast(temp->list.elem); putchar('\n');
                temp = temp->list.next;
            }
            break;
        case AST_SELECT_STMNT:
            temp_str = (ast->select_stmnt.type == AST_IF_STMNT) ? "IF" : "SWITCH";
            indent(space); fprintf(stdout, "%s:\n",temp_str);
            indent(++space); print_ast(ast->select_stmnt.cond); space--;

            temp_str = (ast->select_stmnt.type == AST_IF_STMNT) ? "THEN" : "BODY";
            indent(space); fprintf(stdout, "%s:\n",temp_str);
            indent(++space); print_ast(ast->select_stmnt.then); space--;

            if(ast->select_stmnt.else_stmnt){
                fprintf(stdout, "ELSE:\n");
                indent(++space); print_ast(ast->select_stmnt.else_stmnt); space--;
            }
            break;
        case AST_ITERAT_STMNT:
            switch(ast->iterat_stmnt.type){
                case AST_DO_STMNT:      
                    fprintf(stdout, "DO:"); 
                    indent(++space); print_ast(ast->iterat_stmnt.stmnt); space--;
                    indent(space); fprintf(stdout, "WHILE:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.cond); space--;
                    break;
                case AST_WHILE_STMNT:   
                    indent(space); fprintf(stdout, "WHILE:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.cond); space--;
                    fprintf(stdout, "DO:"); 
                    indent(++space); print_ast(ast->iterat_stmnt.stmnt); space--;
                    break;
                case AST_FOR_STMNT:     
                    fprintf(stdout, "FOR:\n"); 
                    indent(space); fprintf(stdout, "INIT:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.init); space--;
                    indent(space); fprintf(stdout, "COND:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.cond); space--;
                    indent(space); fprintf(stdout, "UPDATE:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.update); space--;
                    indent(space); fprintf(stdout, "BODY:\n"); 
                    indent(++space); print_ast(ast->iterat_stmnt.stmnt); space--;
                    break;
            }
            break;
        case AST_LABEL_STMNT:
            switch(ast->label_stmnt.type){
                case AST_LABEL:
                    fprintf(stdout, "LABEL(%s)\n", ast->label_stmnt.label);
                    indent(++space); print_ast(ast->label_stmnt.stmnt); space--;
                    break;
                case AST_LABEL_CASE:
                    fprintf(stdout, "CASE\n");
                    indent(++space); print_ast(ast->label_stmnt.cond); space--;
                    indent(++space); print_ast(ast->label_stmnt.stmnt); space--;
                    break;
                case AST_LABEL_DEFAULT:
                    fprintf(stdout, "DEFAULT\n");
                    indent(++space); print_ast(ast->label_stmnt.stmnt); space--;
                    break;
            }
            break;
        case AST_JUMP_STMNT:
            switch(ast->jump_stmnt.type){
                case AST_GOTO:
                    fprintf(stdout, "GOTO (%s)\n", ast->jump_stmnt.goto_label);
                    break;
                case AST_CONTINUE:
                    fprintf(stdout, "CONTINUE\n");
                    break;
                case AST_BREAK:
                    fprintf(stdout, "BREAK\n");
                    break;
                case AST_RETURN:
                    fprintf(stdout, "RETURN\n");
                    if(ast->jump_stmnt.ret_expr != NULL){
                        space++;
                        indent(++space); print_ast(ast->jump_stmnt.ret_expr); space--;
                        --space;
                    }
                    break;
            }
            break;
    }
}
