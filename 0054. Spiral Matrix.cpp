class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        // edge
        if (matrix.size() == 0)
            return {};

        // create vector for values
        vector<int> ans;
        // create 2D vector for visited
        vector<vector<bool>> v(matrix.size(), vector<bool>(matrix[0].size()));

        // populate vector
        int cnt = 1, i = 0, j = 0;
        while (cnt <= matrix.size() * matrix[0].size()) {
            // right
            while (j < matrix[0].size() && !v[i][j]) {
                v[i][j] = true;
                ans.push_back(matrix[i][j++]);
                cnt++;
            }
            j--;
            i++;
            // down
            while (i < matrix.size() && !v[i][j]) {
                v[i][j] = true;
                ans.push_back(matrix[i++][j]);
                cnt++;
            }
            i--;
            j--;
            // left
            while (j >= 0 && !v[i][j]) {
                v[i][j] = true;
                ans.push_back(matrix[i][j--]);
                cnt++;
            }
            j++;
            i--;
            // up
            while (i >= 0 && !v[i][j]) {
                v[i][j] = true;
                ans.push_back(matrix[i--][j]);
                cnt++;
            }
            i++;
            j++;
        }

        return ans;
    }
};