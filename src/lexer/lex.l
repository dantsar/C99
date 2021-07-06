%option noyywrap
%option noyylineno
%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <common/def.h>
#include <parser.tab.h>

extern YYSTYPE yylval;

void set_yylval_int(unsigned long long num, int type, int sign);
void set_yylval_real(char* str, int type, int sign);
int isoctal(int c);
int parse_seq(char* src, char *buf);

/* info used for debugging and error reporting */
char filename[256] = "<stdin>";
int lineno = 1;
%}

OCTAL       0[0-7]+
DIGITS      [0-9]+
HEX         0[xX][0-9a-fA-f]+
REAL        [0-9]*\.[0-9]*
R_EXP       {DIGITS}+[eE][+-]?{DIGITS}+
IDENT       [a-zA-Z_][a-zA-Z0-9_]*
CHAR_SEQ    ([^"'\\]|\\.)* 

%%
    /* get filename and lineno from the preprocessor */
#.*\n           {
                    lineno = atoi(strtok(yytext+2, " ")); /* skip # */
                    char* tmp_ptr = strtok(NULL, " ");
                    strncpy(filename, tmp_ptr+1, strlen(tmp_ptr)-2);
                    filename[strlen(tmp_ptr)-3] = '\0';
                }

[ \t\r]         {/* ignore non-newline whitespace */}
\n              {lineno++;}

    /* keywords */
"auto"          {return AUTO;       }
"break"         {return BREAK;      }
"case"          {return CASE;       }
"char"          {return CHAR;       }
"const"         {return CONST;      }
"continue"      {return CONTINUE;   }
"default"       {return DEFAULT;    }
"do"            {return DO;         }
"double"        {return DOUBLE;     }
"else"          {return ELSE;       }
"enum"          {return ENUM;       }
"extern"        {return EXTERN;     }
"float"         {return FLOAT;      }
"for"           {return FOR;        }
"goto"          {return GOTO;       }
"if"            {return IF;         }
"inline"        {return INLINE;     }
"int"           {return INT;        }
"long"          {return LONG;       }
"register"      {return REGISTER;   }
"restrict"      {return RESTRICT;   }
"return"        {return RETURN;     }
"short"         {return SHORT;      }
"signed"        {return SIGNED;     }
"sizeof"        {return SIZEOF;     }
"static"        {return STATIC;     }
"struct"        {return STRUCT;     }
"switch"        {return SWITCH;     }
"typedef"       {return TYPEDEF;    }
"union"         {return UNION;      }
"unsigned"      {return UNSIGNED;   }
"void"          {return VOID;       }
"volatile"      {return VOLATILE;   }
"while"         {return WHILE;      }
"_Bool"         {return _BOOL;      }
"_Complex"      {return _COMPLEX;   }
"_Imaginary"    {return _IMAGINARY; }

{IDENT}     { yylval.ident = strdup(yytext); return IDENT; }

"(" |
")" |
"[" |
"]" |
"{" |
"}" |
";" |
":" |
"," { return yytext[0];}

    /* two char ops */
"->"    {return INDSEL;     }
"++"    {return PLUSPLUS;   }
"--"    {return MINUSMINUS; }
"<<"    {return SHL;        }
">>"    {return SHR;        }
"<="    {return LTEQ;       }
">="    {return GTEQ;       }
"=="    {return EQEQ;       }
"!="    {return NOTEQ;      }
"&&"    {return LOGAND;     }
"||"    {return LOGOR;      }
"..."   {return ELLIPSIS;   }
"*="    {return TIMESEQ;    }
"/="    {return DIVEQ;      }
"%="    {return MODEQ;      }
"+="    {return PLUSEQ;     }
"-="    {return MINUSEQ;    }
"<<="   {return SHLEQ;      }
">>="   {return SHREQ;      }
"&="    {return ANDEQ;      }
"|="    {return OREQ;       }
"^="    {return XOREQ;      }

    /* single char ops */
[-~!%^&*+=\|<.>/?]  {return yytext[0];}

    /* numerical constants */
{OCTAL}             { set_yylval_int(strtoull(yytext, NULL, 8), N_INT,N_SIGNED); return NUMBER; }
{OCTAL}[lL]         { set_yylval_int(strtoull(yytext, NULL, 8), N_LONG,N_SIGNED); return NUMBER; }
{OCTAL}(ll|LL)      { set_yylval_int(strtoull(yytext, NULL, 8), N_LLONG,N_SIGNED); return NUMBER; }
{OCTAL}[uU]         { set_yylval_int(strtoull(yytext, NULL, 8), N_INT, N_UNSIGNED); return NUMBER; }
{OCTAL}[lL][uU]     { set_yylval_int(strtoull(yytext, NULL, 8), N_LONG,N_UNSIGNED); return NUMBER; }
{OCTAL}(ll|LL)[uU]  { set_yylval_int(strtoull(yytext, NULL, 8), N_LLONG,N_UNSIGNED); return NUMBER; }

{DIGITS}            { set_yylval_int(atoll(yytext), N_INT,N_SIGNED); return NUMBER; }
{DIGITS}[lL]        { set_yylval_int(atoll(yytext), N_LONG,N_SIGNED); return NUMBER; }
{DIGITS}(ll|LL)     { set_yylval_int(atoll(yytext), N_LLONG,N_SIGNED); return NUMBER; }
{DIGITS}[uU]        { set_yylval_int(atoll(yytext), N_INT,N_UNSIGNED); return NUMBER; }
{DIGITS}[lL][uU]    { set_yylval_int(atoll(yytext), N_LONG,N_UNSIGNED); return NUMBER; }
{DIGITS}(ll|LL)[uU] { set_yylval_int(atoll(yytext), N_LLONG,N_UNSIGNED); return NUMBER; }

{HEX}               { set_yylval_int(strtoull(yytext, NULL, 16), N_INT, N_SIGNED); return NUMBER; }
{HEX}[lL]           { set_yylval_int(strtoull(yytext, NULL, 16), N_LONG, N_SIGNED); return NUMBER; }
{HEX}"ll"|"LL"      { set_yylval_int(strtoull(yytext, NULL, 16), N_LLONG, N_SIGNED); return NUMBER; }
{HEX}[uU]           { set_yylval_int(strtoull(yytext, NULL, 16), N_INT, N_UNSIGNED); return NUMBER; }
{HEX}[lL][uU]       { set_yylval_int(strtoull(yytext, NULL, 16), N_LONG,N_UNSIGNED); return NUMBER; }
{HEX}(ll|LL)[uU]    { set_yylval_int(strtoull(yytext, NULL, 16), N_LLONG,N_UNSIGNED); return NUMBER; }

{REAL}              { set_yylval_real(yytext, N_DOUBLE, N_SIGNED); return NUMBER; }
{REAL}[f]           { set_yylval_real(yytext, N_FLOAT, N_SIGNED); return NUMBER; }
{REAL}[lL]          { set_yylval_real(yytext, N_LDOUBLE, N_SIGNED); return NUMBER; }
{R_EXP}             { set_yylval_real(yytext, N_DOUBLE, N_SIGNED); return NUMBER; }
{R_EXP}[f]          { set_yylval_real(yytext, N_FLOAT, N_SIGNED); return NUMBER; }
{HEX}[pP][+-]?{DIGITS}+ { set_yylval_real(yytext, N_DOUBLE, N_SIGNED); return NUMBER; }

\'{CHAR_SEQ}\'      {
                        int chars = parse_seq(yytext+1, &(yylval.charlit));
                        if(chars != yyleng-2){
                            fprintf(stderr, "%s:%d\t Error: incorrect CHARLIT\n", filename,lineno);
                            exit(-1);
                        }
                        return CHARLIT;
                    }
