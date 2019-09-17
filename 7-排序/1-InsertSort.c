/**
算法思想：每次顺序选出一个数，"从后往前"找到合适位置。
⚠️：每次插入后，前面都是有序的。

时间复杂度：o(n²)
空间复杂度：o(1)
*/
void InsertSort(int R[], int n) {
    int i, j;
    int temp;

    for (i = 1; i < n; ++i) {
        temp = R[i];

        j = i-1;
        while (j >= 0 && temp < R[j]) { // 从后往前找，直到找到比他小的位置
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = temp;
    }
}
