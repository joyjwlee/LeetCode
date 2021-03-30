class Solution {
  public:
    int binaryGap(int n) {
        // store indices of 1
        vector<int> dp;
        int idx = 0;
        while (n) {
            if (n % 2 == 1)
                dp.push_back(idx);
            n /= 2;
            idx++;
        }

        // edge
        if (dp.size() < 2)
            return false;

        // dp
        int ans = 0;
        for (int i = 1; i < dp.size(); i++)
            if (dp[i] - dp[i - 1] > ans)
                ans = dp[i] - dp[i - 1];
        return ans;
    }
};