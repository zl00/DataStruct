void SelectSort(int R[], int n) {
    if (n <= 1) return ;

    for (int i = 0; i < n; ++i) {
        int k = i;

        for (int j = i; j < n; ++j) {
            if (R[j] < R[k]) ki = j;
        }

        Swap(R, i, k);
    }
}