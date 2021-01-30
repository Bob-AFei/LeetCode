# LeetCode


#### 动态规划

##### 一般解法
> 注意:
> 递归算法为从高到底, 动态规划算法为从底到高!
> 找到转移方程

##### 题目
- No.124 二叉树中的最大路径和
- No.322 零钱兑换


#### 回溯算法

##### 一般解法

> 注意:
> 感觉有点类似于DFS的解法,时间复杂度为N!
```
def backtrack:
	for 选择 in 选择列表:
		# 作出选择
		将该选择从选择列表中移除
		路径.add(选择)
		backtrack(路径, 选择列表)
		# 完成后需要撤销选择
		路径.remove(选择)
		将该选择再次加入到选择列表
```

##### 题目
- No.51 N皇后问题

#### BFS
> 注意在每一轮都要使用一个新的数组去储存下一轮的目标
> 在完成下一轮的目标确定后在进行层数增加

- No. 111 二叉树的最小深度