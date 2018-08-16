#include <iostream>
#include <vector>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
}ListNode;

/**
 * time: O(N)
 * space: O(N)
 * */
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        vector<int> num1;
        vector<int> num2;
        ListNode* p = l1;
        while(p)
        {
            num1.push_back(p->val);
            p = p->next;
        }
        p = l2;
        while(p)
        {
            num2.push_back(p->val);
            p = p->next;
        }
        int n1 = num1.size();
        int n2 = num2.size();
        int plus = 0;
        p = nullptr;
        for(int i=n1-1,j=n2-1;i>=0||j>=0||plus;i--,j--)
        {
            int sum = plus;
            if(i>=0)
            {
                sum += num1[i];
            }
            if(j>=0)
            {
                sum += num2[j];
            }
            plus = sum / 10;
            ListNode* node = new ListNode(sum%10);
            node->next = p;
            p = node;
        }
        return p;
    }
};
