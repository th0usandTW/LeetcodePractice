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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int count = 0;
        int totalNum = 0;
        int numAns = 0;
        int groupNum;
        int remainingNum;
        ListNode* cur = root;
        vector<ListNode*> ans;
        
        
        // total number in list
        while (cur != NULL)
        {
            cur = cur->next;
            totalNum++;
        }
        
        groupNum = totalNum / k;        // Number in each group
        remainingNum = totalNum % k;    // Number need to be added in some groups
        
        cur = root;
        while (cur != NULL)
        {
            count = groupNum;
            if (remainingNum > 0)       
            {
                count++;
                remainingNum--;
            }
            
            ListNode* dummy = new ListNode(0);
            ListNode* tmp = dummy;
            while (count > 0)
            {
                tmp->next = cur;
                tmp = tmp->next;
                cur = cur->next;
                count--;
            }
            
            // Remember to set the next to NULL, or it will include the following number
            tmp->next = NULL;   
            ans.push_back(dummy->next);
            numAns++;
        }
        
        for (int i = 0; i < (k - numAns); i++)
            ans.push_back(NULL);
        
        return ans;
    }
    
};
