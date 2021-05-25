class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;

        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return head;
        
        ListNode* new_head = head->next;
        ListNode* next = cur->next->next;
        cur->next->next = cur;
        cur->next = swapPairs(next);
        
        return new_head;
    }
};
