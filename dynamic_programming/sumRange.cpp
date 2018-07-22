#include <iostream>
#include <vector>
using namespace std;

static int x=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

/* Brute Force
 * time: O(N) for per query
 * memory: O(N) */
class NumArray
{
public:
    NumArray(vector<int> nums)
    {
        array = nums;
    }

    int sumRange(int i, int j)
    {
        int sum = 0;
        for(int k=i;k<=j&&k<array.size();k++)
        {
            sum += array[k];
        }
        return sum;
    }

private:
    vector<int> array;
};

/* Caching
 * time: O(N) for pre-computation, O(1) for per query
 * memory: O(N)*/
class NumArray
{
public:
    NumArray(vector<int> nums)
    {
        sum.resize(nums.size()+1, 0);
        int temp = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum[i+1] = temp + nums[i];
            temp = sum[i+1];
        }
    }

    int sumRange(int i, int j)
    {
        return (sum[j+1]-sum[i]);
    }

private:
    vector<int> sum;
};


int main(int argc, char* argv[])
{
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray s(nums);
    int res = s.sumRange(0,2);
    return 0;
}
