class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre;
        ListNode* next;
        bool init = false;
        
        if (head == NULL)
            return NULL;

        while (cur != NULL && cur->next != NULL) {
            next = cur->next;
            cur->next = next->next;
            next->next = cur;
            
            if (init == true) {
                pre->next = next;
            }
            
            if (init == false) {
                head = next;
                init = true;
            }
            pre = cur;
            cur = cur->next;
        }
        
        return head;
    }
};
