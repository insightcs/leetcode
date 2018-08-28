#include <iostream>
#include <vector>
using namespace std;


/**
 * @method: 回溯+剪枝
 */
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        if(n<=0 || k<=0 || n<k)
        {
            return res;
        }
        vector<int> vec;
        find_combinations(n, k, 1, vec, res);
        return res;
    }

private:
    void find_combinations(int n, int k, int index, vector<int>& vec, vector<vector<int>>& res)
    {
        if(vec.size()==k)
        {
            res.push_back(vec);
            return;
        }
        /* 剪枝优化 */
        // 还有k-vec.size()个空位，所以[i...n]中至少要有k-vec.size()个元素
        // i最多为n-(k-vec.size())+1
        for(int i=index;i<=n-(k-vec.size())+1;i++)
        {
            vec.push_back(i);
            find_combinations(n, k, i+1, vec, res);
            vec.pop_back();
        }
    }
};


int main(int argc, char* argv[])
{
    int n = 4, k = 2;
    vector<vector<int>> res = Solution().combine(n, k);
    return 0;
}