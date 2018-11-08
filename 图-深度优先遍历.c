typedef struct ArcNode {
    int adjvex;
    int info;
    ArcNode *nextarc;
} ArcNode;

typedef struct {
    char data;
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;

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