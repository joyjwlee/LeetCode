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
    TreeNode *bstToGst(TreeNode *root) {
        // same as 538. Convert BST to Greater Tree
        // make stack, create copy of root
        stack<TreeNode *> stk;
        TreeNode *node = root;
        int sum = 0;

        // iterate through and return
        while (!stk.empty() || node != NULL) {
            if (node != NULL) {
                stk.push(node);
                node = node->right;
            } else {
                node = stk.top();
                stk.pop();
                sum += node->val;
                node->val = sum;
                node = node->left;
            }
        }
        return root;
    }
};