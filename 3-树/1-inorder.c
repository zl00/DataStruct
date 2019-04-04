#include "BTNode.h"

void inorder(BTNode *p) {
    inorder(p->lchild);
    visit(p);
    inorder(p->rchild);
}