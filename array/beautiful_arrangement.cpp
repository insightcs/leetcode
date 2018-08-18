#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res;
        set<int> s;
        res.push_back(1);
        s.insert(1);
        int diff = k;
        for(int j=0;j<n-1;j++)
        {
            if(diff==0)
            {
                for (int j=1; j <= k; j++)
                {
                    int a = res[j] + j;
                    int b = res[j] - j;
                    if (b > 0 && s.count(b) == 0)
                    {
                        res.push_back(b);
                        s.insert(b);
                        break;
                    } else if (a <= n && s.count(a) == 0)
                    {
                        res.push_back(a);
                        s.insert(a);
                        break;
                    }
                }
            }
            else
            {
                int a = res[j] + diff;
                int b = res[j] - diff;
                if (b > 0 && s.count(b) == 0)
                {
                    res.push_back(b);
                    s.insert(b);
                }
                else if (a <= n && s.count(a) == 0)
                {
                    res.push_back(a);
                    s.insert(a);
                }
                diff--;
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res;
        int i = 1, j = n;
        while(i<=j)
        {
            if(k>1)
            {
                res.push_back((k--)%2 ? i++ : j--);
            }
            else
            {
                res.push_back(i++);
            }
        }
        return res;
    }
};

class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res;
        int cur = 0;
        for(int i=1;i<n-k;i++)
        {
            res[cur++] = i;
        }
        for(int i=0;i<=k+1;i++)
        {
            res[cur++] = (i%2==0) ? (n-k + i/2) : (n-i/2);
        }
        return res;
    }
};