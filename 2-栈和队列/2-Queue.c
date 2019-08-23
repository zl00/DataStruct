#define MaxSize 50
typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.front = 0;
    Q.rear = 0;
}

bool IsEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool IsFull(SqQueue Q) {
    return (Q.rear + 1) % MaxSize == Q.front;
}

bool EnQueue(SqQueue &Q, ElemType e) {
    if (IsFull(Q) == true) return false;

    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e) {
    if (IsEmpty(Q) == true) return false;

    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}