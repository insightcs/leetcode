#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int max_coins(vector<int>& coins, vector<bool>& coins_value)
    {
        int num_coins = coins.size();
        int value[num_coins+1];
        value[0] = 0;
        value[1] = coins[0];

        for(int i=1;i<num_coins;i++)
        {
            value[i + 1] = max(coins[i] + value[i-1], value[i]);
        }
        int n=num_coins;
        while(n>=2)
        {
            if(value[n]== coins[n-1] + value[n-2])
            {
                coins_value[n - 1] = true;
                n -= 2;
            }
            else
            {
                n--;
            }
        }
        if(n==1)    coins_value[0] = true;
        return value[num_coins];
    }
};


int main(int argc, char* argv[])
{
    vector<int> coins = {5,1,2,10,6,2};
    vector<bool> coins_value(coins.size(), false);
    Solution s;
    int max_value = s.max_coins(coins,coins_value);
    return 0;
}