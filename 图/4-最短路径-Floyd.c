// [url](http://www.cnblogs.com/wangyuliang/p/9216365.html)
#include "结构-邻接矩阵.h"

void Floyd(MGraph g, int Path[][maxSize]) {
    int i, j, k;
    int A[maxSize][maxSize];

    // 初始化
    for (i = 0; i < g.n; ++i) {
        for (j = 0; j < g.n; ++j) {
            A[i][j] = g.edges[i][j];
            Path[i][j] = -1;
        }
    }

    // k为中间节点
    for (k = 0; k < g.n; ++k) {
        for (i = 0; i < g.n; ++i) {
            for (j = 0; j < g.n; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    Path[i][j] = k;
                }
            }
        }
    }
}

void printPath(int u, int v, int path[][maxSize]) {
    if (path[u][v] == -1) {
        print(u v);
    }
    else {
        int mid = path[u][v];
        printPath(u, mid, path);
        printPath(mid, v, path);
    }
}