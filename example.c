typedef struct list {
    int val;
    struct list *next;
} list;

void func(int a[8]) {

}

list *reverse_list(list *curr, int is_first) {
    list *new_head = (curr->next) ? reverse_list(curr->next, 0) : curr;

    int (*(*f[8])(int, double))[8];

    int *a[8];

    int b[4];
    func(b);

    typedef int (*(*some_type)(int, int))[8];

    some_type var[10];

    for (int i=0; i<4; i++) {
        b[i] = i;
    }
}