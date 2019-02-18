#include "BTNode.h"

void preorder(BTNode *p) {
    if (p != NULL) {
        visit(p);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

