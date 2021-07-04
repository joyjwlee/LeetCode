class Solution {
  public:
    // vars
    int ans, m, n, psum, colSum;

    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        // init
        ans = INT_MIN, m = matrix.size(), n = matrix[0].size();

        // get psum (by row)
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                matrix[i][j] += matrix[i][j - 1];

        // loop through all widths
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // psum and set for psums
                set<int> s = {0};
                psum = 0;
                // loop through all heights
                for (int l = 0; l < m; l++) {
                    // get sum of column (collapse to 1D)
                    colSum = (i > 0) ? matrix[l][j] - matrix[l][i - 1] : matrix[l][j];
                    psum += colSum;
                    // search in set, update ans
                    auto itr = s.lower_bound(psum - k);
                    if (itr != s.end())
                        ans = max(ans, psum - *itr);
                    // insert to set
                    s.insert(psum);
                }
            }
        }
        return ans;
    }
};