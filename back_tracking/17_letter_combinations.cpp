#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if(digits.size()==0)    return res;
        helper(digits, 0, "");
        return res;
    }
private:
    vector<string> res;
    const string table[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string digits, int index, string str)
    {
        if(index==digits.size())
        {
            res.push_back(str);
            return;
        }
        char ch = digits[index];
        assert(ch>='2' && ch<='9');
        for(int i=0;i<table[ch-'0'].size();i++)
        {
            helper(digits, index+1, str+table[ch-'0'][i]);
        }
    }
};

int main(int argc, char* argv[])
{
    string digits = "23";
    vector<string> res = Solution().letterCombinations(digits);
    return 0;
}
