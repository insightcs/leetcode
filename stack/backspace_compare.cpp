#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* time: O(M+N)
 * memory: O(N)*/
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        S = helper(S);
        T = helper(T);
        return S.compare(T) == 0 ? true : false;
    }

    string helper(string &str)
    {
        string res;
        for(auto it:str)
        {
            if(it!='#')
            {
                res.push_back(it);
            }
            else if(!res.empty())
            {
                res.pop_back();
            }
        }
        return res;
    }
};


/* time: O(M+N)
 * memory: O(1)*/
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        S = helper(S);
        T = helper(T);
        return S.compare(T) == 0 ? true : false;
    }

    string helper(string &str)
    {
        string res;
        for(auto it:str)
        {
            if(it!='#')
            {
                res.push_back(it);
            }
            else if(!res.empty())
            {
                res.pop_back();
            }
        }
        return res;
    }
};
