#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {
        int pos = a.find_first_of('+');
        int x1 = stoi(a.substr(0,pos));
        int y1 = stoi(a.substr(pos+1,a.size()-pos-2));
        pos = b.find_first_of('+');
        int x2 = stoi(b.substr(0,pos));
        int y2 = stoi(b.substr(pos+1,b.size()-pos-2));
        int x = x1 * x2 - y1 * y2;
        int y = x1 * y2 + x2 * y1;
        string res = to_string(x) + '+' + to_string(y) + 'i';
        return res;
    }
};

class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {
        stringstream is(a+b), os;
        int x1, y1, x2, y2;
        char ch;
        is >> x1 >> ch >> y1 >> ch >> x2 >> ch >> y2;
        os << x1 * x2 - y1 * y2 << '+' << x1 * y2 + x2 * y1 << 'i';
        return os.str();
    }
};
