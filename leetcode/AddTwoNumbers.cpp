#include <iostream>
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

        ListNode* head = nullptr;
        ListNode* curr = head;
        ListNode* currL1 = l1;
        ListNode* currL2 = l2;
        int currDigit = 0;
        int carryDigit = 0;
        int sum = 0;

        while(currL1 != nullptr && currL2 != nullptr){

            sum = currL1->val + currL2->val + carryDigit;
            currDigit = sum % 10;
            carryDigit = (sum - currDigit) / 10;

            if (head == nullptr){
                head = new ListNode(currDigit);
                curr = head;
            }else{
                curr->next = new ListNode(currDigit);
                curr = curr->next;
            }

            currL1 = currL1->next;
            currL2 = currL2->next;
        }

        while(currL1 != nullptr){

            sum = currL1->val + carryDigit;
            currDigit = sum % 10;
            carryDigit = (sum - currDigit) / 10;

            curr->next = new ListNode(currDigit);
            curr = curr->next;
            currL1 = currL1->next;
        }

        while(currL2 != nullptr){

            sum = currL2->val + carryDigit;
            currDigit = sum % 10;
            carryDigit = (sum - currDigit) / 10;

            curr->next = new ListNode(currDigit);
            curr = curr->next;
            currL2 = currL2->next;
        }

        if (carryDigit != 0){
            curr->next = new ListNode(carryDigit);
        }
        
        return head;
    }
};
