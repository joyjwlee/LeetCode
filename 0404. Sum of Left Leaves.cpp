/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        // if at null
        if (root == nullptr)
            return 0;
        // left child is leaf
        else if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            return root->left->val + sumOfLeftLeaves(root->right);
        // otherwise return both subtrees
        else
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};