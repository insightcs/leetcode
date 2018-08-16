#include <iostream>
#include <vector>
#include <climits>
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
        vector<int> squares;
        // 生成square numbers
        for(int i=1;;i++)
        {
            int temp = i * i;
            if(temp>n)
            {
                break;
            }
            squares.push_back(temp);
        }
        return helper(squares, n);
    }

private:
    int helper(vector<int>& squares,  int n)
    {
        if(n<=1)
        {
            return n;
        }
        int res = INT_MAX;
        for(int i=0;i<squares.size();i++)
        {
            if(squares[i]>n)
            {
                break;
            }
            res = min(res, helper(squares, n-squares[i])+1);
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
        vector<int> squares;
        // 生成square numbers
        for(int i=1;;i++)
        {
            int temp = i * i;
            if(temp>n)
            {
                break;
            }
            squares.push_back(temp);
        }
        memo = vector<int>(n+1, INT_MAX);
        return helper(squares, n);
    }

private:
    vector<int> memo;
    int helper(vector<int>& squares,  int n)
    {
        if(n<=1)
        {
            return n;
        }
        if(memo[n]!=INT_MAX)
        {
            return memo[n];
        }
        int res = INT_MAX;
        for(int i=0;i<squares.size();i++)
        {
            if(squares[i]>n)
            {
                break;
            }
            memo[n] = min(memo[n], helper(squares, n-squares[i])+1);
        }
        return res;
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
        vector<int> squares;
        // 生成square numbers
        for(int i=1;;i++)
        {
            int temp = i * i;
            if(temp>n)
            {
                break;
            }
            squares.push_back(temp);
        }
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<squares.size() && squares[j]<=i;j++)
            {
                dp[i] = min(dp[i], dp[i-squares[j]]+1);
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