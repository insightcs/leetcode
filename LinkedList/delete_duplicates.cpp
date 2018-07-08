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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *p = head;
        ListNode *q;
        while(p)
        {
            q = p->next;
            while(q)
            {
                if(q->val==p->val)
                {
                    p->next = q->next;
                    delete q;
                    q = p->next;
                }
                else
                {
                    break;
                }
            }
            p = p->next;
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
    return 0;
}
