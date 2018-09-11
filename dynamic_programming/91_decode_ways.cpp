#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

/**
 * @method: recursion
 * @time: O(2^N)
 * @space: O(N)
 */
class Soltuion
{
public:
    int numDecodings(string s)
    {
        return find_decodings(s);
    }

private:
    int find_decodings(string& s)
    {
        if(s.empty() || s[0]=='0')
        {
            return 0;
        }
        int res = 0;
        int n = s.size();
        for(int i=0;i<(n>2?2:n);i++)
        {
            int num = stoi(s.substr(0,i+1));
            string str = s.substr(i+1, n-i-1);
            if(num>=1 && num<=26)
            {
                res += find_decodings(str);
                if(str.empty())
                {
                    res += 1;
                }
            }
        }
        return res;
    }
};

/**
 * @method: 记忆化搜索
 * @time: O(N)
 * @space: O(N)
 */
class Solution
{
    int numDecodings(string s)
    {
        memo.clear();
        return find_decodings(s);
    }

private:
    map<string, int> memo;
    int find_decodings(string& s)
    {
        if (s.empty() || s[0]=='0')
        {
            return 0;
        }
        if(memo.count(s)!=0)
        {
            return memo[s];
        }
        int res = 0;
        int n = s.size();
        for (int i = 0; i < (n > 2 ? 2 : n); i++)
        {
            int num = stoi(s.substr(0, i + 1));
            string str = s.substr(i + 1, n - i - 1);
            if (num >= 1 && num <= 26)
            {
                res += find_decodings(str);
                if (str.empty())
                {
                    res += 1;
                }
            }
        }
        memo[s] = res;
        return memo[s];
    }
};

/**
 * @method: DP
 * @time: O(N)
 * @space: O(N)
 */
class Solution
{
    int numDecodings(string s)
    {
        if(s.empty() || s[0]=='0')
        {
            return 0;
        }
        int n = s.size();
        // memo[i] 表示前i个字符解码得到的总个数
        vector<int> memo(n+1);
        memo[0] = 1;
        memo[1] = 1;
        for(int i=2;i<=n;i++)
        {
            memo[i] += is_valid(s.substr(i-1, 1)) ? memo[i-1] : 0;
            memo[i] += is_valid(s.substr(i-2, 2)) ? memo[i-2] : 0;
        }
        return memo[n];
    }

private:
    bool is_valid(string str)
    {
        if(str.empty() || str[0]=='0')
        {
            return false;
        }
        int num = stoi(str);
        if(num>=1 && num<=26)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    string s = "226";
    int res = Soltuion().numDecodings(s);
    return 0;
}