#include "结构-临界表.h"

int visit[maxSize];
void DFS(AGraph *G, int v) {
    ArcNode *p = G.adjlist[v].firstarc;
    visit[v] = 1;
    Visit(v);

    while (p != NULL) {
        if (visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        
        p = p->nextarc;
    }
}

void dfs(AGraph *g) {
    int i = 0;
    for (i = 0; i < g->n; ++i)
        if (visit[i]) == 0)
            DFS(g, i);
}