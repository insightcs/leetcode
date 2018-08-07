#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n = nums.size();
        if(n<1)
        {
            return 0;
        }
        int front_product = 1;
        int back_product = 1;
        int max_product = INT_MIN;
        for(int i=0;i<n;i++)
        {
            front_product *= nums[i];
            back_product *= nums[n-i-1];
            max_product = max(max_product, max(front_product, back_product));
            front_product = (front_product==0 ? 1 : front_product);
            back_product = (back_product==0 ? 1 : back_product);
        }
        return max_product;
    }
};

class Solution
{
public:
    int maxProduct(vector<int> nums)
    {
        int res = nums[0];
        for(int i=1,imax=res,imin=res;i<nums.size();i++)
        {
            if(nums[i]<0)
            {
                int temp = imax;
                imax = imin;
                imin = temp;
            }

            imax = max(nums[i], nums[i]*imax);
            imin = min(nums[i], nums[i]*imin);
            res = max(res, imax);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {2,3,-2,4};
    Solution s;
    int res = s.maxProduct(nums);
    return 0;
}