class Solution {
  public:
    // dr dc arrays
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // check for boundary AND 1
    bool shouldVisit(vector<vector<char>> &grid, int i, int j) {
        if (0 <= i && i < grid.size())
            if (0 <= j && j < grid[0].size())
                if (grid[i][j] == '1')
                    return true;
        return false;
    }

    // DFS
    void DFS(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = 0;
        for (int k = 0; k < 4; k++) {
            if (shouldVisit(grid, i + dr[k], j + dc[k]))
                DFS(grid, i + dr[k], j + dc[k]);
        }
    }

    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        // loop through
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // if we come across island
                if (grid[i][j] == '1') {
                    // increase answer and DFS
                    ans++;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
};