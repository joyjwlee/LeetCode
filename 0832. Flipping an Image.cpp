class Solution {
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
        // variables
        int n = image.size(), m = image[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        // copy over, invert, and flip simultaneously
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = 1 - image[i][m - j - 1];
        return ans;
    }
};