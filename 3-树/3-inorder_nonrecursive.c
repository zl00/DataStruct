void inorder(BTNode *bt) {
    BTNode* stack[maxSize];
    int top = -1;

    BTNode *p = bt;

    while (top != -1 || p != NULL) {
        while (p != NULL) {
            stack[++top] = p;
            p = p->lchild;
        }

        if (top != -1) {
            p = stack[top--];
            visit(p);

            if (p->rchild != NULL) {
                p = p->rchild;
            }
        }
    }
}