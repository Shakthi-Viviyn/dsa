#include <vector>

using namespace std;

//  Definition for a binary tree node.
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leafSeq1;
        vector<int> leafSeq2;

        findAllLeafNodes(root1, leafSeq1);
        findAllLeafNodes(root2, leafSeq2);
        if (leafSeq1 == leafSeq2){
            return true;
        }else{
            return false;
        }
    }

    void findAllLeafNodes(TreeNode* curr,vector<int>& vec){

        if (curr->left == nullptr && curr->right == nullptr){
            vec.push_back(curr->val);
            return;
        }

        if (curr->left != nullptr){
            findAllLeafNodes(curr->left, vec);
        }
        if (curr->right != nullptr){
            findAllLeafNodes(curr->right, vec);
        }
    }
};