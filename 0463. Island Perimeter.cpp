class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        // dr dc arrays
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        int ans = 0, nbr = 0;
        // loop through each
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // if a block
                if (grid[i][j] == 1) {
                    // count neighbors
                    nbr = 0;
                    for (int k = 0; k < 4; k++) {
                        // if in bounds
                        if (0 <= i + dr[k] && i + dr[k] < grid.size())
                            if (0 <= j + dc[k] && j + dc[k] < grid[0].size())
                                // if exists
                                if (grid[i + dr[k]][j + dc[k]] == 1)
                                    nbr++;
                    }
                    // add to perimeter
                    ans += (4 - nbr);
                }
            }
        }
        return ans;
    }
};