#include <iostream>
#include <limits>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

struct Window
{
    size_t leftInclusive = 0;
    size_t rightExclusive = 0;

    Window(const size_t left, const size_t right)
        : leftInclusive(left)
        , rightExclusive(right)
    {
    }
};

class MinSubstringFinder
{
public:
    MinSubstringFinder(const string& input, const unordered_set<char>& charset)
        : m_input(input)
        , m_charset(charset)
        , m_window(0, 0)
        , m_min(0, std::numeric_limits<size_t>::max())
    {
    }

    string find()
    {
        while (tryExpandWindowToSatisfyCharset())
        {
            shrinkWindowWhileSatisfyingCharset();
            updateMin();
            shrinkWindowToNextCharInSet();
        }

        if (!m_hasMin)
        {
            return "";
        }
        else
        {
            return m_input.substr(m_min.leftInclusive, m_min.rightExclusive - m_min.leftInclusive);
        }
    }

private:
    bool windowSatisfiesCharset() const
    {
        for (const char c : m_charset)
        {
            auto iter = m_charfreq.find(c);
            if (iter == m_charfreq.end() || iter->second == 0)
            {
                return false;
            }
        }

        return true;
    }

    bool tryExpandWindowToSatisfyCharset()
    {
        if (m_window.leftInclusive == m_input.size())
        {
            return false;
        }

        while (m_window.rightExclusive < m_input.size())
        {
            m_window.rightExclusive++;

            const char c = m_input[m_window.rightExclusive - 1];

            if (m_charset.count(c))
            {
                m_charfreq[c]++;

                if (windowSatisfiesCharset())
                {
                    return true;
                }
            }
        }

        return false;
    }

    void shrinkWindowWhileSatisfyingCharset()
    {
        while (m_window.leftInclusive < m_input.size())
        {
            const char c = m_input[m_window.leftInclusive];

            if (m_charset.count(c))
            {
                m_charfreq[c]--;

                if (!windowSatisfiesCharset())
                {
                    m_charfreq[c]++;
                    return;
                }
            }

            m_window.leftInclusive++;
        }
    }

    void shrinkWindowToNextCharInSet()
    {
        const char c = m_input[m_window.leftInclusive];

        if (m_charset.count(c))
        {
            m_charfreq[c]--;
        }

        m_window.leftInclusive++;

        while (m_window.leftInclusive < m_input.size())
        {
            const char c = m_input[m_window.leftInclusive];

            if (m_charset.count(c))
            {
                return;
            }

            m_window.leftInclusive++;
        }
    }

    void updateMin()
    {
        if (!m_hasMin
            || m_window.rightExclusive - m_window.leftInclusive < m_min.rightExclusive - m_min.leftInclusive)
        {
            m_hasMin = true;
            m_min.leftInclusive = m_window.leftInclusive;
            m_min.rightExclusive = m_window.rightExclusive;
        }
    }

    const string& m_input;
    const unordered_set<char>& m_charset;

    Window m_window;
    unordered_map<char, size_t> m_charfreq;

    bool m_hasMin = false;
    Window m_min;
};

string findMinSubstring(const string& input, const unordered_set<char>& charset)
{
    MinSubstringFinder finder(input, charset);
    return finder.find();
}

string findMinSubstring(const string& input, const string& chars)
{
    unordered_set<char> charset;
    for (const char c : chars)
    {
        charset.insert(c);
    }

    return findMinSubstring(input, charset);
}

struct TestCase
{
  string input;
  string chars;
  string expected;
  
  bool Run() const
  {
    const auto actual = findMinSubstring(input, chars);
    if (expected != actual)
    {
      cout << "Test failed." << input << ',' << chars << ',' << expected << ',' << actual << endl;
    }
    
    return (expected == actual);
  }
};

int main() 
{
  vector<TestCase> cases = {{"asdf", "a", "a"},
                            {"asdf", "", ""},
                            {"asdf", "ad", "asd"},
                            {"babble", "al", "abbl"},
                            {"babble", "la", "abbl"},
                            {"the quick brown fox jumped over the lazy dog", "rje", "jumped over"},
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
