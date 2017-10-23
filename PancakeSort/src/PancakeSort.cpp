#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// O(k)
void flip(vector<int>& arr, int k)
{
  int start = 0;
  int end = k-1;
  
  while (start < end)
  {
    // Swap
    int tmp = arr[start];
    arr[start] = arr[end];
    arr[end] = tmp;
    // Update start and end.
    start++;
    end--;
  }
}

vector<int> pancakeSort(const vector<int>& arrOrig ) 
{
  // Iteratively:
  //    Find largest.
  //    Move largest to its proper position.
  
  vector<int> arr(arrOrig);
  
  for (int end = arr.size() - 1; end > 0; end--)
  {
    // Find largest.
    int largest = -1;
    int largestIndex = -1;
    for (int j = 0; j <= end; j++)
    {
      if (arr[j] > largest)
      {
        largest = arr[j];
        largestIndex = j;
      }
    }
    
    flip(arr, largestIndex+1);
    flip(arr, end+1);
  }
  
  return arr;
}

struct FlipCase
{
  vector<int> arr;
  int k;
  vector<int> expected;
  
  bool Run()
  {
    flip(arr, k);
    
    if (arr != expected)
    {
      cout << "Test failed. " << endl;
    }
    
    return arr == expected;
  }
};

struct SortCase
{
  vector<int> arr;
  
  bool Run()
  {
    auto actual = pancakeSort(arr);
    
    auto expected(arr);
    std::sort(expected.begin(), expected.end());
    
    if (expected != actual)
    {
      cout << "Test failed. " << endl;
    }
    
    return expected == actual;
  }
};

int main() {
  vector<FlipCase> cases = {{{0, 1, 2, 3, 4}, 3, {2, 1, 0, 3, 4}}};
  
  int passCount = 0;
  for (auto& c : cases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  cout << "Flip tests passed: " << passCount << '/' << cases.size() << endl;
  
  vector<SortCase> sortCases = {{{1, 2}}, 
                                {{2, 1}}, 
                                {{1, 5, 4, 3, 2}}, 
                                {{}}, 
                                {{10, 9, 8, 6, 7, 5, 4, 3, 2, 1, 9, 10, 8, 7, 6, 5, 4, 3, 2, 1}}};
  
  passCount = 0;
  for (auto& c : sortCases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  
  cout << "Sort tests passed: " << passCount << '/' << sortCases.size() << endl;
  
  return 0;
}
