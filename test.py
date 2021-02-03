
class Solution:
	def minWindow(self, s, t) -> str:
		target = { _ : t.count(_) for _ in set(t)}

		left  = 0
		right = 0

		ans_left  = -10000
		ans_right = -1

		for right in range(len(s)):


			if s[right] in target: target[s[right]]-=1
			
			if not any(target.values()) > 0:

				for left in range(left, right):
					if s[left] in target: 
						if target[s[left]] == 0:
							if right - left < ans_right - ans_left:
								ans_left,ans_right = left,right
								break
						target[s[left]]+=1

		return s[ans_left:ans_right]




s = "ADOBECODEBANC"
t = "AB"
ans = Solution().minWindow(s,t)
print(ans)