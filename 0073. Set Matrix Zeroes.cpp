class Solution {
  public:
    void setZeroes(vector<vector<int>> &matrix) {
        // maps to flag which row/col
        unordered_map<int, int> row;
        unordered_map<int, int> col;

        // loop through and flag
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        // iterate through each map, set row/col to zero
        for (auto i : row)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[i.first][j] = 0;
        for (auto i : col)
            for (int j = 0; j < matrix.size(); j++)
                matrix[j][i.first] = 0;
    }
};