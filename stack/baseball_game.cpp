#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespacestd;

class Solution
{
    int calPoints(vector<string> &ops)
    {
        stack<int> round_score;
        int total_score = 0;
        for(auto it:ops)
        {
            if(it == "C")
            {
                total_score -= round_score.top();
                round_score.pop();
            }
            else if(it == "D")
            {
                int pre_score = round_score.empty() ? 0 : round_score.top();
                total_score += pre_score * 2;
                round_score.push(pre_score*2);
            }
            else if(it == "+")
            {
                int pre_score = 0;
                if(!round_score.empty())
                {
                    pre_score = round_score.top();
                    round_score.pop();
                }
                int pre_pre_score = round_score.empty() ? 0 : round_score.top();
                round_score.push(pre_score);
                round_score.push(pre_pre_score+pre_score);
                total_score += (pre_pre_score+pre_score);
            }
            else
            {
                int score = stoi(it);
                round_score.push(score);
                total_score += score;
            }
        }
        return total_score;
    }
};
