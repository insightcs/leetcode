#include <iostream>
#include <vector>
using namespace std;

/* DP
 * time: O(N)
 * memory: O(N)*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> dp;
        if(num<0)   return dp;
        dp.push_back(0);
        if(num==0)  return dp;
        dp.push_back(1);
        for(int i=2;i<=num;i++)
        {
            dp.push_back(dp[i/2] + dp[i%2]);
        }
        return dp;
    }
};

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};