void sift(int R[], int low, int high) {
    int i = low;
    int j = 2 * i + 1; // left leaf
    int temp = R[i];

    while (j <= high) {
        if (j + 1 <= high && R[j] < R[j+1]) ++j;

        if (temp < R[j]) {
            R[i] = R[j];
            R[j] = temp;

            i = j;
            j = 2 * i + 1;
        } else {
            break;
        } 
    }
}

void heapSort(int R[], int n) {
    int low = n / 2 - 1; // 第一个非叶子结点 `n / 2 - 1`
    while (low >= 0) {
        sift(R, low, n);
        low--;
    }

    int i = n - 1;
    while (i > 0) {
        swap(R, 0, i);
        sift(R, 0, i-1);
        i--;
    }
}