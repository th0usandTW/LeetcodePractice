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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* next;
        
        while (cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        return pre;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        
        int count = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = dummy;
        ListNode* subHead;
        ListNode* subTail;
        ListNode* breakP1;
        ListNode* breakP2;
        
        // Find boundary
        while (cur != NULL) {
            if (left == count + 1) {
                breakP1 = pre;
                subHead = cur;
            }
            
            if (right == count + 1) {
                breakP2 = cur->next;
                subTail = cur;
                cur->next = NULL;
                break;
            }
            pre = cur;
            cur = cur->next;
            count++;
        }
        
        if (left == 1)
            head = reverseList(subHead);
        else
            breakP1->next = reverseList(subHead);
        
        cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        
        cur->next = breakP2;
        return head;
    }
};
