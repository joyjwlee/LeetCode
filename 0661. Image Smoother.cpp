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
                // reset vals
                numNeighbors = 0, sum = 0;
                // loop through all neighbors
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        // if in bounds
                        if (0 <= k && k < n && 0 <= l && l < m) {
                            numNeighbors++;
                            sum += M[k][l];
                        }
                    }
                }
                ans[i][j] = sum / numNeighbors;
            }
        }

        // return
        return ans;
    }
};