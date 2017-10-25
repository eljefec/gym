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
  
  int rightCol = inputMatrix[0].size() - 1;
  int leftCol = 0;
  int topRow = 0;
  int bottomRow = inputMatrix.size() - 1;
  
  while (topRow <= bottomRow && leftCol <= rightCol)
  {
    for (int i = leftCol; i <= rightCol; i++)
    {
      output.push_back(inputMatrix[topRow][i]);
    }
    
    topRow += 1;
    
    for (int i = topRow; i <= bottomRow; i++)
    {
      output.push_back(inputMatrix[i][rightCol]);
    }
    
    rightCol -= 1;
    
    if (topRow > bottomRow || leftCol > rightCol)
    {
      return output;
    }
    
    for (int i = rightCol; i >= leftCol; i--)
    {
      output.push_back(inputMatrix[bottomRow][i]);
    }
    
    bottomRow -= 1;
    
    for (int i = bottomRow; i >= topRow; i--)
    {
      output.push_back(inputMatrix[i][leftCol]);
    }
    
    leftCol += 1;
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
