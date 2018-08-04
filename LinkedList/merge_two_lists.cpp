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

/**
 * 直接插入排序
 * time: O(N)
 * space: O(1)
 * */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *p = l2;
        ListNode *q = new ListNode(0);
        ListNode *s = nullptr;
        ListNode *node = nullptr;
        q->next = l1;
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

/**
 * time: O(N)
 * space: O(1)
 * */
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy->next;
    }
};

/*****recursive******/
class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        if(l2 == nullptr)
        {
            return l1;
        }

        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};

int main()
{
    Solution s = Solution();
    ListNode *l2;
    return 0;
}