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
    void deleteNode(ListNode* node)
    {
        if(!node)
        {
            return;
        }
        ListNode* next = node->next;
        *node = *next;
        delete next;
    }
};
