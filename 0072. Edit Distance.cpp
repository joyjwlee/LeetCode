class Solution {
  public:
    int minDistance(string word1, string word2) {
        // add char at beginning for null
        word1.insert(0, "."), word2.insert(0, ".");

        // init dp table
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            dp[i][0] = i;
        for (int i = 0; i < m; i++)
            dp[0][i] = i;

        // dp through and return
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int a = dp[i][j - 1], b = dp[i - 1][j - 1], c = dp[i - 1][j];
                // if same
                if (word1[i] == word2[j])
                    dp[i][j] = b;
                // otherwise take min and add one
                else if (a <= b && a <= c)
                    dp[i][j] = a + 1;
                else if (b <= a && b <= c)
                    dp[i][j] = b + 1;
                else
                    dp[i][j] = c + 1;
            }
        }
        return dp[n - 1][m - 1];
    }
};