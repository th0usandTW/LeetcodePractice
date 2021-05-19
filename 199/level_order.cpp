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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* cur;
        vector<int> ans;
        
        if (root == NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            int val;
            for (int i = 0; i < size; i++) {
                cur = q.front();
                q.pop();
                
                val = cur->val; // We only want the last number in this level
                if (cur->left != NULL)
                    q.push(cur->left);
                if (cur->right != NULL)
                    q.push(cur->right);
            }
            ans.push_back(val);
        }
        
        return ans;
    }
};
