#include "BTNode.h"

/**
    层次遍历
*/
void level(BTNode *p) {
    BTNode que[maxSize];
    int front, rear;
    front = rear = 0;
    BTNode *q;

    if (p != NULL) {
        rear = (rear + 1) % maxSize;
        que[rear] = p;

        while (front != rear) {
            front = (front + 1) % maxSize;
            q = que[front];

            visit(q);

            if (q->lchild != NULL) {
                rear = (rear + 1) % maxSize;
                que[rear] = q->lchild;
            }

            if (q->rchild != NULL) {
                rear = (rear + 1) % maxSize;
                que[rear] = q->rchild;
            }
        }
    }
}