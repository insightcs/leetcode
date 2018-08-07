#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        int n = S.length();
        vector<int> res;
        int slow = 0;
        int fast = 1;
        int count = 0;
        for(;slow<n;)
        {
            int index = S.substr(fast, n-fast).find_last_of(S[slow]);
            if(index==-1)
            {
                slow++;
                count++;
            }
            else
            {
                slow++;
                fast = index+fast+1;
                count++;
            }
            if(slow==fast)
            {
                res.push_back(count);
                count = 0;
            }
        }
        return res;
    }
};

class Solution
{
    vector<int> partitionLabels(string S)
    {
        int n = S.length();
        vector<int> last(26, 0);
        for(int i=0;i<n;i++)
        {
            last[S[i]-'a'] = i;
        }
        vector<int> res;
        int anchor = 0;
        int slow = 0;
        int fast = 0;
        for(;slow<n;slow++)
        {
            int index = last[S[slow]-'a'];
            if(index>fast)
            {
                fast = index;
            }
            if(fast==slow)
            {
                res.push_back(slow-anchor+1);
                anchor = slow + 1;
            }
        }
        return res;
    }
};


int main(int argc, char* argv[])
{
    string str = "eaaaabaaec";
    Solution s;
    vector<int> res = s.partitionLabels(str);
    return 0;
}
