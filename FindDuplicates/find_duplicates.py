# Assume: All numbers are unique in each array.
# Advancing two pointers approach.
# O(N + M)
# Search for N numbers in M
# O(N*log(M))

# If N==M: Compare O(2N) with O(N*log(N)), Now compare 2 with log(N). When N>4, log(N) > 2.
#   Use advancing two pointers approach.
# If M>>N: Compare O(N+M) with O(N*log(M)), Assume M = N^c. Now compare O(N+N^c) with O(N*log(N^c)), which becomes O(N*c*log(N)).
#   Use search approach.

def binary_search(arr, v):
  start = 0
  end = len(arr) - 1
  while (end >= start):
    mid = (start + end) / 2
    if arr[mid] == v:
      return True
    elif arr[mid] > v:
      end = mid - 1
    else:
      start = mid + 1
  return False

def find_duplicates(arr1, arr2):
  duplicates = []
  
  for v in arr1:
    found = binary_search(arr2, v)
    if found:
      duplicates.append(v)
  
  return duplicates

if __name__ == '__main__':
  print(find_duplicates([1,2,3,5,6,7], [3,6,7,8,20]))
  print(find_duplicates([], []))
  print(find_duplicates([1, 2], [1, 2]))
