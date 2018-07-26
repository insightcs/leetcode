#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> subset_sum(vector<int> &nums, int M)
    {
        int n = nums.size();
        vector<vector<bool>> subset(n+1, vector<bool>(M+1, false));
        for(int i=0;i<=n;i++)
        {
            subset[i][0] = true;
        }
        for(int j=1;j<=M;j++)
        {
            subset[0][j] = false;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=M;j++)
            {
                if(j<nums[i-1])
                {
                    subset[i][j] = subset[i-1][j];
                }
                else
                {
                    subset[i][j] = subset[i-1][j] || subset[i-1][j-nums[i-1]];
                }
            }
        }

        vector<int> res;
        for(int i=n,j=M;i>=1&&j>=0;i--)
        {
            if(subset[i][j] && !subset[i-1][j])
            {
                res.push_back(nums[i-1]);
                j -= nums[i-1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    vector<int> nums = {1, 3, 4, 5};
    Solution s;
    vector<int> res = s.subset_sum(nums, 7);
    return 0;
}
