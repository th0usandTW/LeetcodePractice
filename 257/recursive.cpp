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
    void traversal(vector<string>& ans, TreeNode* node, string str) {
        if ((node->left == NULL) && (node->right == NULL)) {
            ans.push_back(str);
            return ;
        }
        
        if (node->left)
            traversal(ans, node->left, str + "->" + to_string(node->left->val));
        if (node->right)
            traversal(ans, node->right, str + "->" + to_string(node->right->val));
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        if (root == NULL)
            return ans;
        
        traversal(ans, root, to_string(root->val));
        return ans;
    }
};
