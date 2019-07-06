import random

def swap(arr, i, j):
    val = arr[i]
    arr[i] = arr[j]
    arr[j] = val

def quick_sort(arr, start, end):
    if end - start <= 1:
        return
    pivot = end - 1
    left = start
    right = pivot - 1
    while left < right:
        if arr[left] <= arr[pivot]:
            left += 1
        else:
            swap(arr, left, right)
            right -= 1

    if arr[left] <= arr[pivot]:
        new_pivot = left + 1
    else:
        new_pivot = left

    swap(arr, new_pivot, pivot)

    quick_sort(arr, start, new_pivot)
    quick_sort(arr, new_pivot + 1, end)

if __name__ == '__main__':
    arr = []
    for i in range(10):
        arr.append(random.randrange(0,1000))

    print('input', arr)

    quick_sort(arr, 0, len(arr))

    print('result', arr)
