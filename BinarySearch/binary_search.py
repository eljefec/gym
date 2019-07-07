import random

# Assume arr is sorted.
def binary_search(arr, v):
    if len(arr) < 1:
        return None
    start = 0
    end = len(arr) - 1
    while start <= end:
        mid = start + (end - start) / 2
        if arr[mid] == v:
            return mid
        elif arr[mid] < v:
            start = mid + 1
        else:
            end = mid - 1
    return None

def test(arr, val):
    arr.sort()
    result = binary_search(arr, val)
    if result is None:
        print('Value not found.', val, arr)
    else:
        print('Value found.', result, arr[result], arr)

if __name__ == '__main__':
    test(random.sample(range(1,100), 80), 37)
