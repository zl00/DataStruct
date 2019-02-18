void preorder(BTNode *p) {
    if (p == NULL) {
        return ;
    }

    BTNode *stack[maxSize];
    int top = -1;

    stack[++top] = p;
    while (top != -1) {
        BTNode *p = stack[top--];
        visit(p);

        if (p->rchild) {
            stack[++top] = p->rchild;
        }
        if (p->lchild) {
            stack[++top] = p->lchild;
        }
    }
}