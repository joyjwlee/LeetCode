class Solution {
  public:
    int findLength(vector<int> &A, vector<int> &B) {
        int max = 0;
        // longest common sub; dp
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        return max;
    }
};