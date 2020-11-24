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
    int minDepth(TreeNode *root) {
        // edge
        if (root == NULL)
            return 0;

        // otherwise BFS through
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1, size;
        TreeNode *temp;

        while (!q.empty()) {
            // loop through each layer only
            size = q.size();
            while (size) {
                // first leaf guarantee to be smallest
                if (q.front()->left == NULL && q.front()->right == NULL)
                    return depth;
                // otherwise add children
                if (q.front()->left != NULL)
                    q.push(q.front()->left);
                if (q.front()->right != NULL)
                    q.push(q.front()->right);
                q.pop();
                size--;
            }
            depth++;
        }
        return -1;
    }
};