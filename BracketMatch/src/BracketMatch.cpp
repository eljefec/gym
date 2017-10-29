#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bracketMatch( const string& text ) 
{
  //  For each character after any leading close brackets:
  //    If it's an open bracket (i.e., '('), increment unmatchedOpen.
  //    If it's a close bracket (i.e., ')'):
  //      if unmatchedOpen > 0, decrement unmatchedOpen
  //      if unmatchedOpen == 0, increment unmatchedClose
  //  return unmatchedClose + unmatchedOpen;

  const char c_openBracket = '(';
  const char c_closeBracket = ')';
  
  int unmatchedOpen = 0;
  int unmatchedClose = 0;
  
  for (const char c : text)
  {
    if (c == c_openBracket)
    {
      unmatchedOpen++;
    }
    else if (c == c_closeBracket)
    {
      if (unmatchedOpen > 0)
      {
        unmatchedOpen--;
      }
      else if (unmatchedOpen == 0)
      {
        unmatchedClose++;
      }
    }
  }
  return unmatchedClose + unmatchedOpen;
}

struct TestCase
{
  string input;
  int expected;
  
  bool Run() const
  {
    int actual = bracketMatch(input);
    if (expected != actual)
    {
      cout << "Test failed." << input << ',' << expected << ',' << actual << endl;
    }
    
    return (expected == actual);
  }
};

int main() 
{
  vector<TestCase> cases = {{"(()", 1},
                            {"(())", 0},
                            {"())(", 2},
                            {")()", 1},
                            {"(()", 1}};
  
  int passCount = 0;
  for (auto c : cases)
  {
    if (c.Run())
    {
      passCount++;
    }
  }
  
  cout << "Tests passed: " << passCount << '/' << cases.size() << endl;
  
  return 0;
} 
