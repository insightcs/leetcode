#include <iostream>
#include <vector>
using namespace std;


/**
 * @method: brute force
 * @time: O(N^2)
 * @space: O(1)
 * */


/**
 * @method: two pointers —— 对撞指针
 * @time: O(N)
 * @space: O(1)
 * */
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int max_area = 0;
        while(left<right)
        {
            max_area = max(max_area, (right-left)*min(height[right], height[left]));
            if(height[left]<height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return max_area;
    }
};

int main(int argc, char* argv[])
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution s;
    int res = s.maxArea(height);
    return 0;
}