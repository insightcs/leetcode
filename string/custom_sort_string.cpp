#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string customSortString(string S, string T)
    {
        int n1 = S.size();
        int n2 = T.size();
        vector<int> table(255,0);
        for(int i=0;i<n1;i++)
        {
            table[S[i]] = i;
        }
        for(int i=1;i<n2;i++)
        {
            if(table[T[i-1]]>table[T[i]])
            {
                char temp = T[i];
                int j = i - 1;
                for(;j>=0&&table[T[j]]>table[temp];j--)
                {
                    T[j+1] = T[j];
                }
                T[j+1] = temp;
            }
        }
        return T;
    }
};

class Solution
{
    string customSortString(string S, string T)
    {
        compare cmp(S);
        sort(T.begin(), T.end(), cmp);
        return T;
    }

private:
    typedef struct compare
    {
        string S;
        compare(string str)
        {
            this->S = str;
        }
        bool operator () (char a, char b)
        {
            return this->S.find(a) < this->S.find(b);
        }
    }compare;
};

int main(int argc, char* argv[])
{
    string a = "kqep";
    string b = "pekeq";
    Solution s;
    string res = s.customSortString(a, b);
    return 0;
}