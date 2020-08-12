class Solution {
  public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        // make vector shape
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1);
            ans[i] = row;
        }
        // populate vector
        for (int i = 0; i < numRows; i++) {
            // set first as 1
            ans[i][0] = 1;
            // get values in between
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            // set last as 1
            ans[i][i] = 1;
        }
        return ans;
    }
};