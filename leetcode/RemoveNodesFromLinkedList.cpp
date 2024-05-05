struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);

        ListNode** curr = &head;
        while((*curr)->next != nullptr){
            if ((*curr)->next->val >= (*curr)->val){
                curr = &((*curr)->next);
            }else if((*curr)->next->val < (*curr)->val){
                (*curr)->next = (*curr)->next->next;
            }
        }
        head = reverseList(head);
        return head;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr != nullptr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};