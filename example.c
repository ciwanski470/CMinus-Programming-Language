typedef unsigned long size_t;

extern void *malloc(size_t size);
extern int printf(const char *format, ...);

typedef struct list_node {
    int val;
    struct list_node *next;
} list_node_t;

int main() {
    list_node_t *a = malloc(sizeof(list_node_t));
    a->val = 10;
    a->next = malloc(sizeof(list_node_t));
    a->next->val = 20;
    printf("%d %d\n", a->val, a->next->val);
}