void Sift(int R[], int low, int high) {
    int i = low, j = 2 * i;
    int temp = R[i];

    while (j <= high) {
        if (j < high && R[j] < R[j+1]) ++j;

        if (temp < R[j]) {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        } else {
            break;
        }

        R[i] = temp;
    }
}

void heapSort(int R[], int n) {
    int i;
    int temp;
    
    for (i = n/2; i >= 1; --i) {
        Sift(R, i, n);
    }

    for (i = n; i >= 2; --i) {
        temp = R[1];
        R[1] = R[i];
        R[i] = temp;
        Sift(R, 1, i-1);
    }
}