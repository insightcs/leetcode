#include <iostream>
#include <string>
using namespace std;

/**
 * @method: two pointers---对撞指针
 * @time: O(N)
 * @space: O(1)
 * */
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left<right)
        {
            while(left<n && !is_alpha_num(s[left]))
            {
                left++;
            }
            while(right>=0 && !is_alpha_num(s[right]))
            {
                right--;
            }
            if(left>=right) //空字符串
            {
                return true;
            }
            if(s[left]>='A' && s[left]<='Z')
            {
                s[left] = s[left] - 'A' + 'a';
            }
            if(s[right]>='A' && s[right]<='Z')
            {
                s[right] = s[right] - 'A' + 'a';
            }
            if(s[left]!=s[right])
            {
                return false;
            }
            else
            {
                left++;
                right--;
            }
        }
        return true;
    }

private:
    bool is_alpha_num(char ch)
    {
        if((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A') && (ch<='Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
