#include <iostream>
#include <vector>
#include <climits>
#include <cassert>
using namespace std;

/**
 * recursive
 * time: O(2^N)
 * space: O(N)
 * */
class Solution
{
public:
    int numSquares(int n)
    {
        return helper(squares, n);
    }

private:
    int helper(int n)
    {
        if(n<=1)
        {
            return n;
        }
        int res = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            res = min(res, helper(n-i*i)+1);
        }
        return res;
    }
};

/**
 * 记忆搜索法
 * time: O(N^2)
 * space: O(N)
 * */
class Solution
{
public:
    int numSquares(int n)
    {
        memo = vector<int>(n+1, -1);
        return helper(n);
    }

private:
    vector<int> memo;
    int helper(int n)
    {
        if(n<=1)
        {
            return n;
        }
        if(memo[n]!=-1)
        {
            return memo[n];
        }
        int res = INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            res = min(res, helper(n-i*i)+1);
        }
        memo[n] = res;
        return memo[n];
    }
};

/**
 * DP
 * time: O(N^2)
 * space: O(N)
 * */
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++)
            {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    int res = s.numSquares(12);
    return 0;
}