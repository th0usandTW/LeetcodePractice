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
        ListNode* pre;
        ListNode* tail = cur;
        
        while (cur != NULL && cur->next != NULL)
        {
            tail = cur;
            while (tail->next != NULL)
            {
                pre = tail;
                tail = tail->next;
            }
            pre->next = NULL;
            tail->next = cur->next;
            cur->next = tail;
            cur = tail->next;
        }
    }
};
