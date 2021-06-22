class Solution {
  public:
    // vars
    int n, m, ans;
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {-1, 0, 1, 0};

    // dfs
    int dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int r, int c) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid2[r][c] == 0)
            return 1;
        grid2[r][c] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++)
            res &= dfs(grid1, grid2, r + dr[i], c + dc[i]);
        return res &= grid1[r][c];
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
        // init
        n = grid1.size(), m = grid1[0].size(), ans = 0;

        // loop through and return answer
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid2[i][j] == 1)
                    ans += dfs(grid1, grid2, i, j);
        return ans;
    }
};