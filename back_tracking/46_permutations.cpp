#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        int n = nums.size();
        res.clear();
        if(n==0)    return res;
        vector<bool> visited(n, false);
        vector<int> list;
        find_permute(nums, list, visited);
        return res;
    }

private:
    vector<vector<int>> res;
    void find_permute(const vector<int>& nums, vector<int>& list, vector<bool>& visited)
    {
        if(list.size()==nums.size())
        {
            res.push_back(list);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                list.push_back(nums[i]);
                find_permute(nums, list, visited);
                visited[i] = false;
                list.pop_back();
            }
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = Solution().permute(nums);
    return 0;
}