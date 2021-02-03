"""
# Definition for a Node.
class Node:
	def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
		self.val = int(x)
		self.next = next
		self.random = random
"""

class Solution:

	def __init__ (self):
		self.visited = {}

	def copyRandomList(self, head):

		if head == None: return None

		node = None
		if head in self.visited: 
			node = self.visited[head]
		else:
			node = Node(head.val, None, None)
			self.visited[head] = node

		node.next = self.copyRandomList(head.next)
		node.random = None if head.random is None else self.visited[head.random] 
		return node