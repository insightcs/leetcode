#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/* BFS
 * time: O(N^2)
 * memory: O(N) */
class Solution
{
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        vector<int> res;
        for(unsigned int i=edges.size()-1;i>=0;i--)
        {
            vector<vector<int>> new_edges;
            for(unsigned int j=0;j<edges.size();j++)
            {
                if(j==i)
                {
                    continue;
                }
                new_edges.push_back(edges[j]);
            }
            if(is_connected(new_edges))
            {
                res = edges[i];
                break;
            }
        }
        return res;
    }

private:
    bool is_connected(vector<vector<int>> &edges)
    {
        if (edges.size() == 0) return false;
        int num_nodes = edges.size() + 1;
        bool *visited = new bool[num_nodes]();
        queue<int> q;
        q.push(edges[0][0]);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            visited[cur - 1] = true;
            for (unsigned int i = 0; i < edges.size(); i++)
            {
                if (edges[i][0] == cur && !visited[edges[i][1] - 1])
                {
                    q.push(edges[i][1]);
                }
                else if (edges[i][1] == cur && !visited[edges[i][0] - 1])
                {
                    q.push(edges[i][0]);
                }
            }
        }
        for (unsigned int i = 0; i < num_nodes; i++) {
            if (!visited[i]) {
                delete[] visited;
                return false;
            }
        }
        delete[] visited;
        return true;
    }
};

/* DFS
 * time: O(N^2)
 * memory: O(N)*/
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int num_nodes = edges.size();
        vector<vector<int>> graph(num_nodes+1);
        vector<int> res;
        for(auto edge: edges)
        {
            vector<bool> visited(num_nodes+1);
            if(!graph[edge[0]].empty() && !graph[edge[1]].empty())
            {
                if(!visited[edge[0]] && dfs(graph, edge[0], edge[1], visited))
                {
                    res = edge;
                    break;
                }
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return res;
    }

private:
    bool dfs(vector<vector<int>>& graph, int source, int target, vector<bool>& visited)
    {
        visited[source] = true;
        if(source==target)
        {
            return true;
        }
        for(auto nei:graph[source])
        {
            if(!visited[nei] && dfs(graph, nei, target, visited))
            {
                return true;
            }
        }
        return false;
    }
};

/* Union-Find
 * time: O(N)
 * memory: O(N)*/
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int num_nodes = edges.size();
        parent.resize(num_nodes+1);
        for(int i=1;i<num_nodes;i++)
        {
            parent[i] = i;
        }
        vector<int> res;
        for(auto it:edges)
        {
            bool ok = merge(it[0], it[1]);
            if(!ok)
            {
                res = it;
            }
        }
        return res;
    }

private:
    vector<int> parent;
    int find(int x)
    {
        // 查找当前节点的根节点
        int root = x;
        while(root!=parent[root])
        {
            root = parent[root];
        }

        // 路径压缩：修改当前节点的父辈节点的根节点为root
        int temp = x;
        while(root!=temp)
        {
            temp = parent[x];
            parent[x] = root;
            x = temp;
        }
        return root;
    }

    /*int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }*/

    bool merge(int x, int y)
    {
        int u = find(x);
        int v = find(y);
        if(u!=v)
        {
            parent[u] = v;
        }
        else
        {
            return false;
        }
        return true;
    }

};

