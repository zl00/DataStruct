/**
算法思想：每次顺序选出一个数，插入到之前合适位置。
⚠️：每次插入后，前面都是有序的。
时间复杂度：o(n²)
*/
void InsertSort(int R[], int n) {
    int i, j;
    int temp;

    for (i = 1; i < n; ++i) {
        temp = R[i];

        j = i-1;
        while (j >= 0 && temp < R[j]) {
            R[j+1] = R[j];
            j--;
        }
        R[j+1] = temp;
    }
}
