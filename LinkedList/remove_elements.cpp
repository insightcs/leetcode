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
    ListNode* removeElements(ListNode* head, int val)
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* node = dummy;
        while(node->next)
        {
            if(node->next->val == val)
            {
                ListNode* pre = node->next->next;
                delete node->next;
                node->next = pre;
            }
            else
            {
                node = node->next;
            }
        }
        return dummy->next;
    }
};

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if(head == nullptr)
        {
            return nullptr;
        }
        head->next = removeElements(head->next, val);
        return head->val == val ? head->next : head;
    }
};
