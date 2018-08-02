#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


/* DFS
 * time: O(N*M)
 * memory: O(N^2) */
/*class Solution
{
public:
    vector<double> calEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
    {
        map<string, vector<pair<string, double>>> graph;
        vector<double> res;
        for(int i=0;i<equations.size();i++)
        {
            auto it = equations[i];
            graph[it.first].push_back({it.second, values[i]});
            graph[it.second].push_back({it.first, 1.0/values[i]});
        }
        map<string, bool> visited;
        for(auto it:queries)
        {
            for(auto v:graph)
            {
                visited[v.first] = false;
            }
            if(graph.find(it.first)==graph.end() || graph.find(it.second)==graph.end())
            {
                res.push_back(-1.0);
            }
            else
            {
                double temp = 1.0;
                if(dfs(graph, it.first, it.second, 1.0, visited, temp))
                {
                    res.push_back(temp);
                }
                else
                {
                    res.push_back(-1.0);
                }
            }
        }
        return res;
    }

private:
    bool dfs(map<string, vector<pair<string, double>>>& graph, string& source, string& target, double value, map<string, bool>& visited, double &res)
    {
        visited[source] = true;
        res *= value;
        if(source==target)
        {
            return true;
        }
        for(auto it:graph[source])
        {
            if(!visited[it.first])
            {
                bool temp = dfs(graph, it.first, target, it.second, visited, res);
                if (!temp)
                {
                    res /= it.second;
                    continue;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};*/

/* Union-Find
 * time: O(N*M)
 * memory: O(N^2) */
class Solution
{
public:
    vector<double> calEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
    {
        vector<double> res;
        for(int i=0;i<equations.size();i++)
        {
            auto it = equations[i];
            graph[it.first][it.second] = values[i];
            graph[it.second][it.first] = 1.0/values[i];
            merge(it.first,it.second);
        }

        for(auto it:queries)
        {
            if(graph.count(it.first)==0 || graph.count(it.second)==0 || graph[it.first].count(it.second)==0 || graph[it.second].count(it.first)==0)
            {
                res.push_back(-1.0);
            }
            else
            {
                res.push_back(graph[it.first][it.second]);
            }
        }
        return res;
    }
private:
    map<string, map<string, double>> graph;
    double merge(string u, string v)
    {
        if(u==v)
        {
            return 1.0;
        }
        for(auto it:graph[v])
        {
            if(it.first==v)
                continue;
            graph[u][it.first] = merge(u, it.first);
            graph[it.first][u] = 1.0 / graph[u][it.first];
        }
        for(auto it:graph[u])
        {
            graph[v][it.first] = graph[v][u] * it.second;
            graph[it.first][v] = 1.0 / graph[v][it.first];
        }
    }
};

int main(int argc, char* argv[])
{
    vector<pair<string, string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0,3.0};
    vector<pair<string, string>> queries = {{"a","c"},{"b","c"},{"a","e"}};
    Solution s;
    vector<double> res = s.calEquation(equations,values,queries);
    return 0;
}
