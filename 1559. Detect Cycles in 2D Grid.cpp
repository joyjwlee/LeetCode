class Solution {
  public:
    // dr dc
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // vars
    int m, n;
    vector<vector<bool>> vis;

    // dfs
    bool dfs(vector<vector<char>> &grid, int r, int c, char ch, int prevR, int prevC) {
        // mark as visited
        vis[r][c] = true;

        // loop through neighbors
        int nextR, nextC;
        for (int i = 0; i < 4; i++) {
            nextR = r + dr[i];
            nextC = c + dc[i];
            // if in bounds and connected
            if (0 <= nextR && nextR < m && 0 <= nextC && nextC < n && grid[nextR][nextC] == ch) {
                // if not visited then dfs
                if (!vis[nextR][nextC]) {
                    if (dfs(grid, nextR, nextC, ch, r, c))
                        return true;
                }
                // if visited and not same as parent
                else if ((prevR != nextR) || (prevC != nextC))
                    return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>> &grid) {
        // init
        m = grid.size(), n = grid[0].size();
        vis.resize(m, vector<bool>(n));

        // loop through and return
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                // if not visited yet
                if (!vis[i][j])
                    if (dfs(grid, i, j, grid[i][j], -1, -1))
                        return true;
        return false;
    }
};