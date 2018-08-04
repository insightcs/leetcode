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


class Solution
{
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k)
    {
        int length = 0;
        ListNode* p = root;
        while(p)
        {
            length++;
            p = p->next;
        }
        int avg_length = length / k;
        int rest = length % k;
        vector<ListNode*> heads;
        length = 0;
        p = root;
        heads.push_back(p);
        k--;
        while(p)
        {
            length++;
            if(length==avg_length+(rest>0?1:0) && k>0)
            {
                ListNode* temp = p->next;
                heads.push_back(temp);
                p->next = nullptr;
                p = temp;
                k--;
                rest--;
                length = 0;
            }
            else
            {
                p = p->next;
            }
        }
        while(k>0)
        {
            heads.push_back(nullptr);
            k--;
        }
        return heads;
    }
};

