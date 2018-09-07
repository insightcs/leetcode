#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

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
        if (s.empty())
        {
            return 0;
        }
        if (s[0] == '0')
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
                if (str.empty()) {
                    res += 1;
                }
            }
        }
        memo[s] = res;
        return memo[s];
    }
};

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
        if (s.empty())
        {
            return 0;
        }
        if (s[0] == '0')
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
                if (str.empty()) {
                    res += 1;
                }
            }
        }
        memo[s] = res;
        return memo[s];
    }
};

int main(int argc, char* argv[])
{
    string s = "226";
    int res = Soltuion().numDecodings(s);
    return 0;
}