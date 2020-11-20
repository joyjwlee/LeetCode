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
    vector<double> averageOfLevels(TreeNode *root) {
        // BFS set up
        queue<TreeNode *> q;
        q.push(root);

        // variables
        vector<double> ans;
        int size;
        double sum;

        // BFS and return
        while (!q.empty()) {
            // reset vals
            size = q.size();
            sum = 0;
            // loop through all at the level
            for (int i = 0; i < size; i++) {
                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);
                sum += q.front()->val;
                q.pop();
            }
            // add to vector
            ans.push_back(sum / size);
        }
        return ans;
    }
};