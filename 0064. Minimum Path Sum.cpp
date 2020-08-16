class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        // init horiz
        for (int i = 1; i < grid[0].size(); i++)
            grid[0][i] += grid[0][i - 1];
        // init vert
        for (int i = 1; i < grid.size(); i++)
            grid[i][0] += grid[i - 1][0];
        // dp
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                grid[i][j] += (grid[i - 1][j] < grid[i][j - 1]) ? grid[i - 1][j] : grid[i][j - 1];
            }
        }
        return grid[grid.size() - 1][grid[grid.size() - 1].size() - 1];
    }
};