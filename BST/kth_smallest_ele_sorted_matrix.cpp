#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/** binary search
 * time: O(nlogn)
 * space: O(1)
 * */
class Solution
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];
        while (left < right)
        {
            int mid = (left + right) / 2;
            int num = 0;
            /* 统计比mid小的数的个数 */
            for (int i = 0; i < n; i++)
            {
                int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                num += pos;
            }
            if (num < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};

