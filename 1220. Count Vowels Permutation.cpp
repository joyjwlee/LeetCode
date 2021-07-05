class Solution {
  public:
    int countVowelPermutation(int n) {
        // init
        const int MOD = 1e9 + 7;
        long dp[n][5];
        for (int i = 0; i < 5; i++)
            dp[0][i] = 1;

        // dp through
        for (int i = 1; i < n; i++) {
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][4]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
            dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % MOD;
            dp[i][3] = dp[i - 1][2];
            dp[i][4] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        }

        // sum and return
        int ans = 0;
        for (int i = 0; i < 5; i++) {
            ans += dp[n - 1][i];
            ans %= MOD;
        }
        return ans;
    }
};