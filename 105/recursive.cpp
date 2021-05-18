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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int root_num;
        vector<int> left_preorder;
        vector<int> right_preorder;
        vector<int> left_inorder;
        vector<int> right_inorder;
        bool find_root = false;
        
        // find root
        if (preorder.size() > 0) {
            root = new TreeNode(preorder[0]);
            root_num = preorder[0];
        } else
            return NULL;
            
        // Devide inorder into left and right part 
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root_num) {
                find_root = true;
                continue;
            }
            if (find_root)
                right_inorder.push_back(inorder[i]);
            else
                left_inorder.push_back(inorder[i]);
        }
        
        // Devide preorder into left and right part 
        for (int j = 1; j < preorder.size(); j++) {
            if (left_preorder.size() < left_inorder.size())
                left_preorder.push_back(preorder[j]);
            else
                right_preorder.push_back(preorder[j]);
        }
        
        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        
        return root;
    }
};
