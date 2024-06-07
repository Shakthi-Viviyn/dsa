

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
    int maxDepth(TreeNode* root) {
        return findMaxDepth(root, 0);
    }

    int findMaxDepth(TreeNode* curr, int depth){
        if (curr == nullptr){
            return depth;
        }else{
            int leftDepth = findMaxDepth(curr->left, depth + 1);
            int rightDepth = findMaxDepth(curr->right, depth + 1);

            if (leftDepth > rightDepth){
                return leftDepth;
            }else{
                return rightDepth;
            }
        }
    }
};