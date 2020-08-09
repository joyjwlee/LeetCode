class Solution {
  public:
    int climbStairs(int n) {
        // edge cases
        if (n == 0 || n == 1)
            return 1;

        // dp through
        int dp[n];
        dp[0] = 1, dp[1] = 2;
        for (int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};