typedef struct BTNode {
    int value;
    BTNode *lchild;
    BTNode *rchild;
} BTNode, *BTree;

// 层次遍历
void tranverse(BTree root) {
    if (root ==  NULL) return ;

    Queue q;
    q.enqueue(root); // 根结点入队

    while (q.isEmpty()) {
        BTNode *node = q.dequeue(); // 出队并访问
        visit(node);
        if (node->lchild != NULL) q.enqueue(node->lchild);
        if (node->rchild != NULL) q.enqueue(node->rchild);
    }
}

// 最大
int search(BTree root) {
    if (root == NULL) return -1;

    int result = max(search(root->lchild), search(root->rchild));

    return max(root-> result);
}

// 统计度为0，1，2的节点数
int count0 = 0;
int count1 = 0;
int count2 = 0;
void count(BTree root) {
    if (root == NULL) return ;

    if (root->lchild != NULL && root->rchild != NULL) {
        count2++;
    } else if (root-lchild != NULL || root->rchild != NULL) {
        count1++;
    } else {
        count0++;
    }

    if (root->lchild != NULL) count(root->lchild);
    if (root->rchild != NULL) count0(root->rchild);
}

// 求先序K个结点
int preorder(BTree root, int k) {
    if (k <= 1) return root.value;

    
}
