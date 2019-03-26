/** q1.
*/
bool Del_Min(SqList &L, ElemType &value) {
    if (L.length == 0) return false;

    int pos = 0;
    for (int i = 0; i < L.length; ++i)
        if (L.data[i] < L.data[pos])
            pos = i;

    value = L.data[pos];
    L.data[pos] = L.data[L.length - 1];
    L.length--;
    return true;
}

/** q2.
    注意写法。用这种头尾调换的方式更好
*/
void Reverse(SqList &L) {
    ElemType tmp;
    for (int i = 0; i < L.length / 2; ++i) {
        tmp = L.data[i];
        L.data[i] = L.data[L.length-1-i];
        L.data[L.length-1-i] = tmp;
    }
}

/** q3.
*/
void del_x(SqList &L, ElemType x) {
    int k = 0;
    for (int i = 0; i < L.length; ++i)
        if (L.data[i] != x)
            L.data[k++] = L.data[i];
    L.length = k;
}

/** q6.
    用下面这种2个指针方式，使得逻辑更清晰些。
*/
bool delete_same(SqList &L) {
    if (L.length <= 1) return false;

    int i, j;
    for (i = 0, j = 1; j < L.length; ++j)
        if (L.data[i] != L.data[j])
            L.data[++i] = L.data[j];
        
    L.length = i + 1;
    return true;
}

/** q7.
*/
bool Merge(SeqList A, SeqlList B, SeqlList &C) {
    if (A.length + B.length > C.maxSize) return false;

    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] < B.data[j])
            C.data[k++] = A.data[i++];
        else
            C.data[k++] = B.data[j++];
    }

    while (i < A.length) {
        C.data[k++] = A.data[i++];
    }
    while (j < B.length) {
        C.data[k++] = B.data[j++];
    }
    C.length = A.length + B.length;
    return true;
}


/** q8.
*/
typedef int DataType;
void Reverse(DataType A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize) return;

    int mid = (left + right) / 2;
    DataType tmp;
    for (int i = 0; i <= mid - left; ++i) {
        tmp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = tmp;
    }
}
void Exchange(DataType A[], int m, int n, int arraySize) {
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}

/// 2019.3.26

/** q9.
*/
void SearchExchangeInsert(ElemType A[], int n, ElemType x) {
    int low = 0, high = n-1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (A[mid] == x) break;
        else if (A[mid] < x) low = mid + 1;
        else high = mid - 1;
    }

    if (A[mid] == x && mid != n-1) {
        t = A[mid]; A[mid] = A[mid+1]; A[mid+1] = t;
    }
    if (low > high) {
        // 🤔为什么是high
        for (int i = n-1; i > high; i--) A[i+1] = A[i]; // 后移元素
        A[high+1] = x;
    }
}
