/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        TreeNode* cur;
        
        if (root == NULL)
            return ans;
        
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();               // Be careful here, should use variable to remember the current q size
            for (int i = 0; i < n; i++) {   // DO NOT use q.size() here, it is changeful in for loop
                cur = q.front();
                q.pop();
                if (cur != NULL) {
                    level.push_back(cur->val);
                    q.push(cur->left);
                    q.push(cur->right);
                }
            }
            
            if (level.size() > 0) {
                ans.push_back(level);
            }
        }
        
        return ans;
    }
};
