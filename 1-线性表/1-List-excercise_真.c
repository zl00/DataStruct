/** 10
*/
void Reverse(int A[], int left, int right, int arraySize) {
    if (left >= right || right >= arraySize) return;

    int mid = (left + right) / 2;
    int tmp;
    for (int i = 0; i < mid - left; ++i) {
        tmp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = A[left+i];
    }
}
void Exchange(int A[], int m, int n, int arraySize) {
    Reverse(A, 0, m + n - 1, arraySize);
    Reverse(A, 0, n - 1, arraySize);
    Reverse(A, n, m + n - 1, arraySize);
}


/** 11 求2个有序数组合成后的中位数

    思想： 二分法每次选出结果的一半（小的那半）
        e.g. 2个长度为8的数组:  4个, 2个, 1个
        e.g. 2个长度为10的数组: 5个, 2个, 1个, 1个
*/
int Median_Search(int A[], int B[], int n) {
    int s1 = 0, d1 = n-1, m1;
    int s2 = 0, d2 = n-1, m2;

    while (s1 != d1 || s2 != d2) {
        m1 = (s1 + d1) / 2;
        m2 = (s2 + d2) / 2;

        if (A[m1] == B[m2]) {
            return A[m1];
        }
        else if (A[m1] < B[m2]) {
            d2 = m2;
            /**
            ☁️ 为什么长度是odd时，处理会不同？
            可能是因为保证A，B待选数组长度一样
            */
            s1 = isOdd(s1, d1) ? m1 : m1 + 1;
        }
        else {
            d1 = m1;
            s2 = isOdd(s2, d2) ? m2 : m2 + 1;
        }
    }
    return A[s1] < B[s2] ? A[s1] : B[s2];
}

bool isOdd(int s, int d) {
    return (s + d) % 2 == 0
}


/** 12
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