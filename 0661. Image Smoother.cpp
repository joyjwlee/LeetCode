class Solution {
  public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        // init
        int n = M.size(), m = M[0].size();
        int numNeighbors, sum;
        vector<vector<int>> ans(n, vector<int>(m, 0));

        // loop through all
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // loop through all neighbors
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        // if not self and neighbor is also condition
                        if ((k != i || l != j) && condition) {
                            // increment counter
                        }
                    }
                }
            }
        }
    }

    return ans;
};