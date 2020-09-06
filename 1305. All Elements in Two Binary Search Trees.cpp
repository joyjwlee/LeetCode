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
    void addToVec(TreeNode *node, vector<int> &v) {
        // use stack to iterate and add to vector
        stack<TreeNode *> s;
        s.push(node);

        // iterate
        while (!s.empty()) {
            // get current, remove
            TreeNode *curr = s.top();
            s.pop();
            // if null
            if (curr == NULL)
                continue;
            // otherwise, get val and add to stack
            v.push_back(curr->val);
            s.push(curr->left);
            s.push(curr->right);
        }
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        // store all numbers into a vector
        vector<int> v;

        // add 1 and 2
        addToVec(root1, v);
        addToVec(root2, v);

        // sort and return
        sort(v.begin(), v.end());
        return v;
    }
};