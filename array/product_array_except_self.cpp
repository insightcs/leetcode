#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        int pre = 1;
        int post = 1;
        vector<int> output(n, 1);
        for(int start=0,end=n-1;start<n&&end>=0;start++,end--)
        {
            output[start] *= pre;
            output[end] *= post;
            pre *= nums[start];
            post *= nums[end];
        }
        return output;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {1,2,3,4};
    Solution s;
    vector<int> res = s.productExceptSelf(nums);
    return 0;
}
