class Solution {
  public:
    int fib(int N) {
        // can do dp, just do for loop
        if (N == 0 || N == 1)
            return N;
        // dp through
        int dp[N];
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i < N; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[N - 1];
    }
};