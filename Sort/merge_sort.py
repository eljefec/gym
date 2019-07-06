import random

class Span:
    def __init__(self, arr, start = 0, end = None):
        self.arr = arr
        self.start = start
        self.end = end
        if end is None:
            self.end = len(arr)

    def len(self):
        return self.end - self.start

    def split(self):
        middle = self.start + (self.end - self.start) / 2
        return [Span(self.arr, self.start, middle), Span(self.arr, middle, self.end)]

    def copy(self, other):
        assert(self.start == other.start and self.len() == other.len())
        for i in range(self.start, self.end):
            self.arr[i] = other.arr[i]

    def debug(self):
        print(self.arr[self.start:self.end])

def merge(a, b, target):
    assert(target.len() == a.len() + b.len())

    print('merging...')
    a.debug()
    b.debug()
    target.debug()

    t_i = target.start
    a_i = a.start
    b_i = b.start

    while a_i < a.end and b_i < b.end:
        if a.arr[a_i] < b.arr[b_i]:
            target.arr[t_i] = a.arr[a_i]
            a_i += 1
        else:
            target.arr[t_i] = b.arr[b_i]
            b_i += 1
        t_i += 1

    while a_i < a.end:
        target.arr[t_i] = a.arr[a_i]
        a_i += 1
        t_i += 1

    while b_i < b.end:
        target.arr[t_i] = b.arr[b_i]
        b_i += 1
        t_i += 1

    print('result:')
    target.debug()

def debug(split):
    print(split[0].len(), split[1].len())

def merge_sort_recursive(arr_span, target_span):
    assert(arr_span.len() == target_span.len())
    if arr_span.len() == 1:
        target_span.copy(arr_span)
        return
    split_arr = arr_span.split()
    split_target = target_span.split()
    merge_sort_recursive(split_arr[0], split_target[0])
    merge_sort_recursive(split_arr[1], split_target[1])

    # Temporarily use arr_span to store merged result.
    merge(split_target[0], split_target[1], arr_span)
    # Copy result into target.
    target_span.copy(arr_span)

def merge_sort(arr):
    target_arr = [None] * len(arr)
    merge_sort_recursive(Span(arr), Span(target_arr))
    return target_arr

def test(arr):
    print('input:', arr)
    result = merge_sort(arr)
    print('result:', result)

if __name__ == '__main__':
    test(random.sample(range(1,100), 10))
