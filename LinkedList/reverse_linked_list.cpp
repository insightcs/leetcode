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

/**
 * 头插法
 * time: O(N)
 * space: O(1)
 */
 class Solution
 {
 public:
     ListNode* reverseList(ListNode* head)
     {
         ListNode* tail = nullptr;
         while(head)
         {
             ListNode* next = head->next;
             head->next = tail;
             tail = head;
             head = next;
         }
         return tail;
     }
 };

 /**
  * 头插法递归实现
  * time: O(N)
  * space: O(N)*/
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
