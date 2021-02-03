class Solution:

	def numIslands(self, grid) -> int:
		nums = 0
		self.grid = grid

		self.w = len(grid)
		self.h = len(grid[0])

		for i in range(self.w):
			for j in range(self.h):
				if grid[i][j] == "1":
					nums += 1
					self.traverseIslends(i,j)
		return nums

	def traverseIslends (self, i, j):
		grid[i][j] = 0
		if i > 0 and grid[i-1][j] == "1": self.traverseIslends(i-1, j)
		if i < self.w-1 and grid[i+1][j] == "1": self.traverseIslends(i+1, j)
		if j > 0 and grid[i][j-1] == "1": self.traverseIslends(i, j-1)
		if j < self.h-1 and grid[i][j+1] == "1": self.traverseIslends(i, j+1)

grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]

ans = Solution().numIslands(grid)
print(ans)