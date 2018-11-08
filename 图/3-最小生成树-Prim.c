#include "结构-邻接矩阵.h"

/**
    时间复杂度: O(n²)
    适合：与vertex有关，与edge无关,适合稠密图。
    核心：把vertex加完为止。
*/
void Prim(MGraph g, int v0, int &sum) {
    // `lowcost`当前`生成树`最小花销
    // `vset`选入的vertex
    int lowcost[maxSize], vset[maxSize];
    int i, j, v;

    // 1. init
    for (i = 0; i < g.n; ++i) {
        lowcost[i] = g.edges[v0][i];
    }
    v = v0;
    vset[v0] = 1; 
    sum = 0;

    // 选出剩余（g.n-1）个vertex
    for (i = 0; i < g.n-1; ++i) {
        // 2. 当前最小花销
        int min = INF;
        for (j = 0; j < g.n; ++j) {
            if (vset[j] == 0 && lowcost[j] < min) {
                min = lowcost[j];
                v = j;
            }
        }

        vset[v] = 1;
        sum += min;

        // 3.更新lowcost
        for (j = 0; j < g.n; ++j) {
            if (vset[j] == 0 && g.edges[v][j] < lowcost[j]) {
                lowcost[j] = g.edges[v][j];
            }
        }
    }
}