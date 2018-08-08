#include <iostream>
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
    ListNode* detectCycle(ListNode* head)
    {
        if(!head)
        {
            return nullptr;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        do
        {
            if(!fast->next || !fast->next->next)
            {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);

        ListNode* entry = head;
        while(slow!=entry)
        {
            slow = slow->next;
            entry = entry->next;
        }
        return entry;
    }
};