class Solution {
  public:
    // dr dc
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // vars
    int m, n, size, nextR, nextC, ans;
    bool touchesEdge;

    // bfs
    int bfs(vector<vector<int>> &grid, int r, int c) {
        // init bfs
        queue<pair<int, int>> q;
        grid[r][c] = 0;
        q.push(make_pair(r, c));
        size = 1;
        touchesEdge = false;
        if ((r == 0) || (r == m - 1) || (c == 0) || (c == n - 1))
            touchesEdge = true;

        // do bfs
        while (!q.empty()) {
            // get curr
            pair<int, int> curr = q.front();
            q.pop();

            // loop through neighbors
            for (int i = 0; i < 4; i++) {
                nextR = curr.first + dr[i];
                nextC = curr.second + dc[i];
                // if in bounds and part of island (not visited yet)
                if (0 <= nextR && nextR < m && 0 <= nextC && nextC < n && grid[nextR][nextC] == 1) {
                    // if island touches edge
                    if ((nextR == 0) || (nextR == m - 1) || (nextC == 0) || (nextC == n - 1))
                        touchesEdge = true;
                    // otherwise continue with bfs
                    grid[nextR][nextC] = 0;
                    q.push(make_pair(nextR, nextC));
                    size++;
                }
            }
        }
        return touchesEdge ? 0 : size;
    }

    int numEnclaves(vector<vector<int>> &grid) {
        // init
        m = grid.size(), n = grid[0].size();

        // calculate and return
        ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                // if land (mark visited by changing to 0)
                if (grid[i][j] == 1)
                    ans += bfs(grid, i, j);
        return ans;
    }
};