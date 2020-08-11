class Solution {
  public:
    // dr dc arrays
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // DFS helper function
    int DFS(vector<vector<int>> &grid, int r, int c) {
        // mark visited
        grid[r][c] = 0;
        // find area via neighbors
        int area = 1;
        for (int i = 0; i < 4; i++) {
            // if in bounds
            if (0 <= r + dr[i] && r + dr[i] < grid.size())
                if (0 <= c + dc[i] && c + dc[i] < grid[0].size())
                    // if not visited yet
                    if (grid[r + dr[i]][c + dc[i]] == 1)
                        area += DFS(grid, r + dr[i], c + dc[i]);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int ans = 0, size = 0;

        // loop through
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // if part of island
                if (grid[i][j]) {
                    // reset size, find size
                    size = DFS(grid, i, j);
                    // update ans
                    if (size > ans)
                        ans = size;
                }
            }
        }
        return ans;
    }
};