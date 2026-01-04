extern int printf(const char *format, ...);

static const char *alphabet = "abcdefghijklmnopqrstuvwxyzH ";
static int a = 10;

int main() {
    const char s[12] = "Hello world";
    char curr[12] = "";

    for (int i=0; i<11; i++) {
        for (int j=0; j<28; j++) {
            curr[i] = alphabet[j];
            printf("%s\n", curr);
            if (curr[i] == s[i]) break;
        }
    }

    return 0;
}