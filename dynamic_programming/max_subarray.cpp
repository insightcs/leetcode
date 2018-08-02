#include <iostream>
#include <vector>
using namespace std;

/* Ordinary
 * time: O(N)
 * memory: O(1) */
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

/* Dynamic Programming
 * time: O(N)
 * memory: O(N)*/
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)  return 0;
        int max_sum = INT_MIN;
        int start = 0, end = 0;
        vector<int> sub_array;
        int f[n];
        f[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            if(f[i-1]<0)
            {
                f[i] = nums[i];
                start = i;
            }
            else
            {
                f[i] = f[i-1] + nums[i];
            }
            if(max_sum<f[i])
            {
                max_sum = f[i];
                end = i;
            }
        }
        for(int i=start;i<=end;i++)
        {
            sub_array.push_back(nums[i]);
        }
        return max_sum;
    }
};
