# -*- coding: utf-8 -*-
# @Author: Denghui Zhao
# @Date:   2021-01-27 14:31:28
# @Last Modified by:   Denghui Zhao
# @Last Modified time: 2021-01-27 14:48:24



class Solution:
	def merge(self, nums1, m, nums2, n) -> None:
		i,j = 0,0
		while(i < m and j < n):
			if nums1[i] < nums2[j]: i +=1
			else:
				nums1.insert(i,nums2[j])
				nums1.pop(-1)
				i+=1
				m+=1
				j+=1
		while(j < n):
			nums1[i] = nums2[j]
			i += 1
			j += 1
		return nums1



nums1 = [-1,0,0,3,3,3,0,0,0]
m = 6
nums2 = [1,2,2]
n = 3

a = Solution().merge(nums1, m, nums2, n)
print(a)



