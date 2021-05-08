/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        int lenA = 0, lenB = 0; 
        
        if (!headA || !headB)
            return NULL;
        
        while (curA)
        {
            lenA++;
            curA = curA->next;
        }
        
        while (curB)
        {
            lenB++;
            curB = curB->next;
        }
        
        // Reset the pointer to head
        curA = headA;
        curB = headB;
        
        if (lenA > lenB)
        {
            while (lenA != lenB)
            {
                lenA--;
                curA = curA->next;
            }
        }
        else if (lenA < lenB)
        {
            while (lenA != lenB)
            {
                lenB--;
                curB = curB->next;
            }
        }
        
        while (lenA > 0)
        {
            if (curA == curB)
                return curA;
            lenA--;
            curA = curA->next;
            curB = curB->next;
        }
        
        return NULL;
    }
};
