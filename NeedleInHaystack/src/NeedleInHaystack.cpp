#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Signature
{
public:
    Signature(const string& needle)
        : m_count(needle.size())
        , m_removalFactor(pow(256, (m_count - 1)))
    {
        for (char c : needle)
        {
            addCharacter(c);
        }
    }

    void update(const char removed, const char added)
    {
        cout << "update: r:" << removed << ",a:" << added << endl;
        m_number -= m_removalFactor * static_cast<size_t>(removed);
        cout << m_number << endl;
        addCharacter(added);
    }

    bool operator==(const Signature& other) const
    {
        return m_number == other.m_number;
    }

private:
    void addCharacter(const char c)
    {
        const size_t old = m_number;
        m_number *= 256;
        m_number += static_cast<size_t>(c);

        if (old > m_number)
        {
            cout << "old,m_number:" << old << ',' << m_number << endl;
            throw std::runtime_error("Integer overflow");
        }
    }

    size_t m_number = 0;
    const size_t m_count = 0;
    const size_t m_removalFactor = 0;
};

int findString(const string& needle, const string& haystack)
{
    cout << needle << ',' << haystack << endl;

    if (needle.size() > haystack.size())
    {
        return -1;
    }

    const Signature needleSignature(needle);
    Signature currentSignature(haystack.substr(0, needle.size()));

    for (size_t i = 0; i < 1 + haystack.size() - needle.size(); ++i)
    {
        cout << "i:" << i << endl;
        if (needleSignature == currentSignature)
        {
            return i;
        }
        else
        {
            currentSignature.update(haystack[i], haystack[i + needle.size()]);
        }
    }

    return -1;
}

struct TestCase
{
  string needle;
  string haystack;
  int expected;
  
  bool Run() const
  {
    int actual = findString(needle, haystack);
    if (expected != actual)
    {
      cout << "Test failed." << needle << ',' << haystack << ',' << expected << ',' << actual << endl;
    }
    
    return (expected == actual);
  }
};

int main() 
{
  vector<TestCase> cases = {{"nee", "hays", -1},
                            {"a", "a", 0},
                            {"a", "ba", 1},
                            {"ab", "cab", 1},
                            {"aa", "a", -1},
                            {"ab", "bbbbbbbbbbbbbbbbabbbbbbbbbb", 16},
                            {"abcdefgh", "bbbbbbbbbbbbbbbbabbbbbbbbbb", -1},
  };
  
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
