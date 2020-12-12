class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL)
            return NULL;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        if (leftDepth == rightDepth)
            return root;
        else if (leftDepth > rightDepth)
            return lcaDeepestLeaves(root->left);
        else
            return lcaDeepestLeaves(root->right);
    }
private:
    int getDepth(TreeNode* node) {
        if (node == NULL)
            return 0;
        
        return 1 + max(getDepth(node->left), getDepth(node->right));
    }
};
