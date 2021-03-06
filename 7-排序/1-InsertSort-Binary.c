/**
 时间复杂度 o(n*log₂ⁿ)
 空间复杂度 o(1)
 */
void BinaryInsertSort(int R[], int n) {
    int low, high, middle, insert;
    int temp;
    int i, j;

    for (i = 1; i < n; ++i) {
        low = 0;
        high = i - 1;

        temp = R[i];

        do {
            middle = (low + high) / 2;
            if temp < R[middle] {
                high = max(low, middle - 1);
            } else if temp > R[middle] {
                low = min(middle + 1, high);
            } else {
                low = middle;
                break;
            }
        } while (low <= high);

        // 这样想，low位置的值是最接近temp的值。
        if temp <= result[low] {
            insert = low;
        } else {
            insert = low + 1;
        }

        for (j = i; j > insert; --j) {
            R[j] = R[j-1];
        }
        R[insert] = temp;
    }
}