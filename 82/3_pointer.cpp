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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        pre->next = head;
        while (cur->next != NULL)
        {
            // cur and next are differenct, so move to next number
            if (cur->val != next->val)
            {
                pre = cur;
                cur = cur->next;
                next = cur->next;
            }
            else
            {
                // Move next until next is different from cur
                while ((next != NULL) && (cur->val == next->val))
                {
                    next = next->next;
                }
                // The rest of numbers are the same, need to end the process
                if (next == NULL)
                {
                    pre->next = NULL;
                    cur->next = NULL;   // Used to end the while loop
                }
                else
                {
                    // Find the differenct number
                    pre->next = next;
                    cur = next;
                    next = cur->next;
                }
            }
        }
        
        return dummy->next;
    }
};
