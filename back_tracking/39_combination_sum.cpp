#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        find_combinations(candidates, target, 0, vec, res);
        return res;
    }

private:
    void find_combinations(const vector<int>& candidates, int target, int index, vector<int>& vec, vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        for(int i=index;i<candidates.size() && candidates[i]<=target;i++)
        {
            vec.push_back(candidates[i]);
            find_combinations(candidates, target - candidates[i], i, vec, res);
            vec.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> candidates = {2, 3, 5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum(candidates, target);
    return 0;
}