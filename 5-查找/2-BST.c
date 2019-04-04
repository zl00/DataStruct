/* define */
typedef struct BTNode {
    int key;
    struct BTNode * lchild;
    struct BTNode * rchild;
} BTNode;

/* search */
BTNode* BSTSearch(BTNode *bt, int key) {
    if (bt == NULL) return NULL;

    if (bt->key == key) {
        return bt;
    } else if (key < bt->key) {
        return BSTSearch(bt->lchild, key);
    } else {
        return BSTSearch(bt->rchild, key);
    }
}

/* insert */
int BSTInsert(BTNode *&bt, int key) {
    if (bt == NULL) {
        bt = (BTNode *)malloc(sizeof(BTNode));
        bt->lchild = bt->rchild = NULL;
        bt->key = key;
    } else {
        if (key == bt->key) 
            return 0;
        else if (key < bt->key)
            return BSTInsert(bt->lchild, key);
        else
            return BSTInsert(bt->rchild key);
    }
}

/* create */
void CreateBST(BTNode *&bt, int key[], int n) {
    int i;
    bt = NULL;
    for (i = 0; i < n; ++i) {
        BSTInsert(bt, key[i]);
    }
}

/* delete */
int BSTDelete(BTNode *bt, int key) {
    BTNode* node = BSTSearch(bt, key);
    if (node == NULL) return 0;

    //...
}
