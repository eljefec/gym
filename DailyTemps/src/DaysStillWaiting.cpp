#include <vector>
#include <map>

using namespace std;

vector<int> dailyTemperatures(const vector<int>& temperatures) 
{
    vector<int> output(temperatures.size());
    
    multimap<int, int> daysStillWaiting;
    daysStillWaiting.insert({temperatures[0], 0});
    
    for (int i = 1; i < temperatures.size(); i++)
    {
        const int temp = temperatures[i];
        
        const auto itup = daysStillWaiting.upper_bound(temp);
        const auto itlow = daysStillWaiting.lower_bound(temp);
        for (auto it = daysStillWaiting.begin(); it != itlow; ++it)
        {
            const int waitingDay = it->second;
            output[waitingDay] = i - waitingDay;
        }
        
        daysStillWaiting.erase(daysStillWaiting.begin(), itlow);
        
        daysStillWaiting.insert({temperatures[i], i});
    }
    
    return output;
}
