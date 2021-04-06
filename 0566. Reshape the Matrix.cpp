class Solution {
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        // init
        int n = nums.size(), m = nums[0].size();
        int p = 0, q = 0;
        vector<vector<int>> ans(r, vector<int>(c));

        // check size
        if (n * m != r * c)
            return nums;

        // reshape and return
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[p][q] = nums[i][j];
                q++;
                if (q == c) {
                    q = 0;
                    p++;
                }
            }
        }
        return ans;
    }
};