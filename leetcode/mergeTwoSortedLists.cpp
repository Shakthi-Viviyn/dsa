 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newListHead = nullptr;
        ListNode* newList = nullptr;
        while(list1 != nullptr && list2 != nullptr){
            if (list1->val <= list2->val){
                if (newList == nullptr){
                    newList = new ListNode(list1->val);
                    newListHead = newList;
                }else{
                    newList->next = new ListNode(list1->val);
                    newList = newList->next;
                }
                list1 = list1->next;
            }else{
                if (newList == nullptr){
                    newList = new ListNode(list2->val);
                    newListHead = newList;
                }else{
                    newList->next = new ListNode(list2->val);
                    newList = newList->next;
                }
                list2 = list2->next;
            }
        }
        while(list1 != nullptr){
            if (newList == nullptr){
                newList = new ListNode(list1->val);
                newListHead = newList;
            }else{
                newList->next = new ListNode(list1->val);
                newList = newList->next;
            }
            list1 = list1->next;
        }
        while(list2 != nullptr){
            if (newList == nullptr){
                newList = new ListNode(list2->val);
                newListHead = newList;
            }else{
                newList->next = new ListNode(list2->val);
                newList = newList->next;
            }
            list2 = list2->next;
        }
        return newListHead;
    }
};