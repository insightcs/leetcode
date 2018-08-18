#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        string res;
        if(s.size()<t.size())
        {
            return res;
        }
        unordered_set<char> record(t.begin(),t.end());
        unordered_set<char> table;
        while()
        {
            if(record.count(s[right]))
            {
                table.
            }
        }
    }
};
