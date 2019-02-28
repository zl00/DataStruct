typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) { return false; }
    if (L.length >= MaxSize) { return false; }

    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j-1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) { return false; }
    if (L.length < 1) { return false; }

    e = L.data[i-1];
    for (int j = i; j < L.length; ++j) {
        L.data[j-1] = L.data[j];
    }
    L.length--;
    return true;
}

int LocateElem(SqList &L, ElemType e) {
    for (int i = 0; i < L.length; ++i) {
        if (e == L.data[i]) {
            return i + 1;
        }
    }
    return 0;
}