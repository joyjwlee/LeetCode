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
    vector<int> ans;
    void dfs(TreeNode *node) {
        // end case
        if (node == NULL)
            return;

        // add curr
        ans.push_back(node->val);

        // recur left
        dfs(node->left);

        // recur right
        dfs(node->right);
    }

    vector<int> preorderTraversal(TreeNode *root) {
        dfs(root);
        return ans;
    }
};