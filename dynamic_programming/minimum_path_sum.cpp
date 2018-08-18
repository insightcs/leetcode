#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * recursive
 * time: O(2^N)
 * space: O(N)
 * */
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int row = grid.size();
        if(row==0)
        {
            return 0;
        }
        int col = grid[0].size();
        return helper(grid, row-1, col-1);
    }

private:
    int helper(vector<vector<int>>& grid, int row, int col)
    {
        if(row==0 && col==0)
        {
            return grid[0][0];
        }
        int res = INT_MAX;
        if(col>=1)
        {
            res = min(res, helper(grid, row, col-1)+grid[row][col]);
        }
        if(row>=1)
        {
            res = min(res, helper(grid, row-1, col)+grid[row][col]);
        }
        return res;
    }
};

/**
 * 记忆化搜索
 * time: O(N^2)
 * space: O(N)
 * */
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        memo = grid;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                memo[i][j] = INT_MAX;
            }
        }
        return helper(grid, row-1, col-1);
    }

private:
    vector<vector<int>> memo;
    int helper(vector<vector<int>>& grid, int row, int col)
    {
        if(row==0 && col==0)
        {
            return grid[0][0];
        }
        if(memo[row][col]!=INT_MAX)
        {
            return memo[row][col];
        }
        if(col>=1)
        {
            memo[row][col] = min(memo[row][col], helper(grid, row, col-1)+grid[row][col]);
        }
        if(row>=1)
        {
            memo[row][col] = min(memo[row][col], helper(grid, row-1, col)+grid[row][col]);
        }
        return memo[row][col];
    }
};

/**
 * DP
 * time: O(N^2)
 * space: O(N^2)
 * */
class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        if(grid.size()==0 || grid[0].size()==0)
        {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(grid);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 && j==0)
                {
                    dp[i][j] = grid[i][j];
                }
                else if(i==0)
                {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
                else if(j==0)
                {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
                }
            }
        }
        return dp[row-1][col-1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    int res = s.minPathSum(grid);
    return 0;
}