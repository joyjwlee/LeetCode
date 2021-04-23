class Solution {
  public:
    int jump(vector<int> &nums) {
        // init
        vector<int> dp(nums.size(), 0x3f3f3f3f);
        dp[0] = 0;

        // loop through
        for (int i = 0; i < dp.size(); i++)
            for (int j = 1; j <= nums[i] && i + j < dp.size(); j++)
                dp[i + j] = min(dp[i + j], dp[i] + 1);
        return dp[dp.size() - 1];
    }
};