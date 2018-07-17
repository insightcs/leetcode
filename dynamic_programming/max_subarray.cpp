#include <iostream>
#include <vector>
using namespace std;


class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size()==0)  return 0;
        int sum = 0;
        int max_sum = INT_MIN;
        for(auto it:nums)
        {
            sum = max(sum+it,it);
            max_sum = max(sum, max_sum);
        }
        return max_sum;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)  return 0;
        int max_sum = INT_MIN;
        int f[n];
        f[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            f[i] = max(f[i-1], 0) + nums[i];
            max_sum = max(f[i], max_sum);
        }
        return max_sum;
    }
};
