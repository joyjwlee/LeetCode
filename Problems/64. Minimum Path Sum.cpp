class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty())
            return 0;
        int row = grid.size() - 1;
        int col = grid[0].empty() ? 0 : grid[0].size() - 1;
        for (int r = row; r >= 0; r--) {
            for (int c = col; c >= 0; c--) {
                if (r == row) {
                    if (c != col)
                        grid[r][c] += grid[r][c + 1];
                } else if (c == col) {
                    if (r != row)
                        grid[r][c] += grid[r + 1][c];
                } else {
                    grid[r][c] += min(grid[r + 1][c], grid[r][c + 1]);
                }
            }
        }
        return grid[0][0];
    }
};