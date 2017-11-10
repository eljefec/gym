class Heap:
	def __init__(self, a):
		self.a = a
		self._max_heapify()

	def _max_heapify(self):
		for i in range(len(self.a)):
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
	print(h.a)
	