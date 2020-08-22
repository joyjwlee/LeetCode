class Solution {
  public:
    string longestPalindrome(string s) {
        // COPIED FROM 0647 --> instead of ans++, update longest and LR
        // edge
        int n = s.size();
        if (n == 0 || n == 1)
            return s;

        // dp --> row: starting idx, col: ending idx --> of substring
        // true if palindrome; init diagonal
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;

        // loop through all other substrings by column
        // start with column at index 1 and ignore bottom half
        int longest = 0, left = 0, right = 0;
        for (int col = 1; col < n; col++) {
            for (int row = 0; row < col; row++) {
                // palin size 2
                if (row + 1 == col && s[col] == s[row]) {
                    dp[row][col] = true;
                    // longer? update
                    if (col - row > longest)
                        longest = col - row, left = row, right = col;
                }
                // check outer 2 char and inner substring
                else if (dp[row + 1][col - 1] && s[col] == s[row]) {
                    dp[row][col] = true;
                    // longer? update
                    if (col - row > longest)
                        longest = col - row, left = row, right = col;
                }
            }
        }

        // concatenate and return
        string ans = "";
        for (int i = left; i <= right; i++)
            ans += s[i];
        return ans;
    }
};