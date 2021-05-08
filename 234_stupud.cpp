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
        vector<int> v;
        int len = 0;
        ListNode *cur = head;
        
        while (cur)
        {
            v.push_back(cur->val);
            cur = cur->next;
            len++;
        }
        
        for (int i = 0; i < len/2; i++)
        {
            if (v[i] != v[len-i-1])
                return false;
        }
        
        return true;
    }
};
