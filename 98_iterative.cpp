class Solution {
public:
    bool isValidBST(TreeNode* root) {
        long preVal = LONG_MIN;
        stack<TreeNode*> stk;
        
        while (root || !stk.empty())
        {
            while (root)
            {
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            
            if (root->val <= preVal)
                return false;
            
            preVal = root->val;
            root = root->right;
        }
        
        return true;
    }
};
