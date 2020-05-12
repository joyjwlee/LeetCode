class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) {
            return 0;
        }

        // Get numbers
        int ans = 0;
        int R = grid.size();
        int C = grid[0].size();

        stack<pair<int, int>> s;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                // if we come across one
                if (grid[i][j] == '1') {
                    // take care of it
                    ans++;
                    grid[i][j] = '0';
                    s.push(pair(i, j));
                    // remove all adjecent neighbors
                    while (!s.empty()) {
                        pair curr = s.top();
                        s.pop();
                        int r = curr.first, c = curr.second;
                        if (r + 1 < R && grid[r + 1][c] == '1') {
                            s.push(pair(r + 1, c));
                            grid[r + 1][c] = '0';
                        }
                        if (r - 1 >= 0 && grid[r - 1][c] == '1') {
                            s.push(pair(r - 1, c));
                            grid[r - 1][c] = '0';
                        }
                        if (c + 1 < C && grid[r][c + 1] == '1') {
                            s.push(pair(r, c + 1));
                            grid[r][c + 1] = '0';
                        }
                        if (c - 1 >= 0 && grid[r][c - 1] == '1') {
                            s.push(pair(r, c - 1));
                            grid[r][c - 1] = '0';
                        }
                    }
                }
            }
        }

        return ans;
    }
};