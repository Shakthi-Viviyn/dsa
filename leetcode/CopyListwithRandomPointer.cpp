#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> oldToNew;

        Node* oldCurr = head;
        Node* newHead = new Node(head->val);
        Node* newCurr = newHead;
        oldToNew[oldCurr] = newCurr;
        
        while (oldCurr->next != nullptr) {
            newCurr->next = new Node(oldCurr->next->val);
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
            oldToNew[oldCurr] = newCurr;
        }

        oldCurr = head;
        newCurr = newHead;
        while (oldCurr != nullptr) {
            newCurr->random = oldCurr->random ? oldToNew[oldCurr->random] : nullptr;
            oldCurr = oldCurr->next;
            newCurr = newCurr->next;
        }
        
        return newHead;
    }
};