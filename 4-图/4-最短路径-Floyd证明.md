Floyd证明以来以下2点：

1.
若 (a -> b -> c -> d -> e) 是 MinPath(a,e)，
那么(a -> b -> c)必然是MinPath(a,c).简而言之，最短路径的子路径必然是最短路径。

证明：（反证法）
(a -> b -> c -> d -> e) 是 MinPath(a,e)
假设(a -> b -> c)不是(a,c)最短路径，则(a -> b -> c -> d -> e) 
不是 MinPath(a,e)。与结论矛盾。


2. https://blog.csdn.net/ljhandlwt/article/details/52096932
假设i和j之间的最短路径上的结点集里(不包含i,j),编号最大的一个是x.
那么在外循环k=x时,d[i][j]肯定得到了最小值.

证明：
D(i,j) 最短路径为 i -> x1 -> x -> x2 -> j，且 x1 < x, x2 < x.

假设结论成立,则 
=> 
① D(i, x), K = x1时： i -> x1 -> x是MinPath(i, x)
② D(x, j), K = x2时： x -> x2 -> j是MinPath(x, j)

∴ i -> x1 -> x -> x2 -> j 是 MinPath(i, j)


3. 动态规划 Dynamic Programming
① 最优子结构 d[i][j]=min(d[i][j], d[i][k]+d[k][j])

❓还没有彻底想清楚