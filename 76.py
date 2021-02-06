class Solution:
	def minWindow(self, s, t) -> str:
		target = { _ : t.count(_) for _ in set(t)}

		left  = 0
		right = 0
		ans   = ""


		# 向右扩展
		for right in range(len(s)):
			# 右边纳入
			if s[right] in target: target[s[right]]-=1

			# 如果合规
			if max(target.values()) <= 0:
				# 从左缩小
				for left in range(left, right+1):
					if s[left] in target: 
						if target[s[left]] == 0 :
							if right-left+1 < len(ans) or len(ans)==0:
								ans = s[left:right+1]
							break
						target[s[left]]+=1
		return ans


# s = "a"
s = "ADOBECODEBANC"
# t = "a"
t = "ABC"
ans = Solution().minWindow(s,t)
print(ans)