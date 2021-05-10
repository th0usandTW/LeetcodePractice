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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        ListNode* dummy1 = new ListNode(0);
        ListNode* dummy2 = new ListNode(0);
        ListNode* smallList = dummy1;
        ListNode* bigList = dummy2;
        
        while (cur != NULL)
        {
            if (cur->val < x)
            {
                smallList->next = cur;
                smallList = smallList->next;
            }
            else
            {
                bigList->next = cur;
                bigList = bigList->next;
            }
            
            cur = cur->next;
        }
        
        smallList->next = dummy2->next;
        bigList->next = NULL;
        return dummy1->next;
    }
};
