#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> permutate(string& s)
    {
        vector<string> res;
        int n = s.length();
        if(n==0)
        {
            return res;
        }
        vector<bool> visited(n, false);
        helper(s, "", visited, res);
        return res;
    }

private:
    void helper(string& s, string str, vector<bool>& visited, vector<string>& res)
    {
        if(str.length()==s.length())
        {
            res.push_back(str);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(visited[i])
            {
                continue;
            }
            visited[i] = true;
            helper(s, str+s[i], visited, res);
            visited[i] = false;
        }
    }
};

int main(int argc, char* argv[])
{
    string s = "abcd";
    vector<string> res = Solution().permutate(s);
    return 0;
}