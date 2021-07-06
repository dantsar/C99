#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <parser/ast.h>
#include <parser/sym_tab.h>

extern struct sym_tab *curr_scope;
extern char *file_out;
extern FILE *fp;
extern struct astnode *string_l;


// static int parse_args(int argc, char **argv)
// {


// }

int main(int argc, char **argv)
{
    /* creating global symbol table */
    curr_scope = sym_tab_create(SCOPE_GLOBAL);

    if (!(fp = fopen(file_out, "w"))) {
        fprintf(stderr, "couldn't open output file");
        exit(-1);
    }
    
    // fp = stdout;

    /* hard coding in printf... very kludge */
    sym_enter(curr_scope, alloc_sym_ent("printf", ENT_FUNC, NS_MISC));
    
    yyparse();

    /* add strings to the end */
    if(string_l != NULL){
        fprintf(fp, "\n\t.section .rodata\n");
        
        while(string_l != NULL)
        {
            fprintf(fp, ".STR%zu:\n",string_l->list.elem->string.ro_section);
            fprintf(fp, "\t.string ");

            fprintf(fp, "\"");
            int len = strlen(string_l->list.elem->string.string);
            for(int i = 0; i < len; i++){
                print_char(fp, string_l->list.elem->string.string[i]);
            }
            fprintf(fp, "\"\n");

            string_l = string_l->list.next;
        }
    }

    fclose(fp);
    return 1;
}