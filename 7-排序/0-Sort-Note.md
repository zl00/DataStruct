# 基本概念
1. **稳定**：相同的key，排序完后相对位置不发生改变，称之为稳定。

# 种类
### 插入
   1. **直接**
      1. OBGJECT: 想象待排数组分作 [order section][disorder section]
      2. 逻辑: 将DISORDER元素不断插入到ORDER部分的过程 
            ⚠️找到“合适”位置前，要把“不是目标”位置元素往后挪一位
      3. 复杂度
        时间复杂度：o(n²)
        空间复杂度：o(1)
   2. **折半**
      1. 逻辑：在直接插入排序基础上，在“找位置”这步用二分法做了优化。
      2. 复杂度
        时间复杂度：最好o(nlogn), 最差o(n²)
        空间复杂度：o(1)
   3. **希尔(缩小增量排序)** __不用写算法，关注执行流程__
      1. 能手写计算流程
      2. 缩小增量规则：
         1. shell：[n/2], [n/4] ... [1] 时间复杂度：o(n²)
         2. Papernove：[2ᵏ+1], ..., [65], [33], ..., [5], [3], [1] (2ᵏ+1 < n) 时间复杂度：o(n^1.5)
      3. 复杂度：
        时间复杂度见上面
        空间复杂度：o(1)
      4. ⚠️
         1. 增量序列最后一项一定是1

### 交换
   1. **起泡**
      1. 逻辑：遍历待排序数组，通过两两比较交换，将最大数字交换到最上面。（如同起泡般）。
            ⚠️起泡可以提前退出，退出是条件是：一轮遍历，发现没有产生一次交换（原理 a<b, b<c, ..., y<z 大小的传递性，所以说明数组是排序好的）
      2. 复杂度：
        时间复杂度：时间复杂度：o(n²)
        空间复杂度：o(1)
   2. **快速**
      1. 逻辑：图解见“2_SwapSort_Quick_Logic”，想像成 -- “拍手”，左手遇到比枢纽大的值会停在那里，右手遇到比枢纽小的值也会停在那里，然后2个地方的值交换。这样保证左手扫描过的地方满足<枢纽，右手扫描过的地方满足>枢纽。当2只手重合处，就是放置枢纽的地方。
      2. 复杂度：
        空间复杂度：因为递归压栈log₂ᴺ
        时间复杂度：最好Nlog₂ᴺ，最坏N²，平均Nlog₂ᴺ
        
### 选择
   1. **简单**
      1. OBJECT: 想象待排数组分作 [order section][disorder section]
      2. 逻辑：每次从[disorder section]中找到合适的那部分。
      3. “简单选择” 🆚 “直接插入”：
         1. 两者都是分作 order+disorder 两部分；
         2. 前者是从disorder中找到合适的append；后者是将disorder的第一个insert到合适的位置。
      4. 复杂度：
         1. 时间复杂度：（n-1+1)*(n-1)/2，为o(n²)
         2. 空间复杂度： o(1)
   2. **堆**
      1. OBJECT: 
         1. 数组构成平衡二叉树。e.g. [0]为根节点；[1],[2]为其子节点，依此类推。
         2. 父节点 > 子节点
         3. 满足以上2点后，则处于顶端的节点是最大的；
      2. 逻辑：
         1. 第一步--构成平衡二叉树：从最后一个”父节点“往上构成； ⬆︎
         2. 第二步--排序：从当前树的顶端摘取值到相应位置；
         3. 核心逻辑--sift：只要发生了swap，意味着下面的子树也要排序。⬇︎
      3. 复杂度：
        空间复杂度：因为递归压栈 o(1)
        时间复杂度：平均Nlog₂ᴺ

### 归并 （https://www.cnblogs.com/horizonice/p/4102553.html）
   1. **二路归并** 参考[4-MergeSort-Flow](./4-MergeSort-Flow.png)   [4-MergeSort-merge-flow](./4-MergeSort-merge-flow.png)
      1. 思想：分治法 -- 若2个子数组排序OK，则只需“合并”即可。而对子数组而言，同样的逻辑。
      2. 逻辑：虽然 [代码](./4-MergeSort.c)采用递归，此处的递归只是一层外壳，只是为了调用merge操作。
      3. 复杂度：
        空间复杂度：因为递归压栈 o(n)
        时间复杂度：平均Nlog₂ᴺ

### 基数排序
   1. **低位**：
      1. CONCEPT：
         1. n: 关键字个数 e.g. 数组元素个数
         2. rd: 关键字基的个数 e.g. Int型的关键字，那么rd = 10
         3. d: 关键字最大位数 e.g. [100, 99, 21], 那么 d = 3
      2. 逻辑 -- 以数字排序为例，从最低位 ⟼ 最高位 进行排序，当最高位结束时，排序结束。
         1. “分配”+“收集”
         2. 重复d次
      3. 复杂度：
        空间复杂度： o(d(n+rd))
        时间复杂度： o(rd)

### 外排


# 🆚表格
