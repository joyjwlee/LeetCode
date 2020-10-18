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
    bool hasPathSum(TreeNode *root, int sum) {
        // doesn't work
        if (root == NULL)
            return false;
        // reaches sum
        sum -= root->val;
        if (sum == 0 && root->left == NULL && root->right == NULL)
            return true;
        // otherwise return or of below
        return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};