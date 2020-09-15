class Solution {
  public:
    int diagonalSum(vector<vector<int>> &mat) {
        // go through diagonals
        int sum = 0, n = mat.size();
        for (int i = 0; i < n; i++) {
            sum += mat[i][i];
            sum += mat[i][n - i - 1];
        }

        // see if middle overlaps
        return (n % 2 == 0) ? sum : sum - mat[n / 2][n / 2];
    }
};