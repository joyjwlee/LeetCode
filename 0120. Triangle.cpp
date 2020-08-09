class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        // dp bottom up
        for (int i = triangle.size() - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                // min of bottom or bottom right
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};