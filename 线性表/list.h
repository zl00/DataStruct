#define MaxSize 1024

typedef struct SqList {
    ElemType data[MaxSize];
    int length;
} SqList;