#include "DaysStillWaiting.h"
#include <iostream>

using namespace std;

template<typename T>
void print(const T& v)
{
    for (int i : v)
    {
        cout << i << " ";
    }
    cout << std::endl;
}

int main()
{
    auto t = {74, 50, 48, 60, 62, 50, 48, 74, 75};
    auto v = dailyTemperatures(t);

    print(t);
    print(v);
}
