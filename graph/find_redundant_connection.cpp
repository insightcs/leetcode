#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur - 1] = true;
            for (unsigned int i = 0; i < edges.size(); i++) {
                if (edges[i][0] == cur && !visited[edges[i][1] - 1]) {
                    q.push(edges[i][1]);
                } else if (edges[i][1] == cur && !visited[edges[i][0] - 1]) {
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
