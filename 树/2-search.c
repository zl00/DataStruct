/**
    没说此二叉树是有序的，所以需要遍历查找。
*/
void search(BTNode *p, int key, BTNode* &q) {
    if (p->data == key) {
        q = p;
        return;
    }

    search(p->lchild, key, q);
    search(p->rchild, key, q);
}

/**
    剪枝操作（在理解了tree-base-excecute-flow.c后，更容易理解这里）
*/
void search_cutBranch(BTNode *p, int key, BTNode* &q) {
    if (p->data == key) {
        q = p;
        return;
    }

    search_cutBranch(p->lchild, key, q);
    if (q == NULL) { // cut branch
        search_cutBranch(p->rchild, key, q);
    }
}