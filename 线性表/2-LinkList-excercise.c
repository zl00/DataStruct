/**
    例6 带头结点单链表 升序排列

    从头开始建立升序单链表
*/
void Sort(LinkList &L) {
    LNode *p = L->next; // 待插入元素
    LNode *q; // 待插入位置
    L->next = NULL; // 从头开始建立升序单链表
    
    p = r;
    while (p != NULL) {
        q = L;
        while (q->next != NULL && q->next->data < p->data)
            q = q->next;
        
        q->next = p;
        p = p->next;
        p->next = NULL;
    }
}

/**
    例7 带头结点单链表 删除(min, max)范围内的结点
*/
void RangeDelete(LinkList &L, ElemType min, ElemType max) {
    LNode *pre, p;
    p = L->next;
    pre = L;

    while (p != NULL) {
        if (p->data < max && p->data > min) {
            pre->next = p->next;
            free(p);
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

/**
    例8
*/
void Search_1st_Common(LinkList &L1, LinkList &L2) {
    LinkList longList, shortList;
    int len1 = Length(L1), len2 = Length(L2);
    int dist;
    
    if (len1 < len2) {
        dist = len2 - len1;
        longList = L2-next;
        shortList = L1->next;
    } else {
        dist = len1 - len2;
        longList = L1->next;
        shortList = L2->next;
    }

    // 齐平
    for (; dist > 0; --dist) 
        longList = longList->next;

    while (longList != NULL && shortList != NULL) {
        if (longList == shortList) // 判断同一结点
            return longList;
        else {
            longList = longList->next;
            shortList = shortList->next;
        }
    }
    return NULL;
}

/**
    例题9
*/
void Min_Delete(LinkList &head) {
    LNode *preMin, *pMin;
    LNode *pre, *p;

    while (head->next != NULL) {
        preMin = head;
        pMin = head->next;
        pre = head->next;
        p = head->next->next;

        while (p != NULL) {
            if (p->data < pMin->data) {
                pMin = p;
                preMin = pre;
            }
            pre = p;
            p = p->next;
        }
        preMin->next = pMin->next;
        print(pMin->data);
        free(pMin);
    }
    free(head);
}

// 2019.4.2
/**
    例题10
*/
void split(LinkList &A, LinkList &B) {
    B = (LinkList)malloc(sizeof(LNode));
    B->next = NULL;

    LNode *p = A->next;
    Int count = 0;

    LNode *rA = A, *rB = B;

    while (p != NULL) {
        if (++count % 2 == 1) { // 奇数
            rA->next = p;
            rA = p;
        } else {
            rB->next = p;
            rB = p;
        }
        p = p->next;
    }
    rA->next = NULL;
    rB->next = NULL;
}

/**
    例题11
*/
void split2(LinkList &C, LinkList &A, LinkList &B) {
    A = (LinkList)malloc(sizeof(LNode));
    A->next = NULL;

    B= (LinkList)malloc(sizeof(LNode));
    B->next = NULL;

    int count = 0;
    LNode *p = C->next;
    LNode *rA = A;
    LNode *t;

    while (p != NULL) {
        count++;
        if (count % 2 == 1) {
            rA->next = p;
            rA = p;
            p = p->next;
            rA->next = NULL;
        } else {
            t = p->next;
            p->next = B->next;
            B->next = p;
            p = t;
        }
    }
}

/**
    例题12
*/
void unique(LinkList &L) {
    LNode *p = L->next;
    LNode *q;

    if (p == NULL) return;

    while (p->next != NULL) {
        if (p->data == p->next->data) {
            q = p->next;
            p->next = q->next;
            free(p);
        } else {
            p = p->next;
        }
    }
}

/**
    例题13
*/
LinkList reverse_merge(LinkList &L1, LinkList &L2) {
     LinkList L = (LinkList)malloc(sizeof(LNode));
     L->next = NULL;

     LNode *p, *q, *t;
     p = L1->next;
     q = L2->next;

     while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            t = p->next;
            p->next = L->next;
            L->next = p;
            p = t;
        } else {
            t = q->next;
            q->next = L->next;
            L->next = q;
            q = t;
        }
     }

     while (p != NULL) {
         t = p->next;
         p-next = L->next;
         L->next = p;
         p = t;
     }

     while (q != NULL) {
         t = q->next;
         q->next = L->next;
         L->next = q;
         q = t;
     }

     return L;
}

/**
    例题14
*/
LinkList findSameElement(LinkList L1, LinkList L2) {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;

    LNode *r = L, t;
    LNode *p = L1->next;
    LNode *q = L2->next;

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        }
        else if (q->data < p->data) {
            q = q->next;
        }
        else (p->data == q->data) {
            t = (LNode*)malloc(sizeof(LNode));
            t->data = p->data;
            t->next = NULL;
            r->next = t;
            r = t;
            
            p = p->next;
            q = q->next;
        }
    }
    r->next = NULL;
    return L;
}

