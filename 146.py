class LRUCache:

	def __init__(self, capacity):
		self.queue = []
		self.dict  = {}
		self.capacity = capacity

	def get(self, key) -> int:
		if key in self.queue:
			self.to_top(key)
			return self.dict[key]
		else: return -1

	def put(self, key, value) -> None:
		if key in self.queue: self.to_top(key)
		else: self.queue.append(key)
		self.dict[key] = value

		if len(self.queue) > self.capacity: 
			key = self.queue.pop(-1)
			self.dict.pop(key)

	def to_top (self, key):
		self.queue.remove(key)
		self.queue.insert(0,key)
