#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch( const string &text, const string &pattern ) 
{
  if (text.empty() && pattern.empty())
  {
    return true;
  }
  
  if (pattern.length() >= 2 && pattern[1] == '*')
  {
    // Handle '*'.
    // Zero or more instances.
    bool charMatch = (text[0] == pattern[0]) || pattern[0] == '.';
    return isMatch(text, pattern.substr(2)) 
        || (charMatch && isMatch(text.substr(1), pattern));
  }
  else if (pattern[0] == '.')
  {
    return isMatch(text.substr(1), pattern.substr(1));
  }
  else
  {
    return (text[0] == pattern[0]) && isMatch(text.substr(1), pattern.substr(1));
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
