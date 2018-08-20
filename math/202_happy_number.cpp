#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> table;
        while(true)
        {
            int sum = 0;
            while (n)
            {
                int num = n % 10;
                n /= 10;
                sum += num * num;
            }
            if (sum == 1)
            {
                return true;
            }
            if (table.count(sum) != 0)
            {
                return false;
            }
            table.insert(sum);
            n = sum;
        }
    }
};