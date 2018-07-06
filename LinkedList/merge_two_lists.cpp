#include <iostream>

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        this->val = x;
        this->next = nullptr;
    }
}ListNode;

class Solution
{
public:
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *p = l2;
        ListNode *q = new ListNode(0);
        ListNode *s = nullptr;
        ListNode *node = nullptr;
        q->next = l1;
        for(node=q;node->next&&node->next->val<p->val;node=node->next);

        while(p)
        {
            for(node=q;node->next&&node->next->val<p->val;node=node->next);
            s = p->next;
            p->next = node->next;
            node->next = p;
            p = s;
        }
        return q->next;
    }
};

int main()
{
    Solution s = Solution();
    ListNode *l2;
    return 0;
}