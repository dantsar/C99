%option noyywrap
%{

#define NUMBER  1
#define EQUAL   2
#define PLUS    3
#define MINUS   4
#define W_SPACE 5
#define INT     6
#define HEX     7
#define OCTAL   8

/* stores the value */
//union Holder{
//    int i;
//    float f;
//    char c;
//} other;

int yylval;
%}

DECI        [0-9]+
OCTAL       0+[0-7]+
HEX         0[xX][0-9]+
FLOAT       [0-9]+\.[0.9]+
W_SPACE     [" " \r\n\t]+

%%
0[xX]{DIGIT}+   {return HEX;}
{DIGIT}         {yylval=atoi(yytext);return NUMBER;}
"int"           {return INTEGER;}
"="             {return EQUAL;}
"+"             {return PLUS;}
"-"             {return MINUS;}
[" "\n\t\r]     {return W_SPACE;}
.               {fprintf(stderr, "Error: unknown token %s\n", yytext);}


"char"          {}
"short"{}
"int"{}
"long"{}
"float"         {}
"double"        {}

%%

int main(){
    int t;
    /* yylex returns every char that it reads from stdio */
    while(t = yylex())
    {
        switch(t)
        {
            case HEX:
                printf("HEX\n");
                break;
            case OCTAL:
                printf("OCTAL\n");
                break;
            case NUMBER:
                printf("NUMBER %d\n", yylval);
                break;
            case EQUAL:
                printf("Equal sign encountered\n");
                break;
            case PLUS:
                printf("PLUS\n");
                break;
            case MINUS:
                printf("MINUS\n");
                break;
            case INT:
                printf("INT\n");
//            case W_SPACE:
//                printf("WHITESPACE\n");
//                break;
        }

    }
    printf("EOF ENCOUNTERED\n");
}
