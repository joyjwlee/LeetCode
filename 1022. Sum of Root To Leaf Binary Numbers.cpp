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
    int ans = 0;

    // utility/helper function
    void sumRootToLeafUtil(TreeNode *node, int num) {
        // if null
        if (node == NULL)
            return;

        // otherwise bitshift by 1, or it with current
        num <<= 1;
        num |= node->val;

        // if we are at a leaf
        if (node->left == NULL && node->right == NULL)
            ans += num;

        // otherwise repeat with children
        sumRootToLeafUtil(node->left, num);
        sumRootToLeafUtil(node->right, num);
    }

    int sumRootToLeaf(TreeNode *root) {
        sumRootToLeafUtil(root, 0);
        return ans;
    }
};