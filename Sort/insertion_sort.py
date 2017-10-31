def find_location(arr, i):
    for j in range(i-1, -1, -1):
        if arr[j] < arr[i]:
            return j+1
    return 0

def insertion_sort(arr):
    for i in range(1, len(arr)):
        target_index = find_location(arr, i)
        save = arr[i]
        for j in range(i, target_index-1, -1):
            arr[j] = arr[j-1]
        arr[target_index] = save
    return arr


if __name__ == '__main__':
    print(insertion_sort([4, 2, 1, 5, 3]))
