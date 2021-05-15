class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowTail = dummy;
        TreeNode* root;
        
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
            return new TreeNode(head->val);
        
        // To find the mid of list as a parent node
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slowTail = slow;
            slow = slow->next;
        }
        
        root = new TreeNode(slow->val);
        slowTail->next = NULL;   // To make left sub list
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};
