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
    ListNode* rotateRight(ListNode* head, int k)
    {
        int n = 0;
        ListNode* p = head;
        while(p)
        {
            p = p->next;
            n++;
        }
        if(n==0 || k==0)    return head;
        k %= n;
        p = head;
        int i = n - k;
        while(p && i--)
        {
            p = p->next;
        }
        p = reverse_list(p, k, nullptr);
        head = reverse_list(head, n-k, p);
        head = reverse_list(head, n, nullptr);
        return head;
    }

private:
    ListNode* reverse_list(ListNode* head, int k, ListNode* pre)
    {
        ListNode* p = pre;
        while(head && k--)
        {
            ListNode* temp = head->next;
            head->next = p;
            p = head;
            head = temp;
        }
        return p;
    }
};

ListNode* create_list(vector<int>& nums)
{
    int n = nums.size();
    if(n==0)    return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* p = head;
    for(int i=1;i<n;i++)
    {
        p->next = new ListNode(nums[i]);
        p = p->next;
    }
    return head;
}

int main(int argc, char* argv[])
{
    vector<int> list = {1,2,3,4,5};
    ListNode* head = create_list(list);
    head = Solution().rotateRight(head, 2);
    return 0;
}
