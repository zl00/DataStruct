#include "结构-邻接矩阵.h"


/**
    算法逻辑

    名词说明：
        S： 存放选入节点集合
        T： 存放剩余节点

    思想：    
    假设 v -> a -> b -> c -> e是包含所有节点的最短路径，
    那么其子路径必然是最短路径。
    
    所以问题变形为每次查找v为起点的最短路径。

    ----------------------------

    @dist[]: v到下标对应节点的长度 
    @path[]: path[i] = j; j -> i。path存放的是源头
*/
void Dijkstra(MGraph g, int v, int dist[], int path[]) {
    int set[maxSize]; // 结点是否被访问
    int min, i, j, u;

    // Init
    for (i = 0; i < g.n; ++i) {
        dist[i] = g.edges[v][i];
        set[i] = 0;
        if (g.edges[v][i] != INF) {
            path[i] = v;
        } else {
            path[i] = -1;
        } 
    }
    set[v] = 1; 
    path[v] = -1;

    for (i = 0; i < g.n-1; ++i) {
        // 选出距离v最短距离点
        min = INF;
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        set[u] = 1;

        // 更新dist
        for (j = 0; j < g.n; ++j) {
            if (set[j] == 0 && dist[u]+g.edges[u][j] < dist[j]) {
                dist[j] = dist[u] + g.edges[u][j];
                path[j] = u;
            }
        }
    }
}

void printPath(int path[], int a) {
    int stack[maxSize], top = -1;
    while (path[a] != -1) {
        stack[++top] = a;
        a = path[a];
    }
    stack[++top] = a;
    while (top != -1) {
        cout << stack[top--] << " ";
    }
}