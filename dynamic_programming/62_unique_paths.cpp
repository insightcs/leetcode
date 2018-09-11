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
    int uniquePaths(int m, int n)
    {
        return find_ways(m, n);
    }

private:
    int find_ways(int x, int y)
    {
        if(x<0 || y<0)
        {
            return 0;
        }
        if(x==1 && y==1)
        {
            return 1;
        }
        return find_ways(x-1,y) + find_ways(x, y-1);
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
    int uniquePaths(int m, int n)
    {
        memo = vector<vector<int>>(m+1, vector<int>(n+1, -1));
        return find_ways(m, n);
    }

private:
    vector<vector<int>> memo;
    int find_ways(int x, int y)
    {
        if(x<=0 || y<=0)
        {
            return 0;
        }
        if(x==1 && y==1)
        {
            return 1;
        }
        if(memo[x][y]!=-1)
        {
            return memo[x][y];
        }
        memo[x][y] = find_ways(x-1,y) + find_ways(x, y-1);
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
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n));
        for(int i=0;i<n;i++)
        {
            memo[0][i] = 1;
        }
        for(int i=0;i<m;i++)
        {
            memo[i][0] = 1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                memo[i][j] = memo[i-1][j] + memo[i][j-1];
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