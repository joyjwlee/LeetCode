class Solution {
  public:
    int countSubstrings(string s) {
        // edge
        int n = s.size();
        if (n == 0 || n == 1)
            return n;

        // dp --> row: starting idx, col: ending idx --> of substring
        // true if palindrome; init diagonal
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // loop through all other substrings by column
        // start with column at index 1 and ignore bottom half
        int ans = n;
        for (int col = 1; col < n; col++) {
            for (int row = 0; row < col; row++) {
                // palin size 2
                if (row + 1 == col && s[col] == s[row]) {
                    dp[row][col] = true;
                    ans++;
                }
                // check outer 2 char and inner substring
                else if (dp[row + 1][col - 1] && s[col] == s[row]) {
                    dp[row][col] = true;
                    ans++;
                }
            }
        }
        // bottom left is inner substring
        return ans;
    }
};