#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/* 判断有向图是否为连通图，深度优先遍历
 * time: O(N^2)
 * memory: O(N^2)*/
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<vector<int>> graph(rooms.size(), vector<int>(rooms.size()));
        build_graph(rooms, graph);
        bool *visited = new bool[rooms.size()] ();
        dfs(graph, 0, visited);
        for(unsigned int i=0;i<rooms.size();i++)
        {
            if(!visited[i])
            {
                delete [] visited;
                return false;
            }
        }
        delete [] visited;
        return true;
    }

private:
    void build_graph(vector<vector<int>>& rooms, vector<vector<int>>& graph)
    {
        for (unsigned int i = 0; i < rooms.size(); i++)
        {
            for (unsigned int j = 0; j < rooms[i].size(); j++)
            {
                graph[i][rooms[i][j]] = 1;
                //graph[rooms[i][j]][i] = 1;
            }
            graph[i][i] = 0;
        }
    }

    void dfs(vector<vector<int>>& graph, int i, bool *visited)
    {
        visited[i] = true;
        for(unsigned int j=0;j<graph.size();j++)
        {
            if(graph[i][j]==1 && !visited[j])
            {
                dfs(graph, j, visited);
            }
        }
    }
};

/* 广度优先遍历BFS
 * time: O(N+E)
 * memory: O(N) */
class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        if(!rooms.size())   return true;
        queue<int> q;
        bool *visited = new bool[rooms.size()] ();
        q.push(0);
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            for(unsigned int i=0;i<rooms[cur].size();i++)
            {
                if(rooms[cur][i]!=cur && !visited[rooms[cur][i]])
                {
                    q.push(rooms[cur][i]);
                }
            }
        }
        for(unsigned int i=0;i<rooms.size();i++)
        {
            if(!visited[i])
            {
                delete [] visited;
                return false;
            }
        }
        delete [] visited;
        return true;
    }
};