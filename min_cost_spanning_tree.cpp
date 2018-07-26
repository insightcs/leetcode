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

void min_span_tree(vector<vector<Vertex>> &MGraph)
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
}

typedef struct Edge
{
    int begin;
    int end;
    int weight;
}Edge;

bool cmp(Edge a, Edge, b)
{
    return a.weight < b.weight;
}

void min_span_tree(vector<Edge> &edges)
{
    stable_sort(edges.begin(),edges.end(), cmp);
    int num_vex = edges.size();
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
            cout << '(' << m << ',' << n << ')' << endl;
        }
    }
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