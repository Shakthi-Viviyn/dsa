
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        
        // Count the number of nodes in linked list
        ListNode* curr = head;
        int count = 0;
        while(curr != nullptr){
            count++;
            curr = curr->next;
        }

        // Find the node before the mid Node
        int midIndex = count / 2;
        curr = head;
        while(midIndex > 1){
            midIndex--;
            curr = curr->next;
        }

        // 1 Node in Linked List is special case handle it separately
        if (count == 1){
            delete(head);
            return nullptr;
        }else{
            // Delete the mid Node & point the node before the mid Node to next Node
            ListNode* nodeToDel = curr->next;
            curr->next = nodeToDel->next;
            delete(nodeToDel);
            return head;
        }
    }
};