class Heap:
	def __init__(self, a):
		self.a = a
		self.len = len(a)
		self._max_heapify()

	# O(n*log(n))
	def sort(self):
		for i in range(self.len):
			self._move_max_to_back()
			self.len -= 1

	def _move_max_to_back(self):
		i = 0
		while i < self.len - 1:
			c1_index = (i * 2) + 1
			c2_index = (i * 2) + 2
			if c2_index > self.len - 1:
				max_index = c1_index
			else:
				if self.a[c1_index] > self.a[c2_index]:
					max_index = c1_index
				else:
					max_index = c2_index
			self._swap(i, max_index)
			i = max_index

	def pop(self):
		self._move_max_to_back()
		max = self.a[self.len - 1]
		del self.a[self.len - 1]
		self.len -= 1
		return max

	# O(n*log(n))
	def _max_heapify(self):
		for i in range(self.len):
			self._insert(i)

	def _insert(self, i):
		while i != 0:
			parent_index = self._parent_index(i)
			if self.a[i] > self.a[parent_index]:
				self._swap(i, parent_index)
				i = parent_index

	def _parent_index(self, i):
		if i == 0:
			return None
		else:
			return int((i-1)/2)

	def _swap(self, i, j):
		tmp = self.a[i]
		self.a[i] = self.a[j]
		self.a[j] = tmp

if __name__ == '__main__':
	h = Heap([0,1,2,3,4,5,6,7,8,9])
	print('heapified: ', h.a)
	h.sort()
	print('post sort: ', h.a)

	h2 = Heap([0,1,2,3,4,5,6,7,8,9])
	while h2.a:
		max = h2.pop()
		print(max)