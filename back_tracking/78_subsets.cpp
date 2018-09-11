#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


/**
 * @method: back tracking
 * @time: O(N^2)
 * @space: O(N)
 */
class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> vec;
        find_combinations(nums, 0, vec, res);
        return res;
    }

private:
    void find_combinations(vector<int>& nums, int index, vector<int>& vec, vector<vector<int>>& res)
    {
        if(index==nums.size())
        {
            unordered_set<int> set(vec.begin(), vec.end());
            vector<int> tmp;
            for(int i=0;i<nums.size();i++)
            {
                if(set.count(nums[i])==0)
                {
                    tmp.push_back(nums[i]);
                }
            }
            res.push_back(vec);
            res.push_back(tmp);
            return;
        }
        for(int i=index;i<nums.size();i++)
        {
            vec.push_back(nums[i]);
            find_combinations(nums, i+1, vec, res);
            vec.pop_back();
        }
    }
};

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> vec;
        find_combinations(nums, 0, vec, res);
        return res;
    }

private:
    void find_combinations(vector<int>& nums, int index, vector<int>& vec, vector<vector<int>>& res)
    {
        res.push_back(vec);
        for(int i=index;i<nums.size();i++)
        {
            vec.push_back(nums[i]);
            find_combinations(nums, i+1, vec, res);
            vec.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    return 0;
}