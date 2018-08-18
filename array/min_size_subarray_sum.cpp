#include <iostream>
#include <vector>
using namespace std;

/**
 * @method: brute force
 * @time: O(N^3)
 * @space: O(1)
 * */
class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        int min_len = n + 1;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum = 0;
                for(int k=i;k<=j;k++)
                {
                    sum += nums[k];
                }
                if(sum>=s)
                {
                    min_len = min(min_len, j-i+1);
                    break;
                }
            }
        }
        return (min_len==n+1 ? 0 : min_len);
    }
};

/**
 * @method: two pointers
 * @time: O(N)
 * @space: O(1)
 * */
class Solution
{
public:
    int minSubArrayLen(int s, vector<int>& nums)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int min_len = n+1;
        while(right<n)
        {
            sum += nums[right++];
            while(sum>=s)
            {
                min_len = min(min_len, right-left);
                sum -= nums[left++];
            }
        }
        if(min_len == n+1)
        {
            min_len = 0;
        }
        return min_len;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {2,3,1,2,4,3};
    Solution s;
    int res = s.minSubArrayLen(7, nums);
    return 0;
}