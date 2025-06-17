#include <stdio.h>
#include "token_types.h"

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
    yyin = fopen("example.txt", "r");
    if (!yyin) {
        printf("Could not open example.txt!\n");
        return 1;
    }

    while (1) {
        int t = yylex();
        if (t == TOKEN_EOF) break;
        printf("token: %d text: %s\n", t, yytext);
    }
}