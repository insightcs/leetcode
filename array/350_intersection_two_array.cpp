#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @method: Hash Table
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> map;
        for(auto it:nums1)
        {
            map[it]++;
        }
        vector<int> res;
        for(auto it:nums2)
        {
            if(map.count(it)!=0)
            {
                res.push_back(it);
                map[it]--;
                if (map[it] == 0)
                {
                    map.erase(it);
                }
            }
        }
        return res;
    }
};