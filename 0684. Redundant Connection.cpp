class Solution {
  public:
    // vars
    int n, set1, set2;
    vector<int> parent;

    // find parent/set (with path compression)
    int find(int x) {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return parent[x];
    }

    // union
    void Union(int x, int y) {
        parent[x] = y;
    }

    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        // init
        n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i < n + 1; i++)
            parent[i] = i;

        // loop through
        for (vector<int> E : edges) {
            // find the two groups
            set1 = find(E[0]);
            set2 = find(E[1]);

            // if already connected (meaning it'll be cyclic) then return
            if (set1 == set2)
                return E;

            // otherwise union
            Union(set1, set2);
        }
        return {};
    }
};