#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        int n = S.size();
        vector<string> res;
        find_permutation(S, 0, res);
        return res;
    }

private:
    void find_permutation(string s, int index, vector<string>& res)
    {
        res.push_back(s);
        for(int i=index;i<s.size();i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                s[i] = (s[i] - 'a' + 'A');
                find_permutation(s, i+1, res);
                s[i] = (s[i] - 'A' + 'a');
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] = (s[i] - 'A' + 'a');
                find_permutation(s, i+1, res);
                s[i] = (s[i] - 'a' + 'A');
            }
            else
            {
                continue;
            }
        }
    }
};

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        int n = S.size();
        vector<string> res;
        find_permutation(S, 0, res);
        return res;
    }

private:
    void find_permutation(string& s, int index, vector<string>& res)
    {
        if(index==s.size())
        {
            res.push_back(s);
            return;
        }
        find_permutation(s, i+1, res);
        if(isalpha(s[i]))
        {
            s[i] ^= (1 << 5);
            find_permutation(s, index+1, res);
        }
    }
};

int main(int argc, char* argv[])
{
    string s = "12345";
    vector<string> res = Solution().letterCasePermutation(s);
    return 0;
}
