#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<char> kth_most_num_str(string &str, int k)
    {
        vector<vector<char>> temp(str.size()+1);
        map<char, int> num_str;
        for(auto it:str)
        {
            num_str[it]++;
        }
        for(auto it:num_str)
        {
            temp[it.second].push_back(it.first);
        }
        for(int i=temp.size()-1,j=0;i>=0;i--)
        {
            if(temp[i].empty())
            {
                continue;
            }
            j++;
            if(j==k)
            {
                return temp[i];
            }
        }
        vector<char> res;
        return res;
    }
};


int main(int argc, char *argv[])
{
    Solution s;
    string str = "123333221445";
    vector<char> res = s.kth_most_num_str(str,3);
    return 0;
}