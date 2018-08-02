#include <iostream>
#include <vector>
using namespace std;

static int x=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration)
    {
        int total_time = 0;
        int end_time = 0;
        for(auto it:timeSeries)
        {
            int temp = end_time - it;
            total_time += (duration - (temp>0?temp:0));
            end_time = it + duration;
        }
        return total_time;
    }
};
