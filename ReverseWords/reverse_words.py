def flip(arr, start, end):
  while start < end:
    tmp = arr[start]
    arr[start] = arr[end]
    arr[end] = tmp
    
    start += 1
    end -= 1
    
def reverse_words(arr):
  # Find words.
  start = 0
  for i in range(len(arr)):
    if arr[i] == ' ':
      # Reverse word.
      flip(arr, start, i-1)
      start = i+1

  # Reverse final word, if necessary.
  flip(arr, start, len(arr)-1)
  
  # Reverse entire string.
  flip(arr, 0, len(arr) - 1)
  
  return arr

if __name__ == '__main__':
  arr = ['p', 'e', 'r', 'f', 'e', 'c', 't']
  flip(arr, 0, len(arr)-1)
  print(arr)
  flip(arr, 3, len(arr)-1)
  print(arr)
  
  arr = ['p', 'e', 'r', 'f', 'e', 'c', 't', ' ',
         'm', 'a', 'k', 'e', 's', ' ',
         'p', 'r', 'a', 'c', 't', 'i', 'c', 'e']
  reverse_words(arr)
  
  print(arr)
