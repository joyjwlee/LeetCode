class Solution {
  public:
    // vars
    int m, n, l, r, mid, nextR, nextC;
    vector<vector<bool>> vis;

    // dr dc
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // bfs
    bool bfs(vector<vector<int>> &heights, int k) {
        // init bfs
        queue<pair<int, int>> q;
        vis[0][0] = true;
        q.push(make_pair(0, 0));

        // do bfs
        while (!q.empty()) {
            // get curr
            pair<int, int> curr = q.front();
            q.pop();

            // loop through neighbors
            for (int i = 0; i < 4; i++) {
                nextR = curr.first + dr[i];
                nextC = curr.second + dc[i];
                // if in bounds, can reach, and not visited
                if (0 <= nextR && nextR < m && 0 <= nextC && nextC < n && abs(heights[nextR][nextC] - heights[curr.first][curr.second]) <= k && !vis[nextR][nextC]) {
                    // if at bottom right
                    if (nextR == m - 1 && nextC == n - 1)
                        return true;
                    // otherwise continue with bfs
                    vis[nextR][nextC] = true;
                    q.push(make_pair(nextR, nextC));
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights) {
        // edge
        if (heights.size() == 1 && heights[0].size() == 1)
            return 0;

        // init
        m = heights.size(), n = heights[0].size();
        l = 0, r = 1e6;
        vis.resize(m, vector<bool>(n));

        // binary search k
        while (l < r) {
            // get mid and reset vis
            mid = l + (r - l) / 2;
            fill(vis.begin(), vis.end(), vector<bool>(n, false));
            // if it works update upper bound
            if (bfs(heights, mid))
                r = mid;
            // otherwise upper
            else
                l = mid + 1;
        }
        return l;
    }
};