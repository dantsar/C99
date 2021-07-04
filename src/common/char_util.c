#include <stdio.h>

#include <common/char_util.h>
#include <parser.tab.h>

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

void print_char(FILE* fp, char c){
    switch(c){
        case '\'':  fprintf(fp, "\\'");  break;  
        case '\"':  fprintf(fp, "\\\""); break;
        case '\?':  fprintf(fp, "\\?");  break;
        case '\\':  fprintf(fp, "\\\\"); break;
        case '\a':  fprintf(fp, "\\a");  break;
        case '\b':  fprintf(fp, "\\b");  break; 
        case '\f':  fprintf(fp, "\\f");  break;
        case '\n':  fprintf(fp, "\\n");  break; 
        case '\r':  fprintf(fp, "\\r");  break;
        case '\t':  fprintf(fp, "\\t");  break;
        case '\v':  fprintf(fp, "\\v");  break; 
        default:
            if(c >127 || c < 32){
                fprintf(fp, "%03o", c);
            }else{
                fprintf(fp, "%c", c);
            }
    }
}
