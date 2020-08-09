class Solution {
  public:
    int longestCommonSubsequence(string text1, string text2) {
        int max = 0;
        // dp, set to 0
        int dp[text1.size() + 1][text2.size() + 1];
        memset(dp, 0, sizeof dp);

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                // if same character
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                // otherwise take max
                else
                    dp[i][j] = (dp[i][j - 1] > dp[i - 1][j]) ? dp[i][j - 1] : dp[i - 1][j];
                // update max
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max;
    }
};