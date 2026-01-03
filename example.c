extern int printf(const char *message, ...);

int a = 10;

int foo(int b) {
    if (b <= 0) return 0;
    return (b > 2) ? b + foo(b-1) : b + 1;
}

int main() {
    int sum = 0;
    for (int i=1; i<=a; i++) {
        sum += i;
    }
    
    int (*func)(int) = &foo;
    printf("%d\n", (*func)(sum));

    return 0;
}