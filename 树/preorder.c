#include "BTNode.h"

void preorder(BTNode *p) {
    if (p != NULL) {
        visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void preorder2(BTNode *bt) {
    if (bt != NULL) {
        BTNode *stack[maxSize];
        int top = -1;
        BTNode *p;
    }
}