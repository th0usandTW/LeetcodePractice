/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode *cur = head;
        ListNode *next;
        ListNode *pre;
        bool first = true;
        while (cur != NULL && cur->next != NULL)
        {
            next = cur->next;
            
            // Swap nodes
            cur->next = next->next;
            next->next = cur;
            if (!first)
                pre->next = next;
            
            pre = cur;
            cur = cur->next;
            
            if (first)
            {
                first = false;
                head = next;
            }
        }
        
        return head;
    }
};
