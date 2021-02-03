"""
# Definition for a Node.
class Node:
	def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
		self.val = int(x)
		self.next = next
		self.random = random
"""

class Solution:
	def trap(self, height) -> int:
		dp = [0 for _ in height]
		left_max  = 0
		right_max = 0

		for i in range(len(height)):
			left_max = max(left_max, height[i])
			dp[i] = left_max

		for i in range(1,len(height)+1):
			right_max = max(height[-i], right_max)
			dp[-i] = min(right_max,dp[-i])-height[-i]

		return sum(dp)



a = [4,2,0,3,2,5]

ans = Solution().trap(a)

print(ans)