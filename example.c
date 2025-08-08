
typedef struct list {
    int val;
    struct list *next;
} list;

list *reverse_list(list *curr, int is_first) {
    list *new_head = (curr->next) ? reverse_list(curr->next, 0) : curr;

    int *(*f[8])(int);

    /*
    if (curr->next) {
        curr->next->next = curr;
    }
    if (is_first) {
        curr->next = 0;
    }
    */

    //return new_head;
}


/*
int main(void) {
    int a = 5;
}
*/

/*
int main(void) {
    int b = 2;
    int a = (5 == 3) ? main() : b;
}
*/