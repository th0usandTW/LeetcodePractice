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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        while (root != NULL || !stk.empty()) {
            while (root != NULL) {
                stk.push(root);
                root = root->left;
            }
            
            TreeNode* tmp = stk.top();
            stk.pop();
            ans.push_back(tmp->val);
            root = tmp->right;
        }
        
        
        return ans;
    }
};
