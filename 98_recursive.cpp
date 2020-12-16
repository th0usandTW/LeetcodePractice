bool isValidBSTRecursive(TreeNode* node, long min, long max) {
        if (!node)
            return true;
        
        // node value exceeds min/max bound
        if (node->val <= min || node->val >= max)
            return false;
        
        return isValidBSTRecursive(node->left, min, node->val) && isValidBSTRecursive(node->right, node->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTRecursive(root, LONG_MIN, LONG_MAX);
    }
