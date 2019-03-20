typedef struct Node {
    int data;
    struct Node *link;
} Node;

void filter(Node *h, int n) {
    Node *p = h, *r;
    int m;
    int *q;

    q = (int *)malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n+1; i+=) *(q+i) = 0;

    while (p->link != NULL) {
        m = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(q+m) == 0) {
            *(q+m) = 1;
            p = p->link;
        } else {
            r = p->link;
            p->link = r;
            free(r);
        }
    }

    free(q);
}