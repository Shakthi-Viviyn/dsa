
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int num1 = 0;
        int num2 = 0;
        int mulFactor = 1;
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;

        while(currL1 != nullptr){
            num1 += currL1->val * mulFactor;
            mulFactor *= 10;
            currL1 = currL1->next;
        }

        mulFactor = 1;
        while(currL2 != nullptr){
            num2 += currL2->val * mulFactor;
            mulFactor *= 10;
            currL2 = currL2->next;
        }

        int sum = num1 + num2;

        ListNode* head;

        // handle head case
        int numToAdd = sum % 10;
        sum -= numToAdd;
        sum = sum / 10;
        head = new ListNode(numToAdd);

        ListNode* curr = head;

        //loop through the sum digits and add to list for rest of the nodes
        while (sum > 0){
            numToAdd = sum % 10;
            sum -= numToAdd;
            sum = sum / 10;

            curr->next = new ListNode(numToAdd);
            curr = curr->next;
        }
        
        return head;
    }
};