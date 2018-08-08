#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/**
 * 排序
 * time: O(NlogN)
 * space: O(1)
 * */
class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        int res = -1;
        stable_sort(nums.begin(),nums.end());
        for(int i=0,j=1;i<n&&j<n;i++,j++)
        {
            if(nums[i]==nums[j])
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};

/**
 * set
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int n = nums.size();
        int res = -1;
        vector<bool> flag(n, false);
        for(int i=0;i<n;i++)
        {
            if(flag[nums[i]])
            {
                res = nums[i];
            }
            else
            {
                flag[nums[i]] = true;
            }
        }
        return res;
    }
};

/**
 * two pointers
 * time: O(N)
 * space: O(1)
 * */
class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow!=fast);

        fast = nums[0];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};