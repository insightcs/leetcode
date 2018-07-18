#include <iostream>
#include <vector>
using namespace std;

int x=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();// 取消绑定cin与cout，加速输入输出，此时，scanf等C语言的函数不能使用

/* dynamic programming
 * time: O(N)
 * memory: O(N) */
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        int dp[n] = {0};
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};

/* dynamic programming
 * time: O(N)
 * memory: O(1) */
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        int a = nums[0];
        int b = max(nums[1], a);
        for(int i=2;i<n;i++)
        {
            int temp = max(a+nums[i], b);
            a = b;
            b = temp;
        }
        return b;
    }
};
