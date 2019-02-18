typedef struct InfoNode {
    BTNode *p;
    int level;
} InfoNode;

int width(BTNode *r) {
    int max = 0;
    InfoNode que[maxSize];
    int front, rear;
    front = rear = -1;

    if (r == NULL) return 0;

    max = 1;
    que[++rear] = InfoNode(r, 1);

    while (front != rear) {
        InfoNode info = que[++front];

        if (info.level > max) {
            max = info.level;
        }
        if (info.p->lchild != NULL) {
            que[++rear] = InfoNode(info.p->lchild, info.level + 1);
        }
        if (info.p->rchild != NULL) {
            que[++rear] = InfoNode(info.p->rchild, info.level + 1);
        }
    }

    return max;
}