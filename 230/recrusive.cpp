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
    void inorderTraversal(TreeNode* node, int& count, int k, int& val) {
        if (node == NULL)
            return ;
        
        if (count > k)
            return ;
        
        inorderTraversal(node->left, count, k, val);
        if (count == k)
            val = node->val;
        
        count++;
        inorderTraversal(node->right, count, k, val);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 1, val;
        
        inorderTraversal(root, count, k, val);
        
        return val;
    }
};
