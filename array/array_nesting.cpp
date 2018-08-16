#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Using Visited Array
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    int arrayNesting(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool> visited(n, false);
        int count = 0;
        int max_count = 0;
        for(int i=0;i<n;)
        {
            if(!visited[i])
            {
                count++;
                visited[i] = true;
                i = nums[i];
            }
            else
            {
                count = 0;
                i++;
            }
            max_count = max(max_count, count);
         }
        return max_count;
    }
};

/**
 * time: O(N)
 * space: O(1)
 * */
class Solution2
{
public:
    int arrayNesting(vector<int>& nums)
    {
        int n = nums.size();
        int count = 0;
        int max_count = 0;
        for(int i=0;i<n;)
        {
            if(nums[i]!=INT_MAX)
            {
                int temp = nums[i];
                nums[i] = INT_MAX;
                i = temp;
                count++;
            }
            else
            {
                count = 0;
                i++;
            }
            max_count = max(max_count, count);
        }
        return max_count;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums = {5,4,0,3,1,6,2};
    Solution2 s;
    int res = s.arrayNesting(nums);
    return 0;
}