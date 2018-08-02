#include <iostream>
#include <vector>
using namespace std;

static int x=[]()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        vector<int> count(nums.size()+1);
        for(auto it:nums)
        {
            count[it]++;
        }
        for(int i=0;i<count.size();i++)
        {
            if(count[i]==2)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        vector<bool> flag(nums.size()+1, false);
        for(auto it:nums)
        {
            if(flag[it])
            {
                res.push_back(it);
            }
            else
            {
                flag[it] = true;
            }
        }
        return res;
    }
};
