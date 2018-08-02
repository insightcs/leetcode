#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * DP
 * time: O(N^3)
 * space: O(N)
 * */
class Solution
{
public:
    int countSubStrings(string s)
    {
        if(s.empty())
        {
            return 0;
        }
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i=1;i<=n;i++)
        {
            dp[i] += dp[i-1];
            for(int j=1;j<=i;j++)
            {
                if(is_palindromic(s, j-1, i-1))
                {
                    dp[i] += 1;
                }
            }
        }
        return dp[n];
    }

private:
    bool is_palindromic(string &str, int start, int end)
    {
        int i = start, j = end;
        for(;i<j;i++,j--)
        {
            if(str[i]!=str[j])
            {
                return false;
            }
        }
        return true;
    }
};


int main(int argc, char *argv[])
{
    return 0;
}