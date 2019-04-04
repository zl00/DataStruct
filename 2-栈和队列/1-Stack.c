// 栈顺序存储结构
#define MaxSize 50
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

// 栈链式存储结构
// 采用单链表，所有操作都是喜爱表头进行
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} *LiStack;

// 共享栈


// 栈行为
void InitStack(SqStack &s) {
    s.top = -1;
}

bool StackEmpty(SqStack s) {
    return s.top == -1;
}

bool Push(SqStack &s, ElemType e) {
    if (s.top+1 == MaxSize) {
        return false;
    }

    s.data[++s.top] = e;
    return true;
}

bool Pop(SqStack &s, ElemType &e) {
    if (s.top == -1) {
        return false;
    }

    e = s.data[s.top--];
    return true;
}

bool GetTop(SqStack s, ElemType &e) {
    if (s.top == -1) {
        return false;
    }

    e = s.data[s.top];
    return true;
}