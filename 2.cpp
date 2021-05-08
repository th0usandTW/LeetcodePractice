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
        ListNode *ans;
        ListNode *cur = new ListNode(0);
        int carry = 0;
        ans = cur;
        
        while (l1 != NULL && l2 != NULL)
        {
            int sum = l1->val + l2->val + carry;
            carry = 0;
            // value >= 10
            if (sum / 10)
            {
                carry = 1;
                sum -= 10;
            }
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while (l1 != NULL)
        {
            int sum = l1->val + carry;
            carry = 0;
            // value >= 10
            if (sum / 10)
            {
                carry = 1;
                sum -= 10;
            }
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        
        while (l2 != NULL)
        {
            int sum = l2->val + carry;
            carry = 0;
            // value >= 10
            if (sum / 10)
            {
                carry = 1;
                sum -= 10;
            }
            ListNode *tmp = new ListNode(sum);
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        
        if (carry)
        {
            ListNode *tmp = new ListNode(1);
            cur->next = tmp;
            cur = cur->next;
        }
        
        return ans->next;
    }
};
