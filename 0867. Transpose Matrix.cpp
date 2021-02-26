class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();

        // if square stay in upper right, swap with corresponding
        if (n == m) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < m; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
            return matrix;
        }

        // otherwise just solve
        vector<vector<int>> ans;
        vector<int> row;
        for (int i = 0; i < m; i++) {
            row.clear();
            for (int j = 0; j < n; j++)
                row.push_back(matrix[j][i]);
            ans.push_back(row);
        }
        return ans;
    }
};