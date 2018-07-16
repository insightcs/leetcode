#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.size()==0)    return 0;
        vector<int> f(prices.size(), -1);
        return helper(prices, f, prices.size()-1);
    }

private:
    int helper(vector<int>& prices, vector<int>& f, int n)
    {
        if(n==0)
        {
            f[n] = 0;
            return f[n];
        }
        if(f[n]!=-1)
        {
            return f[n];
        }
        int temp = 0;
        for(int i=1;i<=n;i++)
        {
            temp = max(temp, prices[n] - prices[n-i]);
        }
        f[n] = max(temp, helper(prices, f, n-1));
        return f[n];
    }
};

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        if(n==0)    return 0;
        vector<int> f(prices.size(), 0);
        for(int i=1;i<n;i++)
        {
            int temp = 0;
            for(int j=1;j<=i;j++)
            {
                temp = max(temp, prices[i]-prices[i-j]);
            }
            f[i] = max(temp, f[i-1]);
        }
        return f[n-1];
    }
};

/* brute force
 * time: O(N^2)
 * memory: O(1) */
class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int max_profit = 0;
        for (int i = 0; i < n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int temp = prices[j]-prices[i];
                if(temp>max_profit)
                {
                    max_profit = temp;
                }
            }
        }
        return max_profit;
    }
};

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int min_price = INT_MAX;
        int max_price = 0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]<min_price)
            {
                min_price = prices[i];
            }
            int temp = prices[i] - min_price;
            if(temp>max_price)
            {
                max_price = temp;
            }
        }
        return max_price;
    }
};
