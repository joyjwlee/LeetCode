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
    int deepestLeavesSum(TreeNode *root) {
        int ans = 0, size;
        queue<TreeNode *> q;
        TreeNode *curr;
        q.push(root);

        while (!q.empty()) {
            ans = 0;
            size = q.size();
            for (int i = 0; i < size; i++) {
                curr = q.front();
                q.pop();
                ans += curr->val;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
        }
        return ans;
    }
};