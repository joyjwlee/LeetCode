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
    // recursively traverse, place when at end
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        // null, reach end
        if (root == NULL)
            return new TreeNode(val);
        // go right subtree
        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        // otherwise left subtree
        else
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};