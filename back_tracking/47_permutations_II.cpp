#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        int n = nums.size();
        unordered_map<int, int> table;
        for(auto it:nums)
        {
            table[it]++;
        }
        vector<vector<int>> res;
        vector<int> vec;
        find_permute(table, n, vec, res);
        return res;
    }

private:
    void find_permute(unordered_map<int, int>& table, int n, vector<int>& vec, vector<vector<int>>& res)
    {
        if(vec.size()==n)
        {
            res.push_back(vec);
            return;
        }
        for(auto it:table)
        {
            if(it.second>0)
            {
                vec.push_back(it.first);
                table[it.first]--;
                find_permute(table, n, vec, res);
                vec.pop_back();
                table[it.first]++;
            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> res = Solution().permuteUnique(nums);
    return 0;
}