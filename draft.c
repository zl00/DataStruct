typedef struct TBTNode {
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
} TBTNode;

void InThread(TBTNode *p, TBTNode *&pre) {
    if (!p)  return;

    InThread(p, pre);

    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }

    pre = p;
    InThread(p, pre);
}

void createInThread(TBTNode *root) {
    TBTNode *pre = NULL;
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

TBTNode *first(TBTNode *p) {
    while (p->ltag == 0) p = p->lchild;
    return p;
}

TBTNode *next(TBTNode *p) {
    if (p->rtag == 1) return p->rchild;
    else return first(p->rchild);
}

void Inorder(TBTNode *root) {
    for (TBTNode *p = first(root); p != NULL; p = next(p)) {
        visit(p);
    }
}