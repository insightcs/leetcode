#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

typedef struct Vertex
{
    int adjvex;
    int weight;
}Vertex;

/*void min_span_tree(vector<vector<Vertex>> &MGraph)
{
    int num_vex = MGraph.size();
    if(num_vex==0)
    {
        return;
    }
    vector<int> cost(num_vex, INT_MAX);
    vector<int> adjvex(num_vex, 0);
    cost[0] = 0;
    for(auto it:MGraph[0])
    {
        cost[it.adjvex] = it.weight;
    }
    for(int i=1;i<num_vex;i++)
    {
        int min = INT_MAX;
        int k = 0;
        for(int j=1;j<num_vex;j++)
        {
            if(cost[j]!=0 && cost[j]<min)
            {
                min = cost[j];
                k = j;
            }
        }
        cout << '(' << adjvex[k] << ',' << k << ')' << endl;
        cost[k] = 0;
        for(auto it:MGraph[k])
        {
            if(cost[it.adjvex]!=0 && it.weight < cost[it.adjvex])
            {
                cost[it.adjvex] = it.weight;
                adjvex[it.adjvex] = k;
            }
        }
    }
}*/

typedef struct Edge
{
    int begin;
    int end;
    int weight;
}Edge;

bool cmp(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(vector<int> &parent, int x)
{
    int root = x;
    while(root!=parent[root])
    {
        root = parent[root];
    }
    int temp = x;
    while(root!=temp)
    {
        temp = parent[x];
        parent[x] = root;
        x = temp;
    }
    return root;
}

void min_span_tree(vector<Edge> &edges)
{
    int num_vex = edges.size();
    if(num_vex==0)  return;
    stable_sort(edges.begin(),edges.end(), cmp);
    vector<int> parent(edges.size(), 0);
    for(int i=0;i<num_vex;i++)
    {
        parent[i] = i;
    }
    for(auto it:edges)
    {
        int m = find(parent, it.begin);
        int n = find(parent, it.end);
        if(m!=n)
        {
            parent[m] = n;
            cout << '(' << it.begin << ',' << it.end << ')' << endl;
        }
    }
}


int main(int argc, char* argv[])
{
    vector<Edge> edges;
    edges.push_back({4,7,7});
    edges.push_back({2,8,8});
    edges.push_back({0,1,10});
    edges.push_back({0,5,11});
    edges.push_back({1,8,12});
    edges.push_back({3,7,16});
    edges.push_back({1,6,16});
    edges.push_back({5,6,17});
    edges.push_back({1,2,18});
    edges.push_back({6,7,19});
    edges.push_back({3,4,20});
    edges.push_back({3,8,21});
    edges.push_back({2,3,22});
    edges.push_back({3,6,24});
    edges.push_back({4,5,26});
    min_span_tree(edges);
    return 0;
}