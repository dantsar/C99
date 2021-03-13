#include <stdio.h>

#include "char_util.h"
#include "parser.tab.h"


void print_op(int op){
    if(op < 255){
        putchar(op);
    }else{
        char* op_str;
        switch(op){ 
            case PLUSPLUS:    op_str = "++"; break;
            case MINUSMINUS:  op_str = "--"; break;
            case SHL:         op_str = "<<"; break;
            case SHR:         op_str = ">>"; break;
            case LTEQ:        op_str = "<="; break;  
            case GTEQ:        op_str = ">="; break; 
            case EQEQ:        op_str = "=="; break; 
            case NOTEQ:       op_str = "!="; break;  
            case LOGAND:      op_str = "&&"; break;  
            case LOGOR:       op_str = "||"; break;
            case ELLIPSIS:    op_str = "..."; break;
        }
        fprintf(stdout, "%s", op_str);
    }
}

void print_char(char c){
    switch(c){
        case '\'':  fprintf(stdout, "\\'");  break;  
        case '\"':  fprintf(stdout, "\\\""); break;
        case '\?':  fprintf(stdout, "\\?");  break;
        case '\\':  fprintf(stdout, "\\\\"); break;
        case '\a':  fprintf(stdout, "\\a");  break;
        case '\b':  fprintf(stdout, "\\b");  break; 
        case '\f':  fprintf(stdout, "\\f");  break;
        case '\n':  fprintf(stdout, "\\n");  break; 
        case '\r':  fprintf(stdout, "\\r");  break;
        case '\t':  fprintf(stdout, "\\t");  break;
        case '\v':  fprintf(stdout, "\\v");  break; 
        default:
            if(c >127 || c < 32){
                fprintf(stdout, "%03o", c);
            }else{
                fprintf(stdout, "%c", c);
            }
    }
}

