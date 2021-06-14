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
    // helper
    int dfs(TreeNode *root, int sum) {
        // base case(s)
        if (root == NULL) // null
            return 0;
        int curr = sum * 10 + root->val;
        if (root->left == NULL && root->right == NULL) // leaf
            return curr;
        return dfs(root->left, curr) + dfs(root->right, curr);
    }

    int sumNumbers(TreeNode *root) {
        return dfs(root, 0);
    }
};