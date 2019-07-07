#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class NQueen
{
public:
    NQueen(const size_t N)
        : m_N(N)
        , m_board(N*N)
    {
    }

    bool solve()
    {
        return solve(0);
    }

    void print()
    {
        for (size_t row = 0; row < m_N; ++row)
        {
            for (size_t col = 0; col < m_N; ++col)
            {
                const int val = get(row, col);

                if (val)
                {
                    cout << 'x';
                }
                else
                {
                    cout << '_';
                }
            }
            cout << endl;
        }
    }

private:
    int& get(const size_t row, const size_t col)
    {
        const size_t i = row * m_N + col;
        return m_board.at(i);
    }

    bool solve(const size_t col)
    {
        if (col == m_N)
        {
            return true;
        }

        for (size_t row = 0; row < m_N; ++row)
        {
            if (canPlace(row, col))
            {
                int& cell = get(row, col);
                cell = 1;

                if (solve(col + 1))
                {
                    return true;
                }
                else
                {
                    cell = 0;
                }
            }
        }

        return false;
    }

    bool canPlace(const size_t test_row, const size_t test_col)
    {
        for (size_t row = 0; row < test_row; ++row)
        {
            if (get(row, test_col))
            {
                return false;
            }
        }
        for (size_t col = 0; col < test_col; ++col)
        {
            if (get(test_row, col))
            {
                return false;
            }
        }
        {
            // Check preceding diagonal (up and to left).
            long row = test_row - 1;
            long col = test_col - 1;
            while (row >= 0 && col >= 0)
            {
                if (get(row, col))
                {
                    return false;
                }
                row--;
                col--;
            }
        }
        {
            // Check preceding diagonal (down and to left).
            long row = test_row + 1;
            long col = test_col - 1;
            while (row < m_N && col >= 0)
            {
                if (get(row, col))
                {
                    return false;
                }
                row++;
                col--;
            }
        }
        return true;
    }

    const size_t m_N;

    vector<int> m_board;
};

bool n_queen(const int N)
{
    NQueen solver(N);
    return solver.solve();
}

int main() 
{
    for (int i = 0; i < 9; ++i)
    {
        NQueen solver(i);
        bool solved = solver.solve();

        cout << "i:" << i << ", solved:" << solved << endl;

        solver.print();
    }
}
