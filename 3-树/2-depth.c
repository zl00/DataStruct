/**
思路：当前节点的深度 max(左子树深度, 右子树深度) + 1
*/

int depth(BTNode *p) {
    if (p == NULL) return 0;

    return max(depth(p->lchild), depth(p->rchild)) + 1;
}