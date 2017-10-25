#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralCopy( const vector<vector<int>>& inputMatrix ) 
{
  if (inputMatrix.empty())
  {
    return {};
  }
  else if (inputMatrix[0].empty())
  {
    return {};
  }
  
  vector<int> output;
  
  // inputMatrix[i] is row i.
  // inputMatrix[i][j] is column j in row i.
  
  int rightEdge = inputMatrix[0].size() - 1;
  int leftEdge = 0;
  int topEdge = 0;
  int bottomEdge = inputMatrix.size() - 1;
  
  // rightEdge: 4, leftEdge: 0, topEdge: 0, bottomEdge: 3
  // rightEdge: 4, leftEdge: 0, topEdge: 1, bottomEdge: 3
  // rightEdge: 3, leftEdge: 0, topEdge: 1, bottomEdge: 3
  // rightEdge: 3, leftEdge: 0, topEdge: 1, bottomEdge: 2
  // rightEdge: 3, leftEdge: 1, topEdge: 1, bottomEdge: 2
  // rightEdge: 3, leftEdge: 1, topEdge: 2, bottomEdge: 2
  // rightEdge: 2, leftEdge: 1, topEdge: 2, bottomEdge: 2
  // rightEdge: 2, leftEdge: 1, topEdge: 2, bottomEdge: 1
  // Want to continue while topEdge <= bottomEdge && leftEdge <= rightEdge
  
  while (topEdge <= bottomEdge && leftEdge <= rightEdge)
  {
    for (int i = leftEdge; i <= rightEdge; i++)
    {
      output.push_back(inputMatrix[topEdge][i]);
    }
    
    topEdge += 1;
    
    for (int i = topEdge; i <= bottomEdge; i++)
    {
      output.push_back(inputMatrix[i][rightEdge]);
    }
    
    rightEdge -= 1;
    
    if (topEdge > bottomEdge || leftEdge > rightEdge)
    {
      return output;
    }
    
    for (int i = rightEdge; i >= leftEdge; i--)
    {
      output.push_back(inputMatrix[bottomEdge][i]);
    }
    
    bottomEdge -= 1;
    
    for (int i = bottomEdge; i >= topEdge; i--)
    {
      output.push_back(inputMatrix[i][leftEdge]);
    }
    
    leftEdge += 1;
  }
  
  return output;
}

int main() 
{
  const auto actual = spiralCopy({{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20}});

  const vector<int> expected = {1, 2, 3, 4, 5, 10, 15, 20, 19, 18, 17, 16, 11, 6, 7, 8, 9, 14, 13, 12};
  
  if (actual == expected)
  {
    cout << "Test passed. " << endl;
  }
  else
  {
    cout << "Test failed. " << endl;
  }
  return 0;
}
