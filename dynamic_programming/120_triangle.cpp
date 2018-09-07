#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * recursive
 * time: 2^N
 * space: O(N)
 * */
/*class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int n = triangle.size();
        int min_path = INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++)
        {
            min_path = min(min_path, calc_ways(triangle, n-2, i)+triangle[n-1][i]);
        }
        return min_path;
    }

private:
    int calc_ways(vector<vector<int>>& triangle, int level, int k)
    {
        if(level<0)
            return 0;
        int min_path = INT_MAX;
        if(k-1>=0)
        {
            min_path = min(min_path, calc_ways(triangle, level-1, k-1)+triangle[level][k-1]);
        }
        if(k<triangle[level].size())
        {
            min_path = min(min_path, calc_ways(triangle, level-1, k)+triangle[level][k]);
        }
        return min_path;
    }
};*/

/**
 * 记忆搜索法top-down
 * time: O(N)
 * space: O(N)
 * */
/*class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        memo = triangle;
        int n = triangle.size();
        // 初始化
        for (int i = 0; i < n; i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                memo[i][j] = INT_MAX;
            }
        }
        int min_path = INT_MAX;
        for(int i=0;i<triangle[n-1].size();i++)
        {
            min_path = min(min_path, calc_ways(triangle, n-2, i)+triangle[n-1][i]);
        }
        return min_path;
    }
private:
    vector<vector<int>> memo;
    int calc_ways(vector<vector<int>>& triangle, int level, int k)
    {
        if(level<0)
        {
            return 0;
        }
        int min_path = INT_MAX;
        if (k - 1 >= 0)
        {
            if(memo[level][k-1]==INT_MAX)
            {
                memo[level][k-1] = min(memo[level][k-1], calc_ways(triangle, level - 1, k - 1) + triangle[level][k - 1]);
            }
            min_path = memo[level][k-1];
        }
        if (k < triangle[level].size())
        {
            if(memo[level][k]==INT_MAX)
            {
                memo[level][k] = min(memo[level][k], calc_ways(triangle, level - 1, k) + triangle[level][k]);
            }
            min_path = min(min_path, memo[level][k]);
        }
        return min_path;
    }
};*/

/**
 * DP
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> memo(triangle);
        int n = triangle.size();
        if(n==1)    return triangle[0][0];
        memo[0][0] = triangle[0][0];
        int min_path = INT_MAX;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j-1<0)
                {
                    memo[i][j] = memo[i-1][j] + triangle[i][j];
                }
                else if(j>=triangle[i-1].size())
                {
                    memo[i][j] = memo[i-1][j-1] + triangle[i][j];
                }
                else
                {
                    memo[i][j] = min(memo[i-1][j-1], memo[i-1][j]) + triangle[i][j];
                }
                if(i==n-1)
                {
                    min_path = min(min_path, memo[i][j]);
                }
            }
        }
        return min_path;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    int res = s.minimumTotal(triangle);
    return 0;
}
