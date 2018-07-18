#include <iostream>
#include <vector>
using namespace std;

static int x=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class NumArray
{
public:
    NumArray(vector<int> nums)
    {
        size = nums.size();
        array = nums;
        sum.resize((size*size+size)/2, INT_MIN);
    }

    int sumRange(int i, int j)
    {
        sum[i*size+j] = sum[i*size+j-1] + array[j];

        return sum[i*size+j];
    }

private:
    vector<int> array;
    vector<int> sum;
    int size;
};
