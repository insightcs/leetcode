#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int num_nodes = graph.size();
        vector<bool> visited(num_nodes, false);
        vector<int> setA, setB;
        for(int k=0;k<num_nodes;k++)
        {
            queue<int> q;
            if (!visited[k])
            {
                q.push(k);
            }
            while (!q.empty())
            {
                int node = q.front();
                queue<int> temp;
                q.pop();
                visited[node] = true;
                setA.push_back(node);
                for (auto it:graph[node])
                {
                    if(!visited[it])
                    {
                        setB.push_back(it);
                        temp.push(it);
                        visited[it] = true;
                    }
                }
                while (!temp.empty())
                {
                    int index = temp.front();
                    temp.pop();
                    for (auto it:graph[index])
                    {
                        if(!visited[it])
                        {
                            q.push(it);
                        }
                    }
                }
            }
        }
        if (is_connected(graph, setA))
        {
            return false;
        }
        if(is_connected(graph, setB))
        {
            return false;
        }
        return true;
    }

private:
    bool is_connected(vector<vector<int>>& graph, vector<int>& set)
    {
        for(int i=0;i<set.size();i++)
        {
            for(int j=i+1;j<set.size();j++)
            {
                if(find(graph[set[i]].begin(),graph[set[i]].end(),set[j])!=graph[set[i]].end())
                {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution
{
public:
    bool isBipartite(vector<vector<int>>& graph)
    {
        int num_nodes = graph.size();
        vector<int> color(num_nodes, 0);
        for(int i=0;i<num_nodes;i++)
        {
            queue<int> q;
            if (color[i]==0)
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (auto it:graph[node])
                {
                    if(color[it]==0)
                    {
                        q.push(it);
                        color[it] = color[node] == 1 ? 2 : 1;
                    }
                    else if(color[it]==color[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

static int x = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();


