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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<int> stk;
        ListNode* cur = head;

        vector<int> val;

        while (cur != NULL) {
            val.push_back(cur->val);
            cur = cur->next;
        }
        
        vector<int> ans(val.size(), 0);
        for (int i = 0; i < val.size(); i++) {
            while (!stk.empty() && val[i] > val[stk.top()]) {
                int idx = stk.top();
                stk.pop();
                ans[idx] = val[i];
            }
            stk.push(i);
        }
        
        while (!stk.empty()) {
            int idx = stk.top();
            stk.pop();
            ans[idx] = 0;
        }
        
        return ans;
    }
};
