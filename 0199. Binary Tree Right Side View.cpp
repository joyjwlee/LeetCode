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
    vector<int> rightSideView(TreeNode *root) {
        // init
        vector<int> ans;
        queue<TreeNode *> q;
        if (root != NULL)
            q.push(root);

        // BFS through
        while (!q.empty()) {
            // add rightmost
            ans.push_back(q.back()->val);
            // add next level
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // extract current
                TreeNode *curr = q.front();
                q.pop();
                // left
                if (curr->left != NULL)
                    q.push(curr->left);
                // right
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return ans;
    }
};