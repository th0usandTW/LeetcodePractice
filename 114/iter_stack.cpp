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
    void flatten(TreeNode* root) {
        stack<TreeNode*> stack;
        TreeNode* node;
        TreeNode* cur = root;
        
        if (root == NULL)
            return;
        
        stack.push(root);
        
        while (!stack.empty()) {
            node = stack.top();
            stack.pop();
            
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
            
            if (!stack.empty())
                node->right = stack.top();
            node->left = NULL;
        }
        
    }
};
