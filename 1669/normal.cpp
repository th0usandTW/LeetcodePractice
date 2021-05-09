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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *rmHead = list1;
        ListNode *rmTail;
        ListNode *cur = list1;
        int count = 0;
        
        while (cur != NULL)
        {
            if ((count+1) == a)
            {
                rmHead = cur;
            }
            if ((count) == b)
            {
                rmTail = cur->next;
                break;
            }
            cur = cur->next;
            count++;
        }
        
        cur = list2;
        while (cur->next != NULL)
        {
            cur = cur->next;
        }
        
        rmHead->next = list2;
        cur->next = rmTail;
        
        return list1;
    }
};
