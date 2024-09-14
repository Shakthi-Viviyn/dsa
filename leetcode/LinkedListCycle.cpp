#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        if (head == nullptr){
            return false;
        }
        
        unordered_set<ListNode*> s;
        while(head->next != nullptr){
            if (s.find(head) != s.end()){
                return true;
            }
            s.insert(head);
            head = head->next;
        }
        return false;
        
    }
};