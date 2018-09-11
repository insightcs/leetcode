#include <iostream>
#include <vector>
using namespace std;

/**
 * @method: recursion
 * @time: O(2^(m*n))
 * @space: O(m*n)
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        if(m==0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        return find_ways(obstacleGrid, m-1, n-1);
    }

private:
    int find_ways(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0 || grid[x][y]==1)
        {
            return 0;
        }
        if(x==0 && y==0)
        {
            return 1;
        }
        return find_ways(grid, x-1,y) + find_ways(grid, x, y-1);
    }
};

/**
 * @method: 记忆化搜索
 * @time: O(m*n)
 * @space: O(m*n)
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        if(m==0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return find_ways(obstacleGrid, m-1, n-1);
    }

private:
    vector<vector<int>> memo;
    int find_ways(vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0 || grid[x][y]==1)
        {
            return 0;
        }
        if(x==0 && y==0)
        {
            return 1;
        }
        if(memo[x][y]!=-1)
        {
            return memo[x][y];
        }
        memo[x][y] = find_ways(grid, x-1,y) + find_ways(gird, x, y-1);
        return memo[x][y];
    }
};

/**
 * @method: DP
 * @time: O(m*n)
 * @space: O(m*n)
 */
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        int m = obstacleGrid.size();
        if(m==0)
        {
            return 0;
        }
        int n = obstacleGrid[0].size();
        vector<vector<int>> memo(m, vector<int>(n));
        memo[0][0] = (obstacleGrid[0][0]==1 ? 0 : 1);
        for(int i=1;i<n;i++)
        {
            memo[0][i] = (obstacleGrid[0][i]==1 ? 0 : memo[0][i-1]);
        }
        for(int i=1;i<m;i++)
        {
            memo[i][0] = (obstacleGrid[i][0]==1 ? 0 : memo[i-1][0]);
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    memo[i][j] = memo[i-1][j] + memo[i][j-1];
                }
            }
        }
        return memo[m-1][n-1];
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    int res = s.uniquePaths(7, 3);
    return 0;
}