/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        stack<Node*> s;
        Node* dummy = new Node(0);
        Node* cur = NULL;
        Node* pre = dummy;
        
        s.push(head);
        while (!s.empty()) {
            cur = s.top();
            s.pop();
            
            while (cur != NULL) {
                pre->next = cur;
                cur->prev = pre;
                if (cur->child) {
                    s.push(cur->next);    
                    cur->next = cur->child;
                    cur->child = NULL;
                }
                pre = cur;
                cur = cur->next;
            }
        }
        dummy->next->prev = NULL; // Need to set head's prev as NULL
        return dummy->next;
    }
};
