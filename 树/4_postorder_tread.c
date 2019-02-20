/**
需要借助parent，不作要求。
*/
void postThread(TBTNode *p, TBTNode *&pre) {
    if (p == NULL) return;

    InThread(p->lchild, pre);
    InThread(p->rchild, pre);

    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    pre = p;
}