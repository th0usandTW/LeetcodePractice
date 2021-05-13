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
    void traversal(int& ans, int sum, TreeNode* node) {
        if (node == NULL)
            return ;
        
        sum = sum*10 + node->val;
        
        if (node->left == NULL && node->right == NULL) {
            ans += sum;
            return ;
        }
        traversal(ans, sum, node->left);
        traversal(ans, sum, node->right);
    }
    
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        traversal(ans, 0, root);
        
        return ans;
    }
};
