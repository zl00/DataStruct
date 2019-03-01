/**
摩尔投票问题

问题: 找出一组数字序列中出现次数大于总数1/2的数字,显然这个数字只可能有一个。

原理: 每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是候选数字。
*/
int Majority(int A[], int n) {
    int candidate, count = 0;

    // find candidate
    for (int i = 0; i < n; ++i) {
        if (count == 0) 
            candidate = A[i];

        if (candidate == A[i]) 
            count++;
        else 
            count--;
    }

    if (count > 0) {
        count == 0;
        for (int i = 0; i < n; ++i)
            if (A[i] == candidate)
                count++;
    }

    return count > n/2 ? candidate : -1;
}

// 找出数组中出现次数超过三分之一的元素
bool Majority2(int A[], int n, int &i, int &j) {
    int candidate1, count1 = 0;
    int candidate2, count2 = 1;

    for (int i = 0; i < n; ++i) {
        if (count1 == 0) {
            candidate1 = A[i];
        } else if (count2 == 0) {
            candidate2 = A[i];
        }

        if (A[i] == candidate1) {
            count1++;
        } else if (A[i] == candidate2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    // ...
}