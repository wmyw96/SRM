### 250pt
#### 算法描述
贪心即可。
#### 备注
+0
#### tags
贪心

### 500pt
#### 算法描述
二分答案（不会超过150，大于150就直接输出-1），之后用部分和做到300^2的check
#### 备注
+0
#### tags
二分答案，部分和优化

### 1000pt
#### 题目描述
给定N个变量x_i，对于第i个变量，他的值必须要在[low_i, up_i]之间，可以是实数。让你最大化
\sum_{i=1}^{N}{\sum_{j=1}^{i-1}{g(i,j) * x_i*x_j}}
g(x,y)是给定的并且只可能是0或者1。
#### 算法描述
考虑把这N个东西分成3类：取最小值，取最大值，取中间。
我们可以证明，如果要使得答案最优，取中间的集合S中一定两两之间的g是1。
为什么呢，考虑两个节点u,v，设val(i)表示x_i，sum(u)表示和u的g值为1的数x的val(x)之和，不妨设sum(u)>=sum(v)，那么把u变大一点点，把v变小一点点，答案会更优。
然后我们继续考虑，设a_i表示取中间的节点i的\sum{j,val(j)取极值}{val(j)}。
要算的答案就是取中间的和取极值的和，还有取中间的和取中间的和。
设M表示maxS-已经确定的i的和。
那么，要算的的式子就是
\sum_{i in S}{x_i*(a_i+(M-x_i)/2)}
无视掉常数项，我们需要最大化\sum_{i in S}{x_i*(a_i-x_i/2)}
我们考虑单个东西，是一个二次函数，在x_i=a_i的时候取最大值。
而且每个东西的下降幅度是一样的。
那么，我一定是让所有的东西到他的最大值表示的x的距离一样，不妨设距离为d。
d=(\sum_{i in S}{a_i}-M)/|S|。
最后x_i=a_i-d
这样又带来了一个问题：这个不在范围内怎么办？
很简单：舍去即可！
为什么，因为如果这样的话，这个数应该取极值啊！
#### 备注
+0
#### tags
函数极值，结论