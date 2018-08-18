#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/**
 * @method: two pointers —— sliding window
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        unordered_set<char> record;
        int longest = 0;
        while(left<=right && right<n)
        {
            if(record.count(s[right])==0)
            {
                record.insert(s[right++]);
                longest = max(longest, right-left);
            }
            else
            {
                record.erase(s[left++]);
            }
        }
        return longest;
    }
};

/**
 * @method: two pointers —— optimized sliding window
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int left = 0;
        int right = 0;
        unordered_map<char, int> record;
        int longest = 0;
        while(left<=right && right<n)
        {
            if(record.count(s[right])!=0)
            {
                left = max(record[s[right]]+1, left);
            }
            longest = max(longest, right-left+1);
            record[s[right]] = right;
            right++;
        }
        return longest;
    }
};


int main(int argc, char* argv[])
{
    string s = "abcabcbb";
    Solution ss;
    int res = ss.lengthOfLongestSubstring(s);
    return 0;
}
