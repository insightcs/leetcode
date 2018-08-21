#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(int argc, char* argv[])
{
    unsigned int A, B, C, D;
    while(cin >> A >> B >> C >> D)
    {
        map<unsigned int, unsigned int> label;
        label[A] = 0;
        label[B] = 1;
        label[C] = 2;
        label[D] = 3;
        map<unsigned int, unsigned int> predict;
        cin >> A >> B >> C >> D;
        predict[A] = 0;
        predict[B] = 1;
        predict[C] = 2;
        predict[D] = 3;
        vector<unsigned int> res(2,0);
        for(auto it:predict)
        {
            if(label.count(it.first)!=0)
            {
                if(label[it.first]==it.second)
                {
                    res[0]++;
                }
                else
                {
                    res[1]++;
                }
            }
        }
        cout << res[0] << 'A' << res[1] << 'B' << endl;
    }
    return 0;
}
