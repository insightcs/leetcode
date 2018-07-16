#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        vector<int> f(n, 0);
        f[0] = cost[0];
        f[1] = cost[1];
        for(int i=2;i<n;i++)
        {
            f[i] = cost[i] + min(f[i-1], f[i-2]);
        }
        return min(f[n-1], f[n-2]);
    }
};

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        for(int i=2;i<n;i++)
        {
            int temp = cost[i] + min(a, b);
            a = b;
            b = temp;
        }
        return min(a, b);
    }
};

class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
       vector<int> f(cost.size()+1, -1);
       return helper(cost, f, cost.size());
    }

private:
    int helper(vector<int>& cost, vector<int>& f, int n)
    {
        if (f[n]!=-1)
        {
            return f[n];
        }
        if (n <= 1)
        {
            f[n] = cost[n];
            return f[n];
        }
        if (n != cost.size())
        {
            f[n] = min(helper(cost, f, n - 1), helper(cost, f, n - 2)) + cost[n];
        }
        else
        {
            f[n] = min(helper(cost, f, n - 1), helper(cost, f, n - 2));
        }
        return f[n];
    }
};