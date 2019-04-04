#include "BTNode.h"

typedef struct {
    BTNode *p;
    int lno;
} St;

/**
🌲的宽度
*/
int width(BTNode *b) {
    St que[maxSize];
    int front, rear;
    int i, n, max;

    BTNode *q;
    int Lno;
    
    front = rear = 0;

    if (b != NULL) {
        ++rear;
        que[rear].p = b;
        que[rear].lno = 1;

        while (front != rear) {
            ++front;
            q = que[front].p;
            Lno = que[front].lno;

            if (q->lchild != NULL) {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }

            if (q->rchild != NULL) {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        }
    }

    Lno = -1;
    n = 0;
    max = 0;

    for (i = 1; i <= rear; ++i) {
        if (que[i].lno != Lno) { // new level
            if (n < max) { max = n; }
            n = 1;
        } else {
            n++;
        }
    }
    if (n < max) { max = n;}
    return max;
}