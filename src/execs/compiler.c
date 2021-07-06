#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <parser/ast.h>
#include <parser/sym_tab.h>

FILE *fp = NULL;
char asm_out[64] = "output.S";
// char exec_out[64];
extern struct sym_tab *curr_scope;
extern struct astnode *string_l;


static int parse_args(int argc, char **argv)
{
    static struct option longopts[] = {
        {"help", no_argument, 0, 0},
    };

    int c, opt_ind = 0;
    while ((c = getopt_long(argc, argv, "o:", longopts, &opt_ind)) != -1) {
        switch (c) {
        case 'o':
            /* name of the output file */
            fprintf(stdout, "output file: %s\n", optarg);

            strcpy(asm_out, optarg);

            if (!(fp = fopen(asm_out, "w"))) {
                fprintf(stderr, "couldn't open output file");
                exit(-1);
            }
            break;
        case 0:
            fprintf(stdout, "loooong\n");
            switch (opt_ind) {
            case 0:
                fprintf(stdout, "help msg coming soon!\n");
                break;
            default:
                fprintf(stdout, "opt_ind: %d\n", opt_ind);
                /* error */
                break;
            }
            break;
        default:
            /* error */
            exit(-1);
        }

        opt_ind = 0;
    }

    if (fp == NULL) {
        if (!(fp = fopen("output.S", "w"))) {
            fprintf(stderr, "couldn't open output file");
            exit(-1);
        }
    }

    return optind;
}

int main(int argc, char **argv)
{
    int arg_ind = parse_args(argc, argv);

    /* creating global symbol table */
    curr_scope = sym_tab_create(SCOPE_GLOBAL);

    /* hard coding in printf... very kludge */
    sym_enter(curr_scope, alloc_sym_ent("printf", ENT_FUNC, NS_MISC));


    /* input files */
    for (int i = arg_ind; i < argc; i++) {
        fprintf(stdout, "argv[%d]: %s\n", i, argv[i]);
        FILE *ifp;
        if (!(ifp = fopen(argv[i], "r"))) {
            fprintf(stderr, "couldn't open input file \'%s\'\n", argv[i]);
            exit(-1);
        }
        // yyparse(ifp);
    }

    yyparse();

    /* add strings to the end */
    if (string_l != NULL) {
        fprintf(fp, "\n\t.section .rodata\n");
        
        while(string_l != NULL) {
            fprintf(fp, ".STR%zu:\n",string_l->list.elem->string.ro_section);
            fprintf(fp, "\t.string ");

            fprintf(fp, "\"");
            int len = strlen(string_l->list.elem->string.string);
            for (int i = 0; i < len; i++) {
                print_char(fp, string_l->list.elem->string.string[i]);
            }
            fprintf(fp, "\"\n");

            string_l = string_l->list.next;
        }
    }

    fclose(fp);
    return 1;
}