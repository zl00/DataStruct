/**
R[] 需要是有序的


*/

int Bsearch(int R[], int low, int high, int k) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (R[mid] ==  k) {
            return mid;
        } else if (R[mid] > k) {
            high = mid - 1;
        } else {
            low= mid + 1; 
        } 
    }
    return -1;
}