class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;

        // index the grid
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // fresh
                if (grid[i][j] == 1)
                    fresh++;
                else if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        // dr dc arrays
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};

        // get the time
        int time = 0;
        while (!q.empty() && fresh > 0) {
            time++;
            // simulate the rotting
            int curr = q.size();
            // only the ones in queue right now
            for (int i = 0; i < curr; i++) {
                int currR = q.front().first;
                int currC = q.front().second;
                q.pop();
                // go to each direction
                for (int j = 0; j < 4; j++) {
                    int nextR = currR + dr[j];
                    int nextC = currC + dc[j];
                    // if in bounds
                    if (0 <= nextR && nextR < grid.size()) {
                        if (0 <= nextC && nextC < grid[0].size()) {
                            // if fresh
                            if (grid[nextR][nextC] == 1) {
                                q.push({nextR, nextC});
                                grid[nextR][nextC] = 2;
                                fresh--;
                            }
                        }
                    }
                }
            }
        }

        return (fresh == 0) ? time : -1;
    }
};