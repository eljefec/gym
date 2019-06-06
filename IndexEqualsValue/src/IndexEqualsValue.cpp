#include <iostream>
#include <vector>

using namespace std;

int indexEqualsValueSearch(const vector<int> &arr) 
{
  // Binary search for where index equals value.
  
  int startIndex = 0;
  int endIndex = arr.size() - 1;
  int pivot = arr.size() / 2;
  
  while (startIndex <= endIndex)
  {
    int diff = arr[pivot] - pivot;
    
    if (diff == 0)
    {
      // Return lowest index where index equals value.
      while (pivot > startIndex && arr[pivot-1] == pivot-1)
      {
        pivot--;
      }
      return pivot;
    }
    else
    {
      if (diff > 0)
      {
        endIndex = pivot - 1;
      }
      else if (diff < 0)
      {
        startIndex = pivot + 1;
      }
    }
    
    pivot = (startIndex + endIndex) / 2;
  }
  
  return -1;
}


void print(std::vector<int>& arr)
{
  for (int v : arr)
  {
    std::cout << v << ',';
  }
  std::cout << std::endl;
}

struct TestCase
{
  std::vector<int> arr;
  int expectedOutput;
  
  bool Run()
  {
    int actual = indexEqualsValueSearch(arr);
    if (expectedOutput == actual)
    {
      return true;
    }
    else
    {
      std::cout << "Test failed. " << actual << std::endl;
      print(arr);
      return false;
    }
  }
};

int main() {
  std::vector<TestCase> cases = {{{-8,0,2,5}, 2}, 
                                 {{-1,0,3,6}, -1}, 
                                 {{}, -1}, 
                                 {{0, 1}, 0}, 
                                 {{-1, -1, -1, 3}, 3},
                                 {{-1, -1, -1}, -1}};
  
  size_t passCount = 0;
  for (auto& c : cases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  
  std::cout << "Tests passed: " << passCount << '/' << cases.size() << std::endl;
  
  return 0;
}
