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


数组部分：
1.（中等）给定一个数组nums，编写一个函数将0移动到数组的最后面，非零元素保持原数组的顺序。
例如：
    输入: nums = [0, 1, 0, 3, 12]
    输出: [1, 3, 12, 0, 0]

>> 思路：
1) 遍历nums，用辅助数组记录当前位置前面有几个0，
arr = [1, 1, 2, 2, 2]
2) 再次遍历nums，若当前不是0，则向前移动arr里的个数位置
e.g. 
nums[0] => ignore
nums[1] 1往前移动一个位置
nums[2] => ignore
nums[3] 3往前移动2个位置
...
最后添0


2.（中等）给定一个数组和一个值，在原地删除与值相同的数字，返回新数组的长度。元素的顺序可以改变，并且对新的数组不会有影响。
例如：
    输入：nums = [0,4,4,0,0,2,4,4], value = 4
    输出：4


3.（中等）合并两个有序升序的整数数组A和B变成一个新的数组。新数组也要有序。
例如：
    输入: A=[1,2,3,4], B=[2,4,5,6]
    输出: [1,2,2,3,4,4,5,6] 
思路：？   
4.（简单）给定一个排序的整数数组（升序）和一个要查找的整数target，用O(logn)的时间查找到target第一次出现的下标（从0开始），如果target不存在于数组中，返回-1。
例如：
    输入: [1, 2, 3, 3, 4, 5, 10]，3
     输出: 2
思路：二分查找

5.（简单）原地翻转给出的数组nums。
例如：
    输入 : nums = [1,2,5]
    输出 : [5,2,1]
n/2

6.（简单）分割一个整数数组，使得奇数在前偶数在后。
例如：
     输入: [1,4,2,3,5,6]
    输出: [1,3,5,4,2,6]
>> 记录第一个偶数的位置。

7.（中等）给定一个非负数，表示一个数字数组，在该数的基础上+1，返回一个新的数组。
该数字按照数位高低进行排列，最高位的数在列表的最前面。
例如：
    输入：[9,9,9]
    输出：[1,0,0,0]
思路：？