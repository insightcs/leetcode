#include <iostream>
#include <set>
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
    bool hasCycle(ListNode* head)
    {
        std::set<ListNode*> table;
        while(head)
        {
            if(table.find(head) != table.end())
            {
                return true;
            }
            table.insert(head);
            head = head->next;
        }
        return false;
    }
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if(head == nullptr)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
