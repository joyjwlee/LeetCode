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
    // global (to save mem)
    int ans = 0;
    int l, r;

    // dfs helper method
    void dfs(TreeNode *node) {
        // end case
        if (node == NULL)
            return;
        // add if in range
        if (l <= node->val && node->val <= r)
            ans += node->val;
        // recur left and right
        dfs(node->left);
        dfs(node->right);
    }

    int rangeSumBST(TreeNode *root, int L, int R) {
        l = L, r = R;
        dfs(root);
        return ans;
    }
};