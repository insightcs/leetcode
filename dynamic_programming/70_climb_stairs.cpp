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
    int climbStairs(int n)
    {
        return find_ways(n);
    }

private:
    int find_ways(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        return (find_ways(n-1) + find_ways(n-2));
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
    int climbStairs(int n)
    {
        memo = vector<int> (n+1, -1);
        return find_ways(n);
    }

private:
    vector<int> memo;
    int find_ways(int n)
    {
        if(n<=1)
        {
            return 1;
        }
        if(memo[n]!=-1)
        {
            return memo[n];
        }
        memo[n] = find_ways(n-1) + find_ways(n-2);
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
    int climbStairs(int n)
    {
        int a = 1, b = 1;
        for(int i=2;i<=n;i++)
        {
            int temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
};