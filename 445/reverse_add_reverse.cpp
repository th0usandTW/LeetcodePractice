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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revl1 = reverseList(l1);
        ListNode* revl2 = reverseList(l2);
        int sum = 0, carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        
        while (revl1 || revl2 || carry)
        {
            sum = 0;
            if (revl1)
            {
                sum += revl1->val;
                revl1 = revl1->next;
            }
            if (revl2)
            {
                sum += revl2->val;
                revl2 = revl2->next;
            }
            sum += carry;
            carry = sum/10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
        }
        
        return reverseList(dummy->next);
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *next;
        
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
