class Solution {
  public:
    int minSideJumps(vector<int> &obstacles) {
        // init for dp
        vector<vector<int>> dp(3, vector<int>(obstacles.size(), 0x3f3f3f3f));
        dp[0][0] = 1;
        dp[1][0] = 0;
        dp[2][0] = 1;
        int smallest;

        // run the dp
        for (int i = 1; i < obstacles.size(); i++) {
            // set vals without rock to the left
            for (int j = 0; j < 3; j++) {
                // skip if rock or previous is a rock
                if (j + 1 == obstacles[i] || dp[j][i - 1] == 0x3f3f3f3f)
                    continue;
                // set value
                dp[j][i] = dp[j][i - 1];
            }
            // find smallest in current column
            smallest = 0x3f3f3f3f;
            for (int j = 0; j < 3; j++)
                smallest = min(smallest, dp[j][i]);
            // set vals with rock to the left
            for (int j = 0; j < 3; j++) {
                // skip if rock
                if (j + 1 == obstacles[i])
                    continue;
                // set value
                if (dp[j][i - 1] == 0x3f3f3f3f)
                    dp[j][i] = smallest + 1;
            }
        }

        // find answer and return
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 3; i++)
            ans = min(ans, dp[i][dp[0].size() - 1]);
        return ans;
    }
};