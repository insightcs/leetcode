#include <iostream>
#include <vector>
using namespace std;

/**
 * @method: brute force —— recursion
 * @time: O(2^N)
 * @space: O(N)
 * */
class Solution
{
public:
    int integerBreak(int n)
    {
        int res = 0;
        if(n<=1)    return 0;
        for(int i=1;i<n;i++)
        {
            res = max(res, max(i*(n-i), i*integerBreak(n-i)));
        }
        return res;
    }
};

/**
 * @method: 记忆化搜索
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    int integerBreak(int n)
    {
        memo = vector<int> (n+1, -1);
        return break_num(n);
    }

private:
    vector<int> memo;
    int break_num(int n)
    {
        if(n<=1)
        {
            return 0;
        }
        if(memo[n]!=-1)
        {
            return memo[n];
        }
        for(int i=1;i<n;i++)
        {
            memo[n] = max(memo[n], max(i*(n-i), i*break_num(n-i)));
        }
        return memo[n];
    }
};

/**
 * @method: 动态规划
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    int integerBreak(int n)
    {
        if(n<=1)
        {
            return 0;
        }
        vector<int> memo(n+1, 0);
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                memo[i] = max(memo[i], max(j*(i-j), j*memo[i-j]));
            }
        }
        return memo[n];
    }
};

int main(int argc, char* argv[])
{
    int n = 2;
    int res = Solution().integerBreak(n);
    return 0;
}

