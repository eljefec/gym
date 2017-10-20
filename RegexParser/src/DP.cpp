#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

bool charsEqual(char t, char pattern)
{
  if (pattern == '.')
  {
    return true;
  }
  else
  {
    return t == pattern;
  }
}

bool isMatch( const string &text, const string &pattern ) 
{
  if (text.empty() && pattern.empty())
  {
    return true;
  }
  
  const int P = pattern.size() + 1;
  const int T = text.size() + 1;
  
  vector<vector<bool>> match;
  
  match.resize(P);
  for (int i = 0; i < P; i++)
  {
    match[i].resize(T);
  }
  
  for (int i = 0; i < P; i++)
  {
    for (int j = 0; j < T; j++)
    {
      match[i][j] = false;
    }
  }
  
  match[0][0] = true;
  
  for (int i = 1; i < P; i++)
  {
    if (i+1 < P && pattern[i] == '*')
    {
      match[i][0] = match[i-1][0];
    }
    else
    {
      match[i][0] = false;
    }
  }
  
  for (int j = 1; j < T; j++)
  {
    for (int i = 1; i < P; i++)
    {
      char t = text[j-1];
      char p = pattern[i-1];
      
      if (i+1 < P && pattern[i] == '*')
      {
        match[i][j] = match[i-1][j]
                  || (match[i][j-1] && charsEqual(t, p));
        
        match[i+1][j] = match[i][j];
        
        i++;
      }
      else
      {
        match[i][j] = match[i-1][j-1] && charsEqual(t, p);
      }
    }
  }
  
  for (int i = 1; i < P; i++)
  {
    if (match[i][T-1])
    {
      return true;
    }
  }
  
  return false;
}
  
struct TestCase
{
  std::string text;
  std::string pattern;
  bool expectedIsMatch;
  
  bool Run() const
  {
    bool actual = isMatch(text, pattern);
    if (expectedIsMatch == actual)
    {
      return true;
    }
    else
    {
      std::cout << "Test case failed. " << text << ',' << pattern << ',' << std::boolalpha << expectedIsMatch << ',' << actual << std::endl;
      return false;
    }
  }
};

int main() 
{
  std::vector<TestCase> cases = {{"", "a", false},
                                 {"", "", true},
                                 {"aa", "a", false},
                                 {"aa", "aa", true},
                                 {"abc", "a.c", true},
                                 {"abbb", "ab*", true},
                                 {"acd", "ab*c.", true},
                                 {"bbb", ".*b", true},
                                 {"bbb", ".*b.*b", true},
                                 {"abbbccc", "a.*b.*c", true}};
  
  size_t passCount = 0;
  
  for (const auto& c : cases)
  {
    bool passed = c.Run();
    if (passed)
    {
      passCount++;
    }
  }
  
  std::cout << "Tests passed: " << passCount << '/' << cases.size() << std::endl;
  return 0;
}
