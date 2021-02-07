%{

#include "lex.h"
#include "tokens-manual.h"

int yylval;
%}


%%

[0-9]+  {return NUMBER;}

" "      {;}
" "      {;}
" "      {;}
" "      {;}
" "      {;}
" "      {;}
" "      {;}
" "      {;}


.       {return fprintf(stderr, "other\n");}

%%

int main(){
    int t;
    /* yylex returns every char that it reads from stdio */
    while(t = yylex())
    {
        switch(t)
        {
            case NUMBER:
                printf("INTEGER STUFF\n");
                break;
        }

    }
    printf("EOF ENCOUNTERED\n");
}
