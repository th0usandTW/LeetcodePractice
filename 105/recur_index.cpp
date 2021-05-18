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
    int findRootIdx(vector<int>& inorder, int val) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }
    
    TreeNode* buildTreeRecur(vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx) {
        if (left > right)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[idx++]);
        int rootIdx = findRootIdx(inorder, root->val);
        
        root->left  = buildTreeRecur(preorder, inorder, left, rootIdx - 1, idx);
        root->right = buildTreeRecur(preorder, inorder, rootIdx + 1, right, idx);
        
        return root;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return buildTreeRecur(preorder, inorder, 0, preorder.size()-1, idx);
    }
};
