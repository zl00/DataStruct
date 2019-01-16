// https://cloud.tencent.com/developer/news/269143

void mergeSort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

void merge(int A[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int arr[high+1];

    while (i <= mid && j <= high) {
        if (A[i] < A[j]) {
            arr[k++] = A[i];
            i++;
        } else {
            arr[k++] = A[j];
            j++;
        }
    }

    while (i <= mid) {
        arr[k++] = A[i++];
    }

    while (j <= high) {
        arr[k++] = A[j++];
    }
}