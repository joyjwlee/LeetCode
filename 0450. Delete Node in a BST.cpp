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
    // helper function to find min/successor node
    TreeNode *minValNode(TreeNode *node) {
        TreeNode *curr = node;
        // just go as left as poss
        while (curr != NULL && curr->left != NULL)
            curr = curr->left;
        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key) {
        // edge
        if (root == NULL)
            return root;

        // greater, go left
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        // smaller, go right
        else if (key > root->val)
            root->right = deleteNode(root->right, key);

        // otherwise we're where we need to be
        else {
            // only has right, then right takes its place
            if (root->left == NULL)
                return root->right;
            // only has left, then left takes its place
            else if (root->right == NULL)
                return root->left;
            // if node to be deleted has two children
            else {
                // swap it out
                TreeNode *temp = minValNode(root->right);
                root->val = temp->val;
                root->right = deleteNode(root->right, temp->val);
            }
        }

        // just return now
        return root;
    }
};