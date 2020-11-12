class Solution {
  public:
    void rotate(vector<vector<int>> &matrix) {
        // in-place 90 degree rotation clockwise
        int n = matrix.size();

        // rotation can be achieved by flipping along main diag
        for (int i = 0; i < n; i++)
            for (int j = i; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // and then flipping left-right
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++)
                swap(matrix[i][j], matrix[i][n - j - 1]);
    }
};