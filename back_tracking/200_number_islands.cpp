#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @method: dfs
 * @time: O(N^2)
 * @space: O(N^2)
 * */
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if(m==0)
        {
            return 0;
        }
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    const int direction[4][2] =
            {
                    {0, -1},
                    {0, 1},
                    {-1, 0},
                    {1, 0}
            };

    bool is_valid(int m, int n, int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
        {
            return false;
        }
        return true;
    }

    void dfs(vector<vector<char>>& grid, int x,  int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        if(!is_valid(m, n, x, y) || grid[x][y]=='0')
        {
            return;
        }
        grid[x][y] = '0';
        for(int i=0;i<4;i++)
        {
            dfs(grid, x+direction[i][0], y+direction[i][1]);
        }
    }
};

/**
 * @method: bfs
 * @time: O(N^2)
 * @space: O(N^2)
 * */
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if(m==0)
        {
            return 0;
        }
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }

private:
    const int direction[4][2] =
            {
                    {0, -1},
                    {0, 1},
                    {-1, 0},
                    {1, 0}
            };

    bool is_valid(int m, int n, int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
        {
            return false;
        }
        return true;
    }

    void bfs(vector<vector<char>>& grid, int x,  int y)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x,y});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            grid[it.first][it.second] = '0';
            for(int i=0;i<4;i++)
            {
                int tmp_x = it.first + direction[i][0];
                int tmp_y = it.second + direction[i][1];
                if(is_valid(m, n, tmp_x, tmp_y) && grid[tmp_x][tmp_y]=='1')
                {
                    q.push({tmp_x, tmp_y});
                }
            }
        }
    }
};

/**
 * @method: Union Find Set
 * @time: O(N^2)
 * @space: O(N^2)
 * */
class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if(m==0)
        {
            return 0;
        }
        int n = grid[0].size();
        UnionFind union_set(grid);
        int res = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    for(int k=0;k<4;k++)
                    {
                        int tmp_x = i + direction[k][0];
                        int tmp_y = j + direction[k][1];
                        if(is_valid(m, n, tmp_x, tmp_y) && grid[tmp_x][tmp_y]=='1')
                        {
                            union_set.merge(i*n+j, tmp_x*n+tmp_y);
                        }
                    }
                }
            }
        }
        return union_set.count;
    }

private:
    struct UnionFind
    {
        vector<int> parent;
        int count;
        UnionFind(vector<vector<char>>& grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            parent = vector<int>(m*n, -1);
            count = 0;
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]=='1')
                    {
                        parent[i*n+j] = i*n+j;
                        count++;
                    }
                }
            }
        }

        void merge(int x, int y)
        {
            int m = find(x);
            int n = find(y);
            if(m!=n)
            {
                parent[m] = n;
                count--;
            }
        }

        int find(int x)
        {
            return parent[x]==x ? x : parent[x]=find(parent[x]);
        }
    };
    const int direction[4][2] =
            {
                    {0, -1},
                    {0, 1},
                    {-1, 0},
                    {1, 0}
            };

    bool is_valid(int m, int n, int x, int y)
    {
        if(x<0 || y<0 || x>=m || y>=n)
        {
            return false;
        }
        return true;
    }
};
