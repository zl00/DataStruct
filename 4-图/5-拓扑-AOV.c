// AOV: Activity On Vertex network
/**
使用栈：
    1. 入度为0的Vertex入stack
    2. 掏空stack，访问出栈Vertex，并依赖它的节点入度--
*/
int TopoSort(AGraph *G) {
    int i, j, n = 0;
    int stack[maxSize], top = -1; // 栈
    ArcNode *p;

    // 入度为0的点入栈
    for (i = 0; i < G->n; ++i) {
        if (G->adjlist[i].count == 0) {
            stack[++top] = i;
        }
    }

    while (top != -1) {
        i = stack[top--];
        ++n;
        cout << i << " ";
        p = G->adjlist[i].firstarc;

        while (p != NULL) {
            j = p->adjvex;
            --(G->adjlist[j].count);
            if (G->adjlist[j].count == 0) {
                stack[++top] = j;
            }
            p = p->nextarc;
        }
    }

    if (n == G->n) {
        return 1;
    } else {
        return 0;
    }
}


