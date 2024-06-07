
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeHelper(p, q);
    }

    bool isSameTreeHelper(TreeNode* pCurr, TreeNode* qCurr){

        if (pCurr == nullptr && qCurr == nullptr){
            return true;
        }
        if ((pCurr == nullptr && qCurr != nullptr) || (qCurr == nullptr && pCurr != nullptr)){
            return false;
        }
        if (pCurr->val != qCurr->val){
            return false;
        }
        else{
            return isSameTreeHelper(pCurr->left, qCurr->left) && isSameTreeHelper(pCurr->right, qCurr->right);
        }
    }
};