class Solution {
  public:
    int surfaceArea(vector<vector<int>> &grid) {
        // add zero padding to left and right
        for (int i = 0; i < grid.size(); i++) {
            grid[i].insert(grid[i].begin(), 0); // left
            grid[i].push_back(0);               // right
        }
        // add zero padding to top and bottom
        vector<int> zeroes(grid[0].size(), 0); // zeroes
        grid.insert(grid.begin(), zeroes);     // top
        grid.push_back(zeroes);                // bottom

        // loop through all, find answer, and return
        int ans = 0;
        for (int i = 1; i < grid.size() - 1; i++) {
            for (int j = 1; j < grid[i].size() - 1; j++) {
                // if block actually exists
                if (grid[i][j] != 0) {
                    // calculate sides
                    ans += max(grid[i][j] - grid[i - 1][j], 0);
                    ans += max(grid[i][j] - grid[i + 1][j], 0);
                    ans += max(grid[i][j] - grid[i][j - 1], 0);
                    ans += max(grid[i][j] - grid[i][j + 1], 0);
                    ans += 2; // top and bottom guaranteed
                }
            }
        }
        return ans;
    }
};