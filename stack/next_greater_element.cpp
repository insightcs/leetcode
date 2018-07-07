#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums)
    {
        vector<int> result;
        for(auto item:findNums)
        {
            auto pos = std::find(nums.begin(),nums.end(),item);
            for(;;pos++)
            {
                if(pos==nums.end())
                {
                    result.push_back(-1);
                    break;
                }
                else if(*pos > item)
                {
                    result.push_back(*pos);
                    break;
                }
            }
        }
        return result;
    }
};
