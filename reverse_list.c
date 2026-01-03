typedef unsigned long size_t;

extern int printf(const char *message, ...);
extern void *malloc(size_t size);

typedef struct list_node {
    int val;
    struct list_node *next;
} list_node_t;

list_node_t *reverse_list(list_node_t *node, int is_head) {
    if (!node) return 0;

    list_node_t *new_head = (node->next) ? reverse_list(node->next, 0) : node;

    if (node->next) {
        node->next->next = node;
    }

    if (is_head) {
        node->next = 0;
    }

    return new_head;
}

int main() {
    list_node_t *head = 0;
    list_node_t *prev = 0;
    for (int i=1; i<=10; i++) {
        list_node_t *curr = malloc(sizeof(list_node_t));
        curr->val = i;
        if (prev) {
            prev->next = curr;
        } else {
            head = curr;
        }
        prev = curr;
    }

    for (list_node_t *node = head; node; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");

    head = reverse_list(head, 1);

    for (list_node_t *node = head; node; node = node->next) {
        printf("%d ", node->val);
    }
    printf("\n");

    return 0;
}