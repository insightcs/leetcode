#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

/**
 * @method: Hash Table
 * @time: O(N)
 * @space: O(1)
 * */
class Solution
{
public:
    boool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())  return false;
        unordered_map<char, int> table;
        for(auto it:s)
        {
            table[it]++;
        }
        for(auto it:t)
        {
            table[it]--;
            if(table[it]==0)
            {
                table.erase(it);
            }
        }
        if(table.size()!=0)
        {
            return false;
        }
        return true;
    }
};

/**
 * @method: sort
 * @time: O(NlogN)
 * @space: O(1)
 * */
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())  return false;
        stable_sort(s.begin(),s.end());
        stable_sort(t.begin(),t.end());
        return s==t;
    }
};
