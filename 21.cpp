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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //ListNode *cur = new ListNode(0);
        ListNode *cur;
        ListNode *ans;
        
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        
        // init the cur pointer
        if (l1->val <= l2->val)
        {
            cur = l1;
            l1 = l1->next;
        }
        else
        {
            cur = l2;
            l2 = l2->next;
        }
        
        ans = cur;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        if (l1)
            cur->next = l1;
        else if (l2)
            cur->next = l2;
        
        return ans;
    }
};