/**
    例题15
*/
LinkList Union(LinkList &la, LinkLit &lb) {
    pa = la->next;
    pb = lb->next;
    pc = la;

    while (pa && pb) {
        if (pa->data == pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
            u = pb;
            pb = pb->next;
            free(u);
        }
        else if (pa->data < pb->data) {
            u = pa;
            pa = pa->next;
            free(u);
        }
        else {
            u = pb;
            pb = pb->next;
            free(u);
        }
    }

    while (pa) {
        u = pa;
        pa = pa->next;
        free(u);
    }
    while (pb) {
        u = pb;
        pb = pb->next;
        free(u);
    }

    pc->next = NULL;
    free(lb);

    return la;
}

/**
    例题17
*/
int Symmetry(DLinkList L) {
    DNode *p = L->next, *q = L->prior;

    while (p != q && p->next != p) { // `p->next != p`☁️很容易错
        if (p->data == q->data) {
            p = p->next;
            q = q->prior;
        } else {
            return 0;
        }
    }
    return 1;
}

/**
    例题18
*/
LinkList Link(LinkList &h1, LinkList &h2) {
    LNode *p, *q;

    p = h1;
    while (p->next != h1) {
        p = p->next;
    }

    q = h2;
    while (q->next != h2) {
        q = q->next;
    }

    p->next = h2;
    q->next = h1;
    return h1;
}

/**
    例题19
*/
void Del_All(LinkList &L) {
    LNode *p, *pre, *minp, *minpre;
    while (L->next != L) {
        p = L->next; pre = L;
        minp = p; minpre = pre;

        while (p != L) {
            if (p->data < minp->data) {
                minp = p; minpre = pre;
            }
            pre = p;
            p = p->next;
        }
        printf("%d", minp->data);
        minpre->next = minp->next;
        free(minp);
    }
    free(L);
}

/**
    例题20
*/
DLinkList Locate(DLinkList &L, ElemType x) {
    DNode *p = L->next, *q;

    while (p && p->data != x) p = p->next;

    if (!p) {
        exit(0);
    } else {
        p->freq++;

        p->next->pred = p->pred;
        p->pred->next = p->next;

        q = p->pred;
        while (q != L && q->freq <= p->freq) q = q->pred;

        p->next = q->next;
        q->next->pred = p;
        p->pred = q;
        q->next = p;
    }

    return p;
}


/**
    例题21
*/
typedef int ElemType;
typedef struct LNode {
    ElemType data;
    struct LNode *link;
} LNode, *LinkList;

int Search_k(LinkList list, int k) {
    LNode *p = list->link; *q = list->linkl;
    
    int count = 0;
    while (p != NULL) {
        if (count < k) count++;
        else q = q->link;
        p = p->next;
    }

    if (count < k) return 0;
    else {
        printf("%d", q->data);
        return 1;
    }
}


/**
    例题22
*/
typedef struct Node {
    char data;
    struct Node *next;
} SNode;

int listlen(SNode *head) {
    int len = 0;
    while (head->next != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

SNode *find_addr(SNode *str1, SNode *str2) {
    int m, n;
    SNode *p, *q;
    m = listlen(str1);
    n = listlen(str2);

    for (p = str1; m > n; m--) p = p->next;
    for (q = str2; m < n; n--) q = q->next;

    while (p->next != NULL && p->next != q->next) {
        p = p->next;
        q = q->next;
    }
    return p->next;
}

/**
    例题23
*/
typedef struct Node {
    int data;
    struct Node *link;
} Node;

void filter(Node *h, int n) {
    Node *p = h, *r;
    int *q, m;

    q = (int *)malloc(sizeof(int) * (n+1));
    for (int i = 0; i < n+ 1; i++) *(q+i) = 0;

    while (p->link != NULL) {
        m = p->link->data > 0 ? p->link->data : -p->link->data;
        if (*(q+m) == 0) 
        {
            *(q+m) = 1;
            p = p->link;
        }
        else
        {
            r = p->link;
            p->link = r->link;
            free(r);
        }
    }
    free(q);
}