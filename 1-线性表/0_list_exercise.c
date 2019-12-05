// 链表的定义、插入、删除
typedef struct {
    struct LNode *next;
    int data;
} LNode, *LinkList;

void insert_head(LinkList list, int data) {
    if (list == NULL) return ;

    LNode *p = malloc(sizeof(LNode));
    p->data = data;
    p->next = list->next;
    list->next = p;
}

bool delete(LinkList list, int data) {
    if (list == NULL) return ;

    LNode *p = list;
    while (p->next != NULL && p->next->data != data)
        p = p->next;

    if (p->next != NULL) {
        LNode *q = p->next; // 要删除的结点
        p->next = q->next;
        free(q);
        return true;
    }

    return false;
}

// 奇数放左边
void sort(LinkList list) {
    if (list == NULL) return ;

    LNode *p = list;
    LNode *q = list->next;
    while (q != NULL) {
        if (q->data % 2 == 1) {
            p->next = q->next;
            q->next = list->next;
            list->next = q;
        }
        p = p->next;
        q = q->next;
    }
}

// 找相同后缀
LNode *suffix(LinkList word1, LinkList word2) {
    if (word1 == NULL || word2 == NULL) return NULL;

    Stack s1, s2;
    LNode *p = word1->next;
    while (p != NULL) {
        s1.push(p);
        p = p->next;
    }

    LNode *q = word2->next;
    while (q != NULL) {
        s2.push(q);
        q = q->next;
    }

    LNode *result = NULL;
    while (!s1.isEmpty && !s2.isEmpty) {
        p = s1.pop();
        q = s2.pop();
        if (p == q) result = p;
        else break;
    }
    return result;
}

// add
int add(LinkList list) {
    if (list == NULL) return -1;

    LNode *p = list->next;
    Stack stack;
    while (p != NULL) {
        stack.push(p);
        p = p->next;
    }

    bool flag = true;
    while (stack.isEmpty == false && flag) {
        p = stack.pop();
        if (p->data == 9) {
            flag = true;
            p->data = 0;
        } else {
            flag = false;
            p->data++;
        }
    }
    
    if (flag) {
        p = malloc(sizeof(LNode));
        p->data = 1;
        p->next = list->next;
        list->next = p;
    }
    return 0;
}

// 倒数第K个位置指针
LNode *reversed(LinkList list, int k) {
    if (list == NULL || k <= 0) return NULL;

    LNode *p = list, *q = list->next;
    int dist = 0;
    while (q != NULL) {
        dist++;
        if (dist >= k) p = p->next;

        q = q->next;
    }
    
    if (dist < k) return NULL;
    else return p;
}