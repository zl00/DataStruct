#include "结构-邻接表.h"

int visit[maxSize];
void BFS(AGraph *G, int v) {
    int j;
    ArcNode *p;

    /** 
    QUEUE
    
    存放的节点是：已经访问了，但是还没处理其邻边
    Queue空标志：front == rear
    */
    int que[maxSize], front = 0, rear = 0;

    visit[v] = 1;
    Visit(v);

    rear = (rear+1)%maxSize;
    que[rear] = v;

    while (front != rear) {
        front = (front+1)%maxSize;
        j = que[front];
        p = G.adjlist[j].firstarc;

        while (p != NULL) { // 遍历j节点所有邻边
            if (visit[p->adjvex] == 0) {
                visit[p->adjvex] = 1; // 入队列就设置为1，免得节外生枝。
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