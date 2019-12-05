// [wiki](https://www.cnblogs.com/chengxiao/p/6129630.html)

/**
 `Sift`: 这个函数名字很精妙，Sift本意是“筛”这个动作。
 因此，我所建立的思维模型如下：
 - defs:
    1. 有序树（平衡二叉树--饱和），有序是指--子节点比父节点小。
    2. Sift函数的含义是，将low这个节点筛到合适的位置。
    3. 外部调用Sift函数建立平衡二叉树时，必须从最后一个父节点开始sift，这样才能保证层层调用sift后，得到一棵平衡二叉树。
 */
void sift(int R[], int low, int high) {
    int i = low;
    int j = 2 * i + 1; // left leaf

    while (j <= high) {
        if (j + 1 <= high && R[j] < R[j+1]) ++j; // fetch the bigger leaf

        if (R[i] < R[j]) {
            swap(R, i, j); // 交换之后i位置元素是正确的了，但j位置就可能不正确了，所以才会继续筛

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