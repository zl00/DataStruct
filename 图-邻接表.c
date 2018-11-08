typedef struct {
    VNode adjlist[maxSize];
    int n, e;
} AGraph;

typedef struct {
    char data;
    ArcNode *firstarc;
} VNode;

typedef struct ArcNode {
    int adjvex;
    int info;
    struct ArcNode *nextarc;
} ArcNode;