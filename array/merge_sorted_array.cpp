#include <iostream>
#include <vector>
using namespace std;


/**
 * two pointers
 * time: O(N)
 * space: O(1)
 * */
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int p1 = m - 1;
        int p2= m + n - 1;
        for(int i=0;i<n;)
        {
            if(p1>=0 && nums2[i]<nums1[p1])
            {
                nums1[p2--] = nums1[p1--];
            }
            else
            {
                nums1[p2--] = nums2[i++];
            }
        }
    }
};
