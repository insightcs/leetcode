#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetWithDup(vector<int>& nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        find_combinations(nums, 0, path, res);
        return res;
    }

private:
    void find_combinations(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res)
    {
        res.push_back(path);

        unordered_set<int> visited;
        for(int i=index;i<nums.size();i++)
        {
            if(visited.count(nums[i])!=0)
            {
                continue;
            }
            visited.insert(nums[i]);
            path.push_back(nums[i]);
            find_combinations(nums, i + 1, path, res);
            path.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1,2,2};
    Solution s;
    vector<vector<int>> res = s.subsetWithDup(nums);
    return 0;
}