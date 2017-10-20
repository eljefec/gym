#include <iostream>
#include <vector>

using namespace std;

class IslandCounter
{
public:
  static int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
  {
    if (binaryMatrix.empty())
    {
      return 0;
    }
    else if (binaryMatrix[0].empty())
    {
      return 0;
    }

    IslandCounter counter = IslandCounter(binaryMatrix);

    return counter.getNumberOfIslands();
  }
  
private:
  IslandCounter(const vector<vector<int>>& binaryMatrix)
    : islandCount(0),
      binaryMatrix(binaryMatrix)
  {
    rows = binaryMatrix.size();
    cols = binaryMatrix[0].size();

    islands.resize(rows);

    for (int i = 0; i < rows; i++)
    {
      islands[i].resize(cols);
    }  
  }
  
  int getNumberOfIslands()
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        if (binaryMatrix[i][j] == 1 && islands[i][j] == 0)
        {
          islandCount++;

          markIsland(i, j);
        }
      }
    }
    
    return islandCount;
  }
  
  void checkIsland(int i, int j)
  {
    if (i >= 0 && j >= 0 && i < rows && j < cols
        && binaryMatrix[i][j] == 1 && islands[i][j] == 0)
    {
      markIsland(i, j);
    }  
  }
  
  void markIsland(int i, int j)
  {    
    islands[i][j] = islandCount;

    checkIsland(i - 1, j);
    checkIsland(i, j - 1);
    checkIsland(i + 1, j);
    checkIsland(i, j + 1);
  }
    
  const vector<vector<int>>& binaryMatrix;
  int rows;
  int cols;
  int islandCount;
  vector<vector<int>> islands;
};

int getNumberOfIslands( const vector<vector<int>>& binaryMatrix ) 
{
  return IslandCounter::getNumberOfIslands(binaryMatrix);
}

struct TestCase
{
  std::vector<vector<int>> binaryMatrix;
  int expectedNumberOfIslands;
  
  bool Run()
  {
    int actual = getNumberOfIslands(binaryMatrix);
    if (expectedNumberOfIslands == actual)
    {
      return true;
    }
  }
};

int main() 
{
  vector<TestCase> cases = {{{{1}}, 1},
                            {{{1},{0}}, 1},
                            {{{0, 1, 0, 1}}, 2},
                            {{{1, 0, 1, 0}, {0, 1, 1, 1}, {0, 0, 1, 0}}, 2},
                            {{{1, 0, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}}, 1}
                           };
  
  int passCount = 0;
  
  for (auto& c : cases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  
  cout << "Tests passed: " << passCount << '/' << cases.size() << endl;
  
  return 0;
}
