class Solution {
  public:
    int uniquePaths(int m, int n) {
        // dp, set to 0
        int dp[m][n];
        memset(dp, 0, sizeof dp);
        // init
        dp[0][0]--;
        for (int i = 0; i < m; i++)
            dp[i][0]++;
        for (int i = 0; i < n; i++)
            dp[0][i]++;
        // do the dp
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] += (dp[i][j - 1] + dp[i - 1][j]);
            }
        }
        return dp[m - 1][n - 1];
    }
};