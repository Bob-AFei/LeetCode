class Solution:
	def maxArea(self, height) -> int:
		ans = 0
		i,j = 0,len(height)-1

		while( i < j ):
			if (height[i] < height[j]): 
				area = height[i]*(j-i)
				i += 1
			else:
				area = height[j]*(j-i)
				j -= 1
			ans  = max(area, ans)
		return ans




height = [1,8,6,2,5,4,8,3,7]
ans = Solution().maxArea(height)
print(ans)