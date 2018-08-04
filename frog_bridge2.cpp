#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(int argc, char* argv[])
{
    unsigned long long bridge_length = 0;
    while(cin >> bridge_length)
    {
        unsigned int S, T, M;
        cin >> S >> T >> M;
        set<unsigned long long> stone;
        for(unsigned int i=0;i<M;i++)
        {
            unsigned long long temp;
            cin >> temp;
            stone.insert(temp);
        }
        vector<unsigned int> num_stones(bridge_length+1, 0);
        for(unsigned long long i=S;i<=bridge_length;i++)
        {
            unsigned int num = num_stones[i-S];
            for(unsigned int j=S+1;j<=T&&(i-j>=0);j++)
            {
                 if(num_stones[i-j]<num)
                 {
                     num = num_stones[i-j];
                 }
            }
            num_stones[i] = num + (stone.find(i)!=stone.end() ? 1 : 0);
        }
        unsigned int min_num = num_stones[bridge_length];
        for(unsigned int i=S;i<=T;i++)
        {
            min_num = min(min_num, num_stones[bridge_length-i]);
        }
        cout << min_num << endl;
    }
    return 0;
}
