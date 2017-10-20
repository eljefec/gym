import numpy as np

def sort_k_messed_array(arr, k):
  # Slide a 2k+1 sized window across arr. Need to sort N/k such windows.
    # Sort within that window. O(k*log(k))
  # Overall: O(N*log(k))
  
  arr = np.array(arr)
  
  step = k+1
  
  end = step * ((len(arr) / step))
  
  for start in range(0, end, step):
    window_size = 2 * k + 1
    arr[start:start+window_size].sort()
  
  return arr.tolist()

if __name__ == '__main__':
  arr = [1, 4, 5, 2, 3, 7, 8, 6, 10, 9]
  k = 2
  
  actual = sort_k_messed_array(arr, k)
  
  assert(sorted(arr) == actual)
  
