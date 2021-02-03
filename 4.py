# -*- coding: utf-8 -*-
# @Author: Denghui Zhao
# @Date:   2021-01-26 16:50:51
# @Last Modified by:   Denghui Zhao
# @Last Modified time: 2021-01-26 17:02:58


class Solution:
	def findMedianSortedArrays(self, nums1, nums2) -> float:
		
		i,j,cur = 0,0,0
		ans = 0    	

		length = (len(nums1) + len(nums2))
		median = int(length / 2)


		if length % 2 == 0:  pos = (median-1,median) 
		else:  pos = (median,median) 

		while i < len(nums1) and j < len(nums2):
			if nums1[i] < nums2[j]:
				if cur == pos[0]: ans += nums1[i]
				if cur == pos[1]: ans += nums1[i]
				i += 1
				cur += 1

			else:
				if cur == pos[0]: ans += nums2[j]
				if cur == pos[1]: ans += nums2[j]
				j += 1
				cur += 1

		while i < len(nums1):
			if cur == pos[0]: ans += nums1[i]
			if cur == pos[1]: ans += nums1[i]
			i += 1
			cur += 1

		while j < len(nums2):
			if cur == pos[0]: ans += nums2[j]
			if cur == pos[1]: ans += nums2[j]
			j += 1
			cur += 1

		return ans/2

nums1 = []
nums2 = [1]
print (Solution().findMedianSortedArrays(nums1, nums2))