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
    void reorderList(ListNode* head) {
        ListNode* cur = head;
        stack<ListNode*> stk;
        int len = 0;
        
        while (cur != NULL) {
            stk.push(cur);
            cur = cur->next;
            len++;
        }

        cur = head;
        int i = 0;
        ListNode* last;
        while (i < len/2) {
            last = stk.top();
            stk.pop();
            last->next = cur->next;
            cur->next = last;
            cur = last->next;
            i++;
        }
        
        if (len % 2 == 0)
            last->next = NULL;
        else
            last->next->next = NULL;
        
    }
};
