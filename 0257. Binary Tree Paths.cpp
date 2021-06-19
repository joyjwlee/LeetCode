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
    // init
    vector<string> ans;

    // dfs
    void dfs(TreeNode *root, string s) {
        // edge
        if (root->left == NULL && root->right == NULL) {
            s += "->" + to_string(root->val);
            ans.push_back(s.substr(2));
            return;
        }
        // left and right
        if (root->left != NULL)
            dfs(root->left, s + "->" + to_string(root->val));
        if (root->right != NULL)
            dfs(root->right, s + "->" + to_string(root->val));
    }

    vector<string> binaryTreePaths(TreeNode *root) {
        dfs(root, "");
        return ans;
    }
};