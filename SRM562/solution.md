### 250pt
#### 算法描述
模拟即可。
#### 备注
+0
#### tags
模拟

### 500pt
好神的计算几何...

### 1000pt
#### 题目大意
给定一个N个节点的树，你现在要给N个节点重新标号，使得对于点集{1,2,..k},{2,3..k+1},..{n-k+1.n-k+2,..,n}，他们在这棵树上的导出子树的点数都是k。
#### 算法描述
这题的关键，就是yy出最后的形状。
考虑2k<=n，那么，一定是中间一条长链，然后两边都挂着大小为K的子树，如下图。
-------------------------------------------------
|  [STA] - (k+1) - (k+2) - ... - (n-k) - [STB]  |
-------------------------------------------------   Image1

STA怎么染色，实际上就是所有的儿子都要比父亲小，问染色的方案数，就是一个用组合数的dp，我们用f[x][p]表示x节点父亲为p的染色总方案数。
显然STB类似于STA。
然后这个就可以做了。
当2k>n怎么办？
我们考虑其实形状是这样的：中间有一个很大的联通块是2k-n，联通块的一些节点连着一颗子树，要么是在[1,v]里的，要么是在[n-v+1,n]里的，那么，我们可以在这基础上做一个二维背包就可以了。
但是，注意到，我们求的是：以i为联通块中的root，所以要乘(2k-n)!，但是这样也是错的，同一个联通块会被计算到(2k-n)次，除去就可以了。
#### 备注
+0
(wt)
这题注意两点：
dp有的时候要考虑最后的状态
容斥也可以用除法来做（当个数确定的时候）
#### tags
树形dp，结论，树上背包，容斥
