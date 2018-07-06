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

/*思路：
 * 1. Halve the list into two lists.
 * 2. Reverse one of the sub lists.
 * 2. Compare two sub lists.*/

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if(!head||!head->next)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(true)
        {
            if(!fast->next||!fast->next->next)
            {
                break;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* sub_head = slow->next;
        sub_head = reverse_list(sub_head);

        while(head&&sub_head)
        {
            if(head->val != sub_head->val)
            {
                return false;
            }
            head = head->next;
            sub_head = sub_head->next;
        }
        return true;
    }

    ListNode* reverse_list(ListNode* head)
    {
        if(!head)
        {
            return nullptr;
        }
        ListNode* dummy = nullptr;
        ListNode* temp = nullptr;
        while(head)
        {
            temp = head->next;
            head->next = dummy;
            dummy = head;
            head = temp;
        }
        return dummy;
    }
};
