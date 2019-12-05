typedef struct {
    int value;
    BTNode *lchild;
    BTNode *rchild;
} BTNode, *BTree;

/// 层次遍历
void level_tranverse(BTree tree) {
    if (tree == NULL) return ;

    Queue queue; // 队列用于缓存结点
    queue.enQueue(tree);

    while (queue.isEmpty() == false) {
        BTNode *p = queue.deQueue(); // 从队列中退出一个结点
        visit(p); // 访问该结点
        if (p->lchild != NULL) queue.enQueue(p->lchild);
        if (p->rchild != NULL) queue.enQueue(p->rchild);
    }
}

/// 统计度为0，1，2的节点数
int count0 = 0; // 度为0的结点数
int count1 = 0; // 度为1的结点数
int count2 = 0; // 度为2的结点数

void count(BTNode *node) {
    if (node == NULL) return ;

    if (node->lchild != NULL && node->rchild != NULL) count2++;
    else if (node->lchild != NULL || node->rchild != NULL) count1++;
    else count0++;

    if (node->lchild != NULL) count(node->lchild);
    if (node->rchild != NULL) count(node->rchild);
}


/// 从大到小输出二叉排序树中不小于K的关键字
// 用栈来缓存遍历的数据，兼顾利用栈后进先出的特性将数字的顺序倒置
void inorder(BTNode *p, Stack &stack) {
    if (p == NULL) return ;

    if (p->lchild != NULL) inorder(p->lchild, stack);
    stack.push(p->value);
    if (p->rchild != NULL) inorder(p->rchild, stack);
}

void print(BTree tree, int k) {
    Stack stack;
    inorder(tree, stack);

    while (stack.isEmpty == false) {
        int value = stack.pop();
        if (value < k) break;
        print(value);
    }
}

// 翻转二叉树
void mirror(BTNode *root) {
    if (root == NULL) return ;
    
    BTNode *temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;

    if (root->lchild) mirror(root->lchild);
    if (root->rchild) mirror(root->rchild);
}

// 二叉树是否相似：（相似是指结构相似）
bool resemble(BTNode *r1, BTNode *r2) {
    if ((r1 != NULL && r2 == NULL) || (r2 != NULL && r1 == NULL))
        return false;

    if (resemble(r1->lchild, r2->lchild) == false) {
        return false;
    }

    if (resemble(r1->rchild, r2->rchild) == false) {
        return false;
    }

    return true;
}

// 判断完全二叉树

bool isCompleteBinaryTree(BTNode *root) {
    if (root == NULL) return false; // 参数错误

    bool nullNode = false;

    Queue queue;
    queue.Init();
    queue.enQueue(root);

    while(queue.isEmpty == false) {
        BTNode *p = queue.deQueue();

        // 结点前面有空结点，不为完全二叉树
        if (p != NULL && nullNode == true) { 
            return false;
        } else if (p == NULL) {
            nullNode = true;
        } else {
            queue.enQueue(p->lchild);
            queue.enQueue(p->rchild);
        }
    }
    
    return true;
}

// 计算二叉树宽度
int width(BTNode *root) {
    if (root == NULL) return -1; // 非法值

    Queue queue;
    queue.Init();
    queue.enQueue(root);

    int w = 0; // 宽度

    while (queue.isEmpty == false) {
        BTNode *array[MaxSize];

        int i = 0;
        for (i = 0; i < MaxSize; ++i) array[i] = NULL; // 初始化
        
        i = 0;
        while (queue.isEmpty == false) {
            array[i++] = queue.deQueue(); // 将这层所有结点出队并放入array中
        }

        w = max(i, w); // 更新宽度

        for (int j = 0; j < i; j++) { // 将这层的所有子结点入队
            BTNode *p = array[j];
            if (p->lchild != NULL) queue.enQueue(p->lchild);
            if (p->rchild != NULL) queue.enQueue(p->rchild);
        }
    }

    return w;
}

// 自下而上、从右到左
void tranverse(BTNode *root) {
    if (root == NULL) return ;

    Stack stack;
    stack.Init();

    Queue queue;
    queue.Init();
    queue.enQueue(root);
    
    while (queue.isEmpty == false) {
        BTNode *p = queue.deQueue();
        stack.push(p);
        if (p->lchild) queue.enQueue(p->lchild);
        if (p->rchild) queue.enQueue(p->rchild);
    }

    while (stack.isEmpty == false) {
        BTNode *p = stack.pop();
        print(p->value);
    }
}

// 二叉排序树中插入结点
BTNode* find(BTNode *root, int value) {
    if (root == NULL) return NULL;

    if (root->value == value)  {
        return NULL;
    }
    else (root->value < value) { // 比根节点大，插入到右子树
        if (root->rchild != NULL) {
            return find(root->rchild, value);
        } else {
            return root;
        }
    }
    else (root->value > value) { // 比根节点小，插入到左子树
        if (root->lchild != NULL) {
            return find(root->lchild, value);
        } else {
            return root;
        }
    }
    
    return NULL;
}
bool insert(BTNode *root, int value) {
    BTNode *p = find(root, value);
    if (p == NULL) return false;

    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->value = value;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if (value < p->value) p->lchild = newNode;
    else p->rchild = newNode;
}

// 是否是二叉排序树
bool isBinarySortTree(BTNode *root) {
    if (root == NULL) return false;

    if (root->lchild != NULL) {
        if (root->lchild->value >= root->value) {
            return false;
        } else {
            isBinarySortTree(root->lchild);
        }
        
    } else if (root->rchild != NULL) {
        if (root->rchild->value <= root->value) {
            return false;
        } else {
            isBinarySortTree(root->rchild);
        }
        
    }

    return true;
}

// 带权路径长度：定义 - 叶子结点 * 路径长度
int count(BTNode *root, int level = 0) {
    if (root == NULL) return 0;

    if (root->lchild == NULL && root->rchild == NULL) { // root为叶子结点
        return root->value * level;
    }

    int result = 0;
    if (root->lchild != NULL) result += count(root->lchild, level + 1);
    if (root->rchild != NULL) result += count(root->rchild, level + 1);
    return result;
}

// 树的高度：叶子结点的高度是1
int height(BTNode *root) {
    if (root == NULL) return 0;

    return max(height(root->lchild), height(root->rchild)) + 1;
}

// 判断是否是平衡二叉树
bool isBalanceBinaryTree(BTNode *root) {
    if (root == NULL) return true;

    int leftheight = height(root->lchild);
    int rightheight = height(root->rchild);

    if (abs(leftheight - rightheight) > 1) {
        return false;
    } else if (isBalanceBinaryTree(root->lchild) && isBalanceBinaryTree(root->rchild)) {
        return true;
    } else {
        return false;
    }
}