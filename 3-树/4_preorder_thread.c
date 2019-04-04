void preThread(TBTNode *p, TBTNode *&pre) {
    if (p == NULL) return ;

    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }

    pre = p;
    if (p->ltag == 0) preThread(p->lchild, pre);
    if (p->rtag == 0) preThread(p->rchild, pre);
}

void preorder(TBTNode *root) {
    if (root == NULL) return ;

    TBTNode *p = root;
    while (p != NULL) {
        while (p->ltag == 0) {
            visit(p->lchild);
            p = p->lchild;
        }
        visit(p);
        p = p->rchild;
    }
}