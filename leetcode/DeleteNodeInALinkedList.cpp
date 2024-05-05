

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode** curr = &node;
        while((*curr)->next != nullptr){
            (*curr)->val = (*curr)->next->val;
            curr = &((*curr)->next);
        }
        (*curr) = nullptr;
    }
};