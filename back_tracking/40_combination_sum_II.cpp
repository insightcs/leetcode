#include <iostream>
#include <vector>
#include <map>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        map<int, int> table;
        for(auto it:candidates)
        {
            table[it]++;
        }
        vector<int> vec;
        vector<vector<int>> res;
        find_combinations(table, target, 0, vec, res);
        return res;
    }

private:
    void find_combinations(map<int, int>& table, int target, int pre, vector<int>& vec, vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(vec);
            return;
        }
        for(auto it=table.begin();it!=table.end() && it->first<=target;it++)
        {
            if(it->second==0 || it->first<pre)
            {
                continue;
            }
            vec.push_back(it->first);
            it->second--;
            find_combinations(table, target - it->first, it->first, vec, res);
            it->second++;
            vec.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> res = Solution().combinationSum2(candidates, target);
    return 0;
}
