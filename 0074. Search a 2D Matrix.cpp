class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // edge
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;

        // start from top right, staircase through
        int i = 0, j = n - 1;
        while (i < m && 0 <= j) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }
        return false;
    }
};