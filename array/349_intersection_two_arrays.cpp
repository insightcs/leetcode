#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * @method: 哈希表
 * @time: O(N)
 * @space: O(N)
 * */
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_set<int> set;
        for(auto it:nums1)
        {
            set.insert(it);
        }
        unordered_set<int> res;
        for(auto it:nums2)
        {
            if(set.count(it)!=0)
            {
                res.insert(it);
            }
        }
        return vector<int>(res.begin(), res.end());
    }
};