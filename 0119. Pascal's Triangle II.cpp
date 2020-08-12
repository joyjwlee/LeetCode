class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        // modified from 118
        vector<vector<int>> ans(rowIndex + 1);
        // make vector shape
        for (int i = 0; i < rowIndex + 1; i++) {
            vector<int> row(i + 1);
            ans[i] = row;
        }
        // populate vector
        for (int i = 0; i < rowIndex + 1; i++) {
            // set first as 1
            ans[i][0] = 1;
            // get values in between
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
            // set last as 1
            ans[i][i] = 1;
        }
        return ans[rowIndex];
    }
};