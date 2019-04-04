// MARK: - 顺序表

// MARK: -- 数据结构

#define MaxSize 50
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList; // 静态内存

#define InitSize 100
typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList; // 动态内存


// MARK: -- 行为
bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) 
        return false;
    if (L.length >= MaxSize) 
        return false;

    for (int j = L.length; j >= i; j--) 
        L.data[j]= L.data[j-1];
    L.data[i-1] = e;
    L.length++;

    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length)
        return false;

    e = L.data[i-1];
    for (int j = i-1; j < L.length-1; ++j)
        L.data[j] = L.data[j+1];
    L.length--;

    return true;
}

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; ++i) {
        if (e == L.data[i])
            return i + 1;
    }

    return 0;
}
