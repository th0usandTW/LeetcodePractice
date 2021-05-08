class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        if (head == NULL)
            return false;
        
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                return true;
        }
        return false;
    }
};
