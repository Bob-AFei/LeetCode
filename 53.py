# -*- coding: utf-8 -*-
# @Author: Denghui Zhao
# @Date:   2021-01-26 17:09:37
# @Last Modified by:   Denghui Zhao
# @Last Modified time: 2021-01-27 09:31:24


class Solution:
    def maxSubArray(self, nums) -> int:
    	ans = nums[0]
    	tem_ans = nums[0]

    	for num in nums[1:]:
    		tem_ans = max(num, num+tem_ans)
    		ans     = max(tem_ans, ans)

    	return ans