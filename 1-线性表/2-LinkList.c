/**
    带头结点
*/
void Del_X_1(LinkList &L, ElemType x) {
    LNode *p = L->next, *pre = L, *q;

    while (p != NULL) {
        if (p->data == x) {
            q = p;
            p = q->next;
            pre->next = q->next;
            free(q);
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
    带头结点 尾插法
*/
void Del_X_2(LinkList &L, ElemType x) {
    LNode *p = L->next, *r = L, *q;
    while (p != NULL) {
        if (p->data != x) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            q = p;
            p = p->next;
            free(q);
        }
    }
    r->next = NULL;
}

/**
    不带头结点 + 注意引用。
*/
void Del_X_3(LinkList &L, ElemType x) {
    if (L == NULL) return ;

    LNode *p;
    if (L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    } else {
        Del_X_3(L->next, x);
    }
}

/**
    倒序输出各节点（☁️ 能想到用栈的 就可以用递归解决）
    带头结点
*/
void R_Print(LinkList L) {
    if (L->next == NULL) return ;
    R_Print(L->next);
    print(L->data);
}

LinkList Delete_Min(LinkList &L) {
    LNode *pre = L, *p = pre->next;
    LNode *minpre = pre, *minp = p;

    while (p != NULL) {
        if (p->data < minp->data) {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next;
    }

    minpre->next = minp->next;
    free(minp);
    return L;
}

LinkList Reverse_1(LinkList L) {
    LNode *p, *r;
    p = L->next;
    L->next = NULL;

    while (p != NULL) {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }

    return L;
}

LinkList Reverse_2(LinkList L) {
    LNode *pre, *p = L->next, *r = p->next;
    p->next = NULL;
    while (r != NULL) {
        pre = p;
        p = r;
        p->next = pre;
        r = r->next;
    }
    L->next = p;
    return L;
}