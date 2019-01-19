/**
a[]不要求有顺序
找到：ASL1 = (n+1)/2
未找到：ASL2 = n
*/
int search(int a[], int n, int k) {
    int i;
    for (i = 0; i < n; ++i) {
        if (a[i] == k) return i;
    }
    return -1;
}