\"{CHAR_SEQ}\"      {
                        yylval.str.str = calloc(yyleng, sizeof(char*));
                        yylval.str.len = 0;
                        for(int i = 1, j = 0; i < yyleng-1;j++){
                            i += parse_seq(yytext+i, yylval.str.str+j);
                            yylval.str.len++;
                        }
                        return STRING;
                    }

    /* if this is reached, an error was encountered */
.                   {
                        fprintf(stderr, "%s:%d\t Error: unrecognized char \'%c\'\n", filename, lineno, yytext[0]); 
                        exit(-1);
                    }
%%

int isoctal(int c){
    return (c > '0' && c < '8');
}

/* returns the number of characters parsed: ex/ "\n" would parse two and "\x2A" would parse 4*/
int parse_seq(char* src, char* buf){
    char *fmt, esc_seq[4];
    int i = 0, esc_max = 0;
    int (*p_func)(int); /* parse function: used to find the number of chars in an escape sequence */
    if(src[i] == '\\'){ 
        switch(src[++i]){
            case '\'': *buf = '\''; return 2;
            case '\"': *buf = '\"'; return 2;
            case '\\': *buf = '\\'; return 2;
            case '?':  *buf = '\?'; return 2;
            case 'a':  *buf = '\a'; return 2;
            case 'b':  *buf = '\b'; return 2;
            case 'f':  *buf = '\f'; return 2;
            case 'n':  *buf = '\n'; return 2;
            case 'r':  *buf = '\r'; return 2;
            case 't':  *buf = '\t'; return 2;
            case 'v':  *buf = '\v'; return 2;
            case 'x': i++; fmt = "%x";  esc_max = 2; p_func = &isxdigit; break; 
            case '0': i++; fmt = "%o";  esc_max = 3; p_func = &isoctal; break; 
            default: 
                fprintf(stderr, "%s:%d: Error: invalid escape sequence \'\\%c\'\n", filename, lineno, src[i]);
                exit(-1);
        }
        /* get the escape sequence from src and counts its length variable for hex and octal */
        memset(esc_seq, '\0', sizeof(esc_seq));
        for(int j = 0; j < esc_max; j++,i++){
            /* check if char is part of the escpae sequence */
            if(!p_func(src[i])) break;
            esc_seq[j] = src[i];
        }
        sscanf(esc_seq, fmt, buf);
        return i;
    } else {             
        if(src[i] == '\n'){
            fprintf(stderr, "%s:%d: Error: unexpected newline\n", filename, lineno);
            exit(-1);
        }else if(isascii(src[i])){
            *buf = src[i];
            return 1;
        }
    }
    fprintf(stderr, "%s:%d: Error: unknown character %c\n", filename, lineno, src[i]);
    exit(-1);
}

/* converts yytext to integer (assumed yytext is already converted to number) */
void set_yylval_int(unsigned long long num, int type, int sign)
{
    yylval.num.int_num = num; 
    yylval.num.sign = sign;
    yylval.num.type = type;
}

void set_yylval_real(char* str, int type, int sign)
{
    sscanf(str, "%Lf", &yylval.num.real);
    yylval.num.type = type;
    yylval.num.sign = sign;
}