class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        // edge
        if (nums.size() == 0)
            return 0;

        // init
        vector<int> dp;
        dp.assign(nums.size(), 0);
        dp[0] = 1;

        // O(n^2) dp
        int max = 0;
        for (int i = 1; i < nums.size(); i++) {
            max = 0;
            for (int j = 0; j < i; j++)
                if (dp[j] > max && nums[j] < nums[i])
                    max = dp[j];
            dp[i] = max + 1;
        }

        // loop through and find max
        max = -1;
        for (int n : dp)
            if (n > max)
                max = n;
        return max;
    }
};