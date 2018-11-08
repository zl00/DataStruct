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
void BFS(AGraph *G, int v) {
    int j;
    ArcNode *p;
    int que[maxSize], front = 0, rear = 0;

    visit[v] = 1;
    Visit(v);

    rear = (rear+1)%maxSize;
    que[rear] = v;

    while (front != rear) {
        front = (front+1)%maxSize;
        j = que[front];
        p = G.adjlist[j].firstarc;

        while (p != NULL) {
            if (visit[p->adjvex] == 0) {
                visit[p->adjvex] = 1;
                Visit(p->adjvex);

                rear = (rear+1)%maxSize;
                que[rear] = p->adjvex;
            }

            p = p->nextarc;
        }
    }

}

void bfs(AGraph *g) {
    int i = 0;
    for (i = 0; i < g->n; ++i)
        if (visit[i] == 0)
            BFS(g, i);
}