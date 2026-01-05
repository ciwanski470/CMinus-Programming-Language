extern int printf(const char *format, ...);
extern unsigned int usleep(unsigned long us);

static const char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";

int main() {
    const char s[24] = "Charles Iwanski for MIT";
    char curr[24] = "";

    for (int i=0; i<23; i++) {
        for (int j=0; j<54; j++) {
            curr[i] = alphabet[j];
            printf("%s\n", curr);
            usleep(5000ul);
            if (curr[i] == s[i]) break;
        }
    }

    return 0;
}