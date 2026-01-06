typedef unsigned long size_t;
extern void *malloc(size_t size);
extern int printf(const char *format, ...);

int main() {
    int *a = 0ll;
    if (a < 1.0) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}