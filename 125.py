# -*- coding: utf-8 -*-
# @Author: Denghui Zhao
# @Date:   2021-01-27 14:50:15
# @Last Modified by:   Denghui Zhao
# @Last Modified time: 2021-01-27 16:26:07



class Solution:
    def isPalindrome(self, s) -> bool:
    	s = s.lower()
    	i = 0
    	j = len(s)-1

    	while(i < j):
    		if not s[i].isalnum(): i+=1; continue
    		if not s[j].isalnum(): j-=1; continue
    		if not s[i] == s[j]: return False
    		i+=1
    		j-=1
    	return True



s = "A man, a plan, a canal: Panama"
ans = Solution().isPalindrome(s)
print(ans)