#include "graph.h"

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
    struct ArcNode *nextarc;
} ArcNode;