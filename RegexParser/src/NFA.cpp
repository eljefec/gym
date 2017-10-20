#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct NextState;

class State
{
public:
  static State* BuildStateMachine(const string& pattern);
    
  std::vector<State*> Input(char c);
  
  bool IsFinish() const;
      
private:
  State(bool isFinish, const std::vector<char>& selfTransition, NextState* nextState);
  
  bool m_isFinish;
  std::vector<char> m_selfTransition;
  NextState* m_nextState;
};

struct NextState
{
  const char m_input;
  State* m_state;
};

State::State(bool isFinish, const std::vector<char>& selfTransition, NextState* nextState)
  : m_isFinish(isFinish),
    m_selfTransition(selfTransition),
    m_nextState(nextState)
{
}

const char c_wildcard = '.';

std::vector<State*> State::Input(char c)
{
  std::vector<State*> nextStates;
  if (m_nextState)
  {
    NextState& next = *m_nextState;
    if (c == next.m_input || next.m_input == c_wildcard)
    {
      nextStates.push_back(next.m_state);
    }
  }
  
  for (char selfTransition : m_selfTransition)
  {
    if (c == selfTransition || selfTransition == c_wildcard)
    {
      nextStates.push_back(this);
    }
  }
  
  return nextStates;
}

bool State::IsFinish() const
{
  return m_isFinish;
}

State* State::BuildStateMachine(const string& pattern)
{
  State* next = nullptr;
  
  bool isFinish = true;
  
  for (int i = pattern.length() - 1; i >= 0; i--)
  {
    if (pattern[i] == '*')
    {
      i--;
      
      std::vector<char> selfTransition = {pattern[i]};

      NextState* nextState = nullptr;
      if ((i + 2) < pattern.length())
      {
        selfTransition.push_back(pattern[i + 2]);
        nextState = new NextState{pattern[i + 2], next};
      }

      State* state = new State(isFinish, selfTransition, nextState);
      next = state;
    }
    else
    {
      State* state = new State(isFinish, {}, new NextState{pattern[i], next});
      next = state;
      
      isFinish = false;
    }
  }
  
  return next;
}

bool isMatch( const string &text, const string &pattern ) 
{
  State* state = State::BuildStateMachine(pattern);
  
  std::set<State*> states;
  
  for (char c : text)
  {
    for (State* s : states)
    {
      std::vector<State*> newStates = s->Input(c);
      
      states.insert(newStates.begin(), newStates.end());
    }
  }
  
  for (State* s : states)
  {
    if (s->IsFinish())
    {
      return true;
    }
  }
  
  return false;
}
  
/*
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
*/

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
