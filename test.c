#include <stdio.h>

int main() {
    char s[10] = "";
    scanf("%s", s);

    for (int i=0; i<10; i++) {
        printf("%c\n", s[i]);
    }
}