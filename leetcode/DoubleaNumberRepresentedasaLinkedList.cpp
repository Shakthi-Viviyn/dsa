
// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 #include <stack>
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {

        std::stack<int> s;
        ListNode* curr = head;
        while(curr != nullptr){
            s.push(curr->val);
            curr = curr->next;
        }

        ListNode* currNode = nullptr;
        int carry = 0;
        while(!s.empty()){
            int digit = s.top() * 2;
            digit += carry;
            s.pop();
            carry = 0;
            if (digit > 9){
                carry = digit / 10;
                digit = digit % 10;
            }
            currNode = new ListNode(digit, currNode);
        }
        if (carry > 0){
            currNode = new ListNode(carry, currNode);
        }
        return currNode;

    }
};