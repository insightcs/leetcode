#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution
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
