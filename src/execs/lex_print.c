#include <stdio.h>
#include <string.h>

// #include "lex.h"
#include <parser.tab.h>
#include <lex.yy.h>
#include <common/def.h>
#include <common/char_util.h>

extern int lineno;
extern char filename[];

char* get_keyword(int kw){
    switch(kw){
        case AUTO:       return "AUTO";          
        case BREAK:      return "BREAK";         
        case CASE:       return "CASE";          
        case CHAR:       return "CHAR";          
        case CONST:      return "CONST";         
        case CONTINUE:   return "CONTINUE";      
        case DEFAULT:    return "DEFAULT";       
        case DO:         return "DO";            
        case DOUBLE:     return "DOUBLE";        
        case ELSE:       return "ELSE";          
        case ENUM:       return "ENUM";          
        case EXTERN:     return "EXTERN";        
        case FLOAT:      return "FLOAT";         
        case FOR:        return "FOR";           
        case GOTO:       return "GOTO";          
        case IF:         return "IF";            
        case INLINE:     return "INLINE";        
        case INT:        return "INT";           
        case LONG:       return "LONG";          
        case REGISTER:   return "REGISTER";      
        case RESTRICT:   return "RESTRICT";      
        case RETURN:     return "RETURN";        
        case SHORT:      return "SHORT";         
        case SIGNED:     return "SIGNED";        
        case SIZEOF:     return "SIZEOF";        
        case STATIC:     return "STATIC";        
        case STRUCT:     return "STRUCT";        
        case SWITCH:     return "SWITCH";        
        case TYPEDEF:    return "TYPEDEF";       
        case UNION:      return "UNION";         
        case UNSIGNED:   return "UNSIGNED";      
        case VOID:       return "VOID";          
        case VOLATILE:   return "VOLATILE";      
        case WHILE:      return "WHILE";         
        case _BOOL:      return "_BOOL";         
        case _COMPLEX:   return "_COMPLEX";      
        case _IMAGINARY: return "_IMAGINARY";
    };
    return NULL;
}

char* get_op(int op){
    switch(op){
        case INDSEL:     return "INDSEL";  
        case PLUSPLUS:   return "PLUSPLUS";
        case MINUSMINUS: return "MINUSMINU";
        case SHL:        return "SHL";     
        case SHR:        return "SHR";    
        case LTEQ:       return "LTEQ";       
        case GTEQ:       return "GTEQ";      
        case EQEQ:       return "EQEQ";      
        case NOTEQ:      return "NOTEQ";      
        case LOGAND:     return "LOGAND";     
        case LOGOR:      return "LOGOR";    
        case ELLIPSIS:   return "ELLIPSIS";
        case TIMESEQ:    return "TIMESEQ";
        case DIVEQ:      return "DIVEQ"; 
        case MODEQ:      return "MODEQ";   
        case PLUSEQ:     return "PLUSEQ";   
        case MINUSEQ:    return "MINUSEQ";
        case SHLEQ:      return "SHLEQ";
        case SHREQ:      return "SHREQ";  
        case ANDEQ:      return "ANDEQ";     
        case OREQ:       return "OREQ";     
        case XOREQ:      return "XOREQ";      
    }
    return NULL;
}

int main(){
    int t;
    /* default */
    lineno = 1;
    strcpy(filename, "<stdin>");
    /* yylex returns every char that it reads from stdio */
    while((t = yylex()))
    {
        /* just print out the ascii chars */
        if(t < 255){
            fprintf(stdout, "%s\t %d\t ", filename, lineno);
            fprintf(stdout, "%c\n", t);
            continue;
        }

        switch(t)
        {
            case CHARLIT:
                fprintf(stdout, "%s\t %d\t CHARLIT\t ",filename, lineno);
                print_char(stdout, yylval.charlit);
                fprintf(stdout, "\n");
                break;
            case STRING:
                fprintf(stdout, "%s\t %d\t STRING ", filename, lineno);
                for(int i = 0; i < yylval.str.len; i++){
                    print_char(stdout, yylval.str.str[i]);
                }   
                fprintf(stdout, "\n");
                break;
            case NUMBER:
                fprintf(stdout, "%s\t %d\t NUMBER\t ", filename, lineno);

                if(yylval.num.type <= N_LLONG){ 
                    fprintf(stdout, "INTEGER\t %lld\t ", yylval.num.int_num);
                }else{
                    fprintf(stdout, "REAL\t %Lg\t ", yylval.num.real);
                }

                if(yylval.num.sign == N_UNSIGNED){
                    fprintf(stdout, "UNSIGNED,");
                }
                switch(yylval.num.type){
                    case N_INT: fprintf(stdout, "INTEGER\n"); break;
                    case N_LONG: fprintf(stdout, "LONG\n"); break;
                    case N_LLONG: fprintf(stdout, "LONGLONG\n"); break;
                    case N_FLOAT: fprintf(stdout, "FLOAT\n"); break;
                    case N_DOUBLE: fprintf(stdout, "DOUBLE\n"); break;
                    case N_LDOUBLE: fprintf(stdout, "LONGDOUBLE\n"); break;
                }
                break;
            case IDENT:
                fprintf(stdout, "%s\t %d\t IDENT\t %s\n", filename, lineno, yylval.ident);
                break;
            default:
                fprintf(stdout, "%s\t %d\t ", filename, lineno);
                if(t >= AUTO && t <= _IMAGINARY){
                    fprintf(stdout, "%s\n", get_keyword(t));
                }else{
                    fprintf(stdout, "%s\n", get_op(t));
                }
                break;
        }
    }
    printf("EOF ENCOUNTERED\n");
    return 1;
}