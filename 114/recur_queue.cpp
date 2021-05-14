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
    void preorder(TreeNode *node) {
        if (node == NULL)
            return ;
        
        q.push(node);
        preorder(node->left);
        preorder(node->right);
    }
    
    void flatten(TreeNode* root) {
        TreeNode *cur;
        
        preorder(root);

        while (!q.empty()) 
        {
            cur = q.front();
            cur->left = NULL;
            q.pop();
            
            if (!q.empty()) 
            {
                cur->right = q.front();
            }
        }
    }
    
private:
    queue<TreeNode *> q;
};
