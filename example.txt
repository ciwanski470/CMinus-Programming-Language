#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list {
    int val;
    struct list *next;
} list;

list *reverse_list(list *curr, bool is_first) {
    list *new_head = (curr->next) ? reverse_list(curr->next, false) : curr;

    if (curr->next) {
        curr->next->next = curr;
    }
    if (is_first) {
        curr->next = 0;
    }

    return new_head;
}

int main(void) {
    list *my_list = (list *) malloc(sizeof(list));
    my_list->val = 1;
    list *curr = my_list;
    for (int i=2; i<=5; i++) {
        curr->next = (list *) malloc(sizeof(list));
        curr->next->val = i;
        curr = curr->next;
    }

    list *new_list = reverse_list(my_list, true);

    for (list *node = new_list; node; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");

    return 0;
}