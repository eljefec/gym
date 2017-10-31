def bubble_sort(arr):
    for i in range(len(arr), 0, -1):
        print(i)
        for j in range(i - 1):
            print(j)
            if arr[j] > arr[j + 1]:
                tmp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = tmp
    return arr

if __name__ == '__main__':
    print(bubble_sort([4, 2, 1, 5, 3]))
