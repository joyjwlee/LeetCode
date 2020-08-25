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
    // helper method
    bool isSame(TreeNode *n1, TreeNode *n2) {
        // if both aren't null and values are same
        if (n1 && n2 && n1->val == n2->val)
            return isSame(n1->left, n2->right) && isSame(n1->right, n2->left);
        // if we at the bottom, check for same
        return n1 == n2;
    }

    bool isSymmetric(TreeNode *root) {
        // edge
        if (!root)
            return true;
        return isSame(root->left, root->right);
    }
};