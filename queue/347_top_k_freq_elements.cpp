#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

typedef struct compare
{
    bool operator () (const pair<int, int> a, const pair<int, int> b)
    {
        return a.first < b.first;
    }
}compare;

/**
 * @method: 优先队列
 * @time: O(NlogN)
 * @space: O(N)
 * */
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for(auto it:nums)
        {
            map[it]++;
        }

        vector<int> res;
        if(map.size()<k)
        {
            return res;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it:map)
        {
            pq.push(make_pair(it.second, it.first));
        }
        for(int i=0;i<k;i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};

/**
 * @method: 优先队列优化版
 * @time: O(Nlogk)
 * @space: O(N)
 * */
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> map;
        for(auto it:nums)
        {
            map[it]++;
        }

        vector<int> res;
        if(map.size()<k)
        {
            return res;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it:map)
        {
            if(pq.size()==k)
            {
                if(it.second>pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(it.second, it.first));
                }
            }
            else
            {
                pq.push(make_pair(it.second, it.first));
            }
        }
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
