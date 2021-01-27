# -*- coding: utf-8 -*-next_loop
# @Author: Denghui Zhao
# @Date:   2021-01-27 14:50:15
# @Last Modified by:   Denghui Zhao
# @Last Modified time: 2021-01-27 16:26:05



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def levelOrder(self, root):
        self.ans = []
        if root == None: return self.ans
        current_loop = []
        current_loop += [root]
        self.bfs(current_loop)
        return self.ans

    def bfs (self, current_loop):
        next_loop = []
        this_level = []

        for node in current_loop:
            this_level += [node.val]
            if not node.left == None: next_loop += [node.left]
            if not node.right == None: next_loop += [node.right]

        self.ans += [this_level]
        if len(next_loop) > 0 : self.bfs (next_loop)