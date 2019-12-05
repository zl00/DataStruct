// 邻接矩阵
typedef struct {
    int edges[MaxSize][MaxSize];
    int n; // 顶点数
    int e; // 边数
} MGraph;

// 邻接表
typedef struct {
    VertexNode vertex[MaxSize];
    int n; // 顶点数
} AGraph;

typedef struct {
    int adjvertex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct {
    int inCount; // 入度
    struct ArcNode * firstarc;
} VertexNode;

// BFS
void bfs(AGraph *G) {
    bool visit[MaxSize];
    for (int i = 0; i < MaxSize; ++i) 
        visit[i] = false;

    for (int i = 0; i < G->n; ++i) {
        if (visit[i] == false) {
            BFS(G, i);
        }
    }
}

void BFS(AGraph *G, int v) {
    if (visit[v] == true) return ;

    Visit(G, v);
    visit[v] = true;

    ArcNode *arc = G->vertex[v].firstarc;

    Queue queue;
    queue.Init();
    while (arc != NULL) {
        if (visit[arc->adjvertex] == false) {
            queue.enQueue(arc);
            arc = arc->nextarc;
        }
    }

    while (queue.isEmpty == false) {
        arc = queue.deQueue();
        Visit(G, arc->adjvertex);
        visit[arc->adjvertex] = true;

        arc = G->vertex[arc->adjvertex].firstarc;
        while (arc != NULL) {
            if (visit[arc->adjvertex] == false) {
                queue.enQueue(arc);
                arc = arc->nextarc;
            }
        }
    }
}

// DFS
int visit[MaxSize] = {0};
void DFS(AGraph *G, int v) {
    if (G == NULL) return ;

    if (visit[v] == 0) {
        Visit(G, v);
        visit[v] = 1;

        ArcNode *p = G->vertex[v].firstarc;
        if (p != NULL) {
            DFS(G, p->adjvertex);
        }
    }
}

void dfs(AGraph *G) {
    if (G == NULL) return ;

    for (int i = 0; i < G->n; i++) {
        DFS(G, i);
    }
}

// Topo
bool hasCircle(AGraph *G) {
    Queue queue;
    queue.Init();

    ArcNode *arc = NULL;
    for (int i = 0; i < G->n; ++i) {
        if (G->vertex[i].inCount == 0) {
            queue.enQueue(i);
        }
    }

    int count = 0;
    while (queue.isEmpty == false) {
        int v = queue.deQueue();
        count++;
        arc = G->vertex[v].firstarc;
        while (arc != NULL) {
            G->vertex[arc->adjvertex].inCount--;
            if (G->vertex[arc->adjvertex].inCount == 0)
                queue.enQueue(arc->adjvertex);
            arc = arc->nextarc;
        }
    }

    return count != G->n;
}