#include <iostream>
#include <vector>
#include <set>
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
 * HashSet
 * time: O(N+G)
 * space: O(G)
 */
class Solution
{
public:
    int numComponents(ListNode* head, vector<int>& G)
    {
        int res = 0;
        set<int> s(G.begin(), G.end());
        while(head)
        {
            if(s.count(head->val))
            {
                if(!head->next || s.count(head->next->val)==0)
                {
                    res++;
                }
            }
        }
        return res;
    }
};