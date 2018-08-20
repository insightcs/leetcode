#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


/**
 * @method: 计数排序
 * @time: O(N)
 * @space: O(N)
 * 1. 统计频数
 * 2. 排序
 * */
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        unordered_map<char, int> freq;
        for(auto it:s)
        {
            freq[it]++;
        }
        vector<vector<char>> record(n+1);
        for(auto it:freq)
        {
            record[it.second].push_back(it.first);
        }
        string res;
        for(int i=record.size()-1;i>0;i--)
        {
            for(auto it:record[i])
            {
                for(int j=0;j<i;j++)
                {
                    res += it;
                }
            }
        }
        return res;
    }
};

/**
 * @method: 计数排序优化
 * @time: O(N)
 * @space: O(N)
 * 1. 统计频数
 * 2. 排序
 * */
class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        unordered_map<char, int> freq;
        for(auto it:s)
        {
            freq[it]++;
        }
        set<pair<int, char>> set;
        for(auto it:freq)
        {
            set.insert(make_pair(it.second, it.first));
        }
        string res;
        for(auto it=set.crbegin();it!=set.crend();it++)
        {
            for(int i=0;i<it->first;i++)
            {
                res += it->second;
            }
        }
        return res;
    }
};

/**
 * @method: 三路快排
 * @time: O(N)
 * @space: O(1)
 * 1. 统计频数
 * 2. 三路快排
 * */
class Solution2
{
public:
    string frequencySort(string s)
    {
        int n = s.length();
        vector<int> freq(256);
        for(auto it:s)
        {
            freq[it]++;
        }

        vector<int> index(256);
        for(int i=0;i<256;i++)
        {
            index[i] = i;
        }
        quick_sort(freq, index, 0, 255);

        string res;
        for(int i=255;i>=0;i--)
        {
            if(freq[index[i]]==0)
            {
                return res;
            }
            for(int j=0;j<freq[index[i]];j++)
            {
                res += index[i];
            }
        }
        return res;
    }

private:
    void quick_sort(vector<int>& freq, vector<int>& index, int left, int right)
    {
        if(left<right)
        {
            vector<int> pivot = partition(freq, index, left, right);
            quick_sort(freq, index, left, pivot[0]);
            quick_sort(freq, index, pivot[1], right);
        }
    }

    vector<int> partition(vector<int>& freq, vector<int>& index, int left, int right)
    {
        srand((unsigned)time(nullptr));
        int random = rand() % (right-left+1) + left;
        int pivot = freq[index[random]];
        int lt = left - 1; //[left, lt] < pivot
        int gt = right + 1;  //[gt, right] > pivot
        int pos = left;  //[lt+1, pos] == pivot
        while(pos<gt)
        {
            if(freq[index[pos]]<pivot)
            {
                swap(index[pos++], index[++lt]);
            }
            else if(freq[index[pos]]>pivot)
            {
                swap(index[pos], index[--gt]);
            }
            else
            {
                pos++;
            }
        }
        return {lt, gt};
    }
};

int main(int argc, char* argv[])
{
    string s = "tree";
    string res = Solution2().frequencySort(s);
    return 0;
}

