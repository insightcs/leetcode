#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    unsigned long long bridge_length = 0;
    while(cin >> bridge_length)
    {
        unsigned int S, T, M;
        cin >> S >> T >> M;
        map<unsigned long long, bool> stone;
        for(unsigned int i=0;i<M;i++)
        {
            unsigned long long temp;
            cin >> temp;
            stone[temp] = false;
        }
        unsigned long long i = 0;
        unsigned int num_stones = 0;
        while(i<=bridge_length)
        {
            bool flag = false;
            for(unsigned int j=T;j>=S;)
            {
                if(stone.count(i+j))//有石子
                {
                    j--;
                }
                else
                {
                    flag = true;
                    i += j;
                    break;
                }
            }
            if(!flag)
            {
                i += ((S+T)/2);
                num_stones++;
            }
        }
        cout << num_stones << endl;
    }
    return 0;
}
