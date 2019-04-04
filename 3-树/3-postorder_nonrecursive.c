/**
    e.g.
            ①
        ②       ③

思路一
    preorder: 1, 2, 3
    postorder: 2, 3, 1
    换言之，postorder = preoder逆序 + 左右子树交换

思路二

*/

void postorder(BTNode *bt) {
    BTNode *rstack[maxSize];
    int rtop = -1;

    BTNode *stack[maxSize];
    int top = -1;

    BTNode *p = NULL;

    if (bt == NULL) return;
    stack[++top] = bt;

    while (top != -1) {
        p = stack[top--];
        rstack[++rtop] = p;

        if (p->lchild != NULL) {
            stack[++top] = p->lchild;
        }

        if (p->rchild != NULL) {
            stack[++top] = p->rchild;
        }
    }

    while (rtop != -1) {
        visit(rstack[rtop--]);
    }
}