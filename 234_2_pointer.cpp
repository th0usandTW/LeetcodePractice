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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        if (head == NULL || head->next == NULL)
            return true;
        
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *rev = reverseList(slow->next);
        slow->next = NULL;
        
        while (rev)
        {
            if (rev->val != head->val)
                return false;
            rev = rev->next;
            head = head->next;
        }
        
        return true;
    }
    
    ListNode *reverseList(ListNode* head) {
        ListNode *pre = NULL, *next = NULL;
        
        while (head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};
