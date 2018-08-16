#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int res = 0;
        int bal = 0;
        for(int i=0;i<S.size();i++)
        {
            if(it=='(')
            {
                bal++;
            }
            else
            {
                bal--;
                if(S[i-1]=='(')
                {
                    res += 1 << bal;
                }
            }
        }
        return res;
    }
};