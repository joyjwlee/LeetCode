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
    vector<vector<int>> levelOrder(TreeNode *root) {
        // answer, set up queue
        vector<vector<int>> ans;

        // edge case
        if (root == NULL)
            return ans;

        // BFS through for each level
        queue<TreeNode *> q;
        q.push(root);
        int n;
        TreeNode *temp;
        while (!q.empty()) {
            // get the size of that level, create a vector
            n = q.size();
            vector<int> level;

            // loop through the n nodes
            for (int i = 0; i < n; i++) {
                // add val to level vector
                level.push_back(q.front()->val);
                // add children if not null
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                // pop once done
                q.pop();
            }

            // done loop, add on
            ans.push_back(level);
        }
        return ans;
    }
};