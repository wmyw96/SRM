# 250pt
## 题目大意
给定一个N行，第i行有i列的类似数字三角形的东西，然后让你染3种颜色，相邻的不能染相同颜色。告诉你三个颜色的数量，问最多能染多少个。
## 算法描述
前3个确定，那么整个三角形也确定了。那么找规律也好，数学推导也好，可以推出通项，接下来是发现很好玩东西，就可以二分做了。
## 备注
+0
## tags
找规律
<!--more-->

# 500pt
## 题目大意
给定一个R`$\times$`C的方格，有些地方有L有些地方有P有些地方是空的，让你选两个不相交的矩形，使得L和P的个数的绝对值差小于等于md的情况下个数和最大。
## 算法描述
枚举分界线（横的竖的都要枚举）然后部分和算一下即可。
## 备注
+0
## tags
部分和，棋盘

# 1000pt
## 题目大意
求1-N之内所有由<=P的质数组成的好数的个数，好数的要求是每个质数的幂次要么是0要么是奇数。
## 算法描述
这题无比吊，直接暴力枚举，然后+一个剪枝就能过了，但是还是感觉有复杂度保证的。
## 备注
+1
RE #1 数组在改算法之后没记得改回来。
## tags
搜索，数论。