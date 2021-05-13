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
    void traversal(vector<int>& val, TreeNode* node) {
        if (node == NULL)
            return;
        
        traversal(val, node->left);
        val.push_back(node->val);
        traversal(val, node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> val;
        int min_diff = INT_MAX;
        
        // Record all nodes
        traversal(val, root);
        
        for (int i = 0; i < val.size() - 1; i++) {
            min_diff = min(min_diff, abs(val[i]-val[i+1]));
        }
        
        return min_diff;
    }
};
