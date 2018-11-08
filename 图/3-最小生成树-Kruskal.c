#include "结构-邻接矩阵.h"

/*
 并查集
    1. 快速合并2个并查集
    2. 快速判断元素是否属于同一个集合
*/
typedef struct {
    int a, b; // a -> b
    int w;
} Road;

Road road[maxSize];

/**
    并查集
*/
int v[maxSize];  // 存放的是前驱

int getRoot(int i) {
    int r = i;
    while (v[r] != r) r = v[r];
    return r;
}

/**
    时间复杂度: 
    适合：与edge有关,适合稀疏图
    核心：每加入一条边，不构成回路。
*/
void Kruskal(MGraph g, int &sum, Road road[]) {
    int a, b, i;
    int N, E;

    N = g.n;
    E = g.e;
    sum = 0;
    for (i = 0; i < N; ++i) v[i] = i; // 初始化并查集
    sort(road, E);

    for (i = 0; i < E; ++i) {
        b = getRoot(road[i].b);
        a = getRoot(road[i].a);

        if (b != a) {
            v[b] = a;
            sum += road[i].w;
        }
    }
}