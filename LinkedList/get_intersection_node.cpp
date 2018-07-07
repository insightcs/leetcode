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

/*iterative:
 * time: O(n1+n2)
 * memory: O(n1)*/
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        std::set<ListNode*> s;
        while(headA)
        {
            s.insert(headA);
            headA = headA->next;
        }
        if(s.empty())
        {
            return nullptr;
        }
        while(headB)
        {
            if(s.find(headB)!=s.end())
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};

/*iterative
 * time: O(n1*n2)
 * memory: O(1)*/
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode *p = nullptr;
        while(headA)
        {
            p = headB;
            while(p)
            {
                if(headA == p)
                {
                    return headA;
                }
                p = p->next;
            }
            headA = headA->next;
        }
        return nullptr;
    }
};

/*iterative
 * time: O(n1+n2)
 * memory: O(1)*/
class Solution
{
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        ListNode *p_headA = headA;
        ListNode *p_headB = headB;
        while(p_headA != p_headB)
        {
            p_headA ? p_headA->next : headB;
            p_headB ? p_headB->next : headA;
        }
        return p_headA;
    }
};
