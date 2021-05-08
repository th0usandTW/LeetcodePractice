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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head, *pre;
        int len = 0;
        
        while (cur)
        {
            cur = cur->next;
            len++;
        }
        
        // Find out i-th node from start
        int target = len - n;
        
        if (target == 0)
        {
            head = head->next;
            return head;
        }
        
        cur = head;
        pre = head;
        while (target > 0)
        {
            pre = cur;
            cur = cur->next;
            target--;
        }
        
        pre->next = cur->next;
        
        return head;
    }
};
