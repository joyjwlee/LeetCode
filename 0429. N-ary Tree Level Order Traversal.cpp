/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        // answer, set up queue
        vector<vector<int>> ans;

        // edge case
        if (root == NULL)
            return ans;

        // BFS through for each level
        queue<Node *> q;
        q.push(root);
        int n;
        Node *temp;
        while (!q.empty()) {
            // get the size of that level, create a vector
            n = q.size();
            vector<int> level;

            // loop through the n nodes
            for (int i = 0; i < n; i++) {
                // add val to level vector
                level.push_back(q.front()->val);
                // add children if not null
                for (int j = 0; j < q.front()->children.size(); j++)
                    if (q.front()->children[j] != NULL)
                        q.push(q.front()->children[j]);
                // pop once done
                q.pop();
            }

            // done loop, add on
            ans.push_back(level);
        }
        return ans;
    }
};