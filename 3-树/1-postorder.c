#include "BTNode.h"

void postorder(BTNode *p) {
    postorder(p->lchild);
    postorder(p->rchild);
    visit(p);
}