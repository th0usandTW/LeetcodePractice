class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* cur = head;
        int len = 0;
        
        if (head == NULL || head->next == NULL)
            return true;
        
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->next;
            len++;
        }
        
        ListNode* tmp;
        cur = head;
        for (int i = 0; i < len/2; i++) {
            tmp = stk.top();
            stk.pop();
            
            if (cur->val != tmp->val)
                return false;
            cur = cur->next;
        }
        
        return true;
    }
    

};
