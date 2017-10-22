#include <iostream>
#include <string>
#include <vector>

using namespace std;

// O(N*M)
int deletionDistance( const string& str1, const string& str2 ) 
{
  const int N = str1.length() + 1;
  const int M = str2.length() + 1;
  
  vector<vector<int>> dp;
  dp.resize(N);
  for (int i = 0; i < N; i++)
  {
    dp[i].resize(M);
  }
  
  // Fields are initialized to zero by resize.
  
  for (int i = 0; i < N; i++)
  {
    dp[i][0] = i;
  }
  
  for (int j = 0; j < M; j++)
  {
    dp[0][j] = j;
  }
  
  for (int i = 1; i < N; i++)
  {
    for (int j = 1; j < M; j++)
    {
      char c1 = str1[i-1];
      char c2 = str2[j-1];
      
      if (c1 == c2)
      {
        dp[i][j] = dp[i-1][j-1];
      }
      else
      {
        dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
      }
    }
  }
  
  return dp[N-1][M-1];
}

struct TestCase
{
  string str1;
  string str2;
  int expectedDeletionDistance;
  
  bool Run() const
  {
    int actual = deletionDistance(str1, str2);
    if (actual != expectedDeletionDistance)
    {
      cout << "Test failed. " << str1 << ',' << str2 << ',' << expectedDeletionDistance << ", actual=" << actual << endl;
    }
    return (actual == expectedDeletionDistance);
  }
};

int main() {
  vector<TestCase> cases = {{"dog", "frog", 3},
                            {"some", "some", 0},
                            {"some", "thing", 9},
                            {"", "", 0},
                            {"", "asdf", 4},
                            {"heat", "hit", 3},
                            {"slate", "blots", 6}};
  
  int passCount = 0;
  
  for (const auto& c : cases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  
  cout << "Tests passed. " << passCount << '/' << cases.size() << endl;
  return 0;
}
