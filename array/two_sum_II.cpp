#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * @method: binary_search
 * @time: O(NlogN)
 * @space: O(1)
 * */
class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        vector<int> res;
        int n = numbers.size();
        for(int i=0;i<n;i++)
        {
            int pos = binary_search(numbers, i+1, n-1, target-numbers[i]);
            if(pos!=-1)
            {
                res.push_back(i+1);
                res.push_back(pos+1);
                return res;
            }
        }
        return res;
    }

private:
    int binary_search(vector<int>& nums, int left, int right, int val)
    {
        while(left<=right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid]==val)
            {
                return mid;
            }
            else if(nums[mid]<val)
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

/**
 * @method: two pointers --- 对撞指针
 * @time: O(N)
 * @space: O(1)
 * */
class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;
        vector<int> res;
        while(left<right)
        {
            if(numbers[left]==target-numbers[right])
            {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(numbers[left]<target-numbers[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return res;
    }
};

/**
 * @method: dict
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers,  int target)
    {
        int n = numbers.size();
        unordered_map<int, int> record;
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int temp = target - numbers[i];
            if(record.count(temp))
            {
                res.push_back(record[temp]+1);
                res.push_back(i+1);
                return res;
            }
            record[numbers[i]] = i;
        }
        return res;
    }
};
