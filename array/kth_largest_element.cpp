#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * @description: 快速排序
 * @time: O(NlogN)
 * @space: O(1)
 * */
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left<=right)
        {
            int pivot = partition(nums, left, right);
            if(pivot==k-1)
            {
                return nums[pivot];
            }
            else if(pivot>k-1)
            {
                right = pivot - 1;
            }
            else
            {
                left = pivot + 1;
            }
        }
    }

private:
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[left];
        while(left<right)
        {
            while(left<right && nums[right]<=pivot)
            {
                right--;
            }
            nums[left] = nums[right];
            while(left<right && nums[left]>=pivot)
            {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution s;
    int res = s.findKthLargest(nums, 4);
    return 0;
}