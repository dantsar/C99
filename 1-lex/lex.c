#include "lex.h"

int main(){
    int t;
    /* yylex returns every char that it reads from stdio */
    while(t = yylex())
    {
        switch(t)
        {
            case INTEGER:
                printf("INTEGER STUFF\n");
                break;
        }

    }
    printf("EOF ENCOUNTERED\n");
}

