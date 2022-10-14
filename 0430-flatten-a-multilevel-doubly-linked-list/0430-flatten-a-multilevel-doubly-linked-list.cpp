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
        stack<Node *> stk;
        Node *ptr = head;
        while (ptr) {
            if (ptr->child) {
                if (ptr->next) {
                    stk.push(ptr->next);
                }
                ptr->next = ptr->child;
                ptr->child = nullptr;
                ptr->next->prev = ptr;
            }
            if (!ptr->next && !stk.empty()) {
                ptr->next = stk.top();
                stk.pop();
                ptr->next->prev = ptr;
            }
            ptr = ptr->next;
        }
        return head;
    }
};