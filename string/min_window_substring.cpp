#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cassert>
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
        unordered_map<char, int> table;
        for(auto it:t)
        {
            table[it]++;
        }
        int left = 0, right = 0;
        int win_left = -1, win_right = -1;
        unordered_map<char, int> record;
        int min_len = s.size() + 1;
        while(right<s.size())
        {
            if(table.count(s[right])!=0)
            {
                record[s[right]]++;
                while(record.size()==table.size() && greater_or_equal(record, table))
                {
                    int len = right - left + 1;
                    if(min_len>len)
                    {
                        min_len = len;
                        win_left = left;
                        win_right = right;
                    }
                    if(record.count(s[left])!=0)
                    {
                        record[s[left]]--;
                        if(record[s[left]]==0)
                        {
                            record.erase(s[left]);
                        }
                    }
                    left++;
                }
            }
            right++;
        }
        if(win_left==-1 || win_right==-1)
        {
            return res;
        }
        else
        {
            res = s.substr(win_left, win_right-win_left+1);
        }
        return res;
    }

private:
    bool greater_or_equal(unordered_map<char, int>& a, unordered_map<char, int>& b)
    {
        assert(a.size() == b.size());
        for(auto it:b)
        {
            if(a[it.first]<it.second)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> count(256);
        for(auto it:t)
        {
            count[it]++;
        }
        int min_len = s.size() + 1;
        int win_left = 0;
        int left = 0, right = 0;
        int total = t.size();
        while(right<s.size())
        {
            if (count[s[right]]-->0)
            {
                total--;
            }
            while(total==0)
            {
                int len = right - left + 1;
                if(len<min_len)
                {
                    min_len = len;
                    win_left = left;
                }
                if(count[s[left++]]++ == 0)
                {
                    total++;
                }
            }
        }
        return min_len==s.size()+1 ? "" : s.substr(win_left, min_len);
    }
};

int main(int argc, char* argv[])
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string str = Solution().minWindow(s,t);
    return 0;
}