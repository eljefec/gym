def swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def selection_sort(arr):
    for i in range(len(arr)):
        # Find minimum in unsorted part of array.
        min = arr[i]
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < min:
                min = arr[j]
                min_index = j
        # Swap minimum with first location.
        swap(arr, i, min_index)
    return arr

if __name__ == '__main__':
    print(selection_sort([4, 2, 1, 5, 3]))
