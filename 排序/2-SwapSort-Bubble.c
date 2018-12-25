/**
    一轮冒泡
    根据a < b, b < c... <传递性，所以max不存在时则排序结束

    时间：o(n²)
    空间：o(1)
*/
void bubbleSort(int input[], int n) {
    int i, j, temp, flag = 0;

    for (i = n - 1; i >= 1; --i) {
        flag = 0;

        for (j = 1; j <= i; ++j) {

            if (input[j-1] > input[j]) {
                flag = 1;
                temp = input[j];
                input[j] = input[j-1];
                input[j-1] = temp;
            }

            if (flag == 0) {
                return
            }
        }
    }
}