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
    // from 104
    int maxDepth(TreeNode *root) {
        return (root == NULL) ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    bool isBalanced(TreeNode *root) {
        // edge
        if (root == NULL)
            return true;
        return (isBalanced(root->left) && isBalanced(root->right) && abs(maxDepth(root->left) - maxDepth(root->right)) <= 1);
    }
};