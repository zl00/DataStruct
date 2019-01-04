void Sift(int R[], int low, int high) {
    int i = low, j = 2*i;
    int temp = R[i];
    while (j <= high) {
        if (j < high && R[j] < R[j+1]) ++j;

        if (temp < R[j]) {

        }
    }
}

void heapSort(int R[], int n) {
    int i;
    int temp;

    for (i = n/2; i >=1; --i)
        
}