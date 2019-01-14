void bubbleSort(int R[], int n) {
    int i, j, temp, flag;

    for (i = n-1; i >= 1; --i) {
        flag = 0;

        for (j = 1; j <= i; ++j) {
            if (R[j-1] > R[j]) {
                flag = 1;
                temp = R[j];
                R[j] = R[j-1];
                R[j-1] = temp;
            }
            if (flag == 0) { 
                return; 
            }
        }
    }
}