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
    vector<int> inorderTraversal(TreeNode *root) {
        // stack to keep track of where we are, vector for answer
        stack<TreeNode *> branch;
        vector<int> ans;

        // iterate in order
        while (root != NULL || !branch.empty()) {
            // go as left as possible
            if (root != NULL) {
                branch.push(root);
                root = root->left;
                continue; // come back later
            }
            root = branch.top();
            branch.pop();
            // add value, go right
            ans.push_back(root->val);
            root = root->right;
        }

        return ans;
    }
};