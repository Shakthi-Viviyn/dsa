
// Definition for a binary tree node.
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
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root->val == val){
            return root;
        }

        if (root->left != nullptr){
            TreeNode* leftBranch = searchBST(root->left, val);
            if (leftBranch != nullptr){
                return leftBranch;
            }
        }

        if (root->right != nullptr){
            TreeNode* rightBranch = searchBST(root->right,val);
            if (rightBranch != nullptr){
                return rightBranch;
            }
        }
        
        return nullptr;
    }
};