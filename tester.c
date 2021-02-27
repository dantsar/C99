#include <stdio.h>
#include "lex.h"

int main(){

    struct Str str;
    struct Num num;

    fprintf(stdout, "sizeof Str: %d\n", sizeof(str));
    fprintf(stdout, "sizeof Num: %d\n", sizeof(num));

    return 1;
}