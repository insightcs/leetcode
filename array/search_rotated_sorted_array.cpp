#include <iostream>
#include <vector>
using namespace std;


/**
 * @method: 二分查找
 * @time: O(logN)
 * @space: O(1)
 * */
class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int n = nums.size();
        if(n==0)    return -1;
        int left = 0;
        int right = n - 1;
        while(left<right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid]>nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        int pivot = left;
        left = 0;
        right = n - 1;
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            int real_mid = (mid + pivot) % n;
            if(nums[real_mid]==target)
            {
                return real_mid;
            }
            else if(nums[real_mid]<target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {3,1};
    int res = Solution().search(nums, 3);
    return 0;
}
