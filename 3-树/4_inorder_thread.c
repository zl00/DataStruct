typedef struct TBTNode {
    char data;
    int ltag, rtag;
    struct TBTNode *lchild;
    struct TBTNode *rchild;
} TBTNode;

////////////////////////////建立线索//////////////////////////////
/**
功能：
1. 建立前驱、后继关系
2. 更新pre
*/
void InThread(TBTNode *p, TBTNode *&pre) {
    if (p == NULL) return;

    InThread(p->lchild, pre);

    // 1. 建立前驱、后继关系
    if (p->lchild == NULL) {
        p->lchild = pre;
        p->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = p;
        pre->rtag = 1;
    }
    
    // 2. 更新pre
    pre = p;

    InThread(p->rchild, pre);
}

void createInThread(TBTNode *root) {
    TBTNode *pre = NULL;
    if (root != NULL) {
        InThread(root, pre);
        pre->rchild = NULL;
        pre->rtag = 1;
    }
}

////////////////////////////遍历//////////////////////////////
TBTNode* first(TBTNode *p) {
    while (p->ltag == 0) p = p->lchild;
    return p;
}

TBTNode* next(TBTNode *p) {
    if (p->rtag == 1) {
        return p->rchild;
    } else {
        return first(p->rchild);
    }
}

void Inorder(TBTNode *root) {
    for (TBTNode *p = first(root); p != NULL; p = next(p)) {
        visit(p);
    }
}