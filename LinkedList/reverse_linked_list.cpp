#include <iostream>
#include <stack>
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

/********iterative**********/
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *p = head;
        stack<int> s;
        while(p)
        {
            s.push(p->val);
            p = p->next;
        }
        p = head;
        while(!s.empty())
        {
            p->val = s.top();
            s.pop();
            p = p->next;
        }
        return head;
    }
};

/********iterative:头插法**********/
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode *dummy = nullptr;
        ListNode *temp = nullptr;
        while(head!= nullptr)
        {
            temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};

/********recursive**********/
class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        return helper(head, nullptr);
    }

    ListNode* helper(ListNode* head, ListNode* new_head)
    {
        if(head == nullptr)
        {
            return new_head;
        }
        ListNode *next = head->next;
        head->next = new_head;
        return helper(next, head);
    }
};
