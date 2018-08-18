#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/**
 * count sort
 * time: O(N)
 * space: O(1)
 * */
class Soution
{
public:
    void sortColors(vector<int>& nums)
    {
        int freq[3] = {0};
        for(auto it:nums)
        {
            assert(it>=0 && it<=2);
            freq[it]++;
        }
        int index = 0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<freq[i];j++)
            {
                nums[index++] = i;
            }
        }
    }
};

/**
 * 三路快排
 * time: O(N)
 * space: O(1)
 * */
class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int lt = -1;
        int gt = nums.size();
        for(int i=0;i<gt;)
        {
            if(nums[i]<1)
            {
                swap(nums[i++], nums[++lt]);
            }
            else if(nums[i]>1)
            {
                swap(nums[i], nums[--gt]);
            }
            else
            {
                i++;
            }
        }
    }
};


int main(int argc, char* argv[])
{
    vector<int> nums = {2,0,2,1,1,0};
    Soution s;
    s.sortColors(nums);
    return 0;
}

