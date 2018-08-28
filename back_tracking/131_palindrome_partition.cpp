#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        if(s.empty())   return res;
        vector<string> path;
        dfs(s, 0, path, res);
        return res;
    }

private:
    void dfs(const string& s, int index, vector<string>& path, vector<vector<string>>& res)
    {
        if(index==s.size())
        {
            res.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(is_palindrome(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                dfs(s, i+1, path, res);
                path.pop_back();
            }
        }
    }
    bool is_palindrome(const string& s, int left, int right)
    {
        while(left<right)
        {
            if(s[left++]!=s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
