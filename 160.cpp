class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA;
        ListNode *curB = headB;
        ListNode *ans = new ListNode(-1);
        vector<ListNode*> a;
        vector<ListNode*> b;
        
        
        if (!headA || !headB)
            return NULL;
        
        while (curA)
        {
            a.push_back(curA);
            curA = curA->next;
        }
        
        while (curB)
        {
            b.push_back(curB);
            curB = curB->next;
        }
        
        while (!a.empty() && !b.empty())
        {
            if (a.back() == b.back())
            {
                ans = a.back();
                a.pop_back();
                b.pop_back();
            }
            else
                break;
        }
        
        if (ans->val == -1)
            return NULL;
        else
            return ans;
    }
};
