## 二叉树定义
1. 结点的度：这个结点有几个分支；相应的“树的度”：max{结点的度}；
2. 满二叉树：连叶子结点都是满的；完全二叉树：结点前没有空洞。

## 二叉树性质
1. N0 = N2 + 1 "叶子结点"数与"有2个孩子结点"数量关系
   ∵ N0 + N1 + N2 = N1 + 2N2 + 1 （结点数 = 分支数 + 1） 
   ➜ N0 = N2 + 1
2. TODO:


## 二叉树数据结构
1. 双亲表示法：用数组存储双亲结点下标。目的是溯源，并查集就是此应用。
2. 孩子表示法/孩子兄弟表示法：用链表。

## 二叉树遍历

### 遍历定义
[execute flow](https://github.com/zl00/DataStruct/tree/master/树/tree-base-excecute-flow.jpg "traverse exec flow")
无论前/中/后序遍历，都使用上图中的递归执行流。

### 利用系统栈
#### 算法参考1-XXX.c
搞清楚“遍历定义”，就很好理解。

#### 应用
1. 求表达式(a - (b + c)) * (d / e)的值（叶子结点是数值，其他结点是运算符号， 见【6-1】）
2. 求二叉树深度，二叉树以二叉树链表为存储方式。[depth](./2-depth.c)
3. 以二叉树链表为存储方式的二叉树，搜索其中是否包含key，有则指向该结点，否则返回NULL。[search](./2-search.c) **cut branch**

### 利用自定义栈
原理：入栈元素等候处理，出栈时visit
参考**3-XXX.c**

### 线索二叉树

## 树与二叉树转换

## 森林与二叉树转换

## Huffman树


## 平衡二叉树插入
http://www.iqiyi.com/w_19ru8hixdx.html