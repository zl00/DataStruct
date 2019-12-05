void buble(int arr[], int n) {
    if (arr == NULL || n < 2) return;

    bool flag = false;

    for (int i = 1; i < n; i++) {
        flag = false;
        for (int j = 0; j < n-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr, j, j+1);
                flag = true;
            }
        }

        if (flag == false) break;
    }
}

void insert(int arr[], int n) {
    if (arr == NULL || n < 2) return;

    for (int i = 1; i < n; ++i) {
        int temp = arr[i];
        for (int j = i-1; j >= 0; --j) {
            if (arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                arr[j+1] = temp;
                break;
            }
        }
    }
}

void select(int arr[], int n) {
    if (arr == NULL || n < 2) return;

    for (int i = 0; i < n; ++i) {
        int temp = 0;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[temp]) {
                temp = j;
            }
        }
        swap(arr, i, temp);
    }
}

void quick(int arr[], int low, int high) {
    if (arr == NULL || low >= high || low < 0 || high < 0) return;

    int i = low, j = high;
    int temp = arr[low];

    while (i <= j) {
        while (arr[j] >= temp && j > i) j--;
        if (j > i) {
            arr[i] = arr[j];
            i++;
        }
        while (arr[i] <= temp && i < j) i++;
        if (i < j) {
            arr[j] = arr[i];
            j--;
        }
    }
    quick(arr, low, i);
    quick(arr, j, high);
}