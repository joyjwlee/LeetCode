class Solution {
  public:
    double knightProbability(int n, int k, int row, int column) {
        // dr dc arrays
        int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        int nextR, nextC;

        // make and set curr board
        vector<vector<double>> curr(n, vector<double>(n, 0.0));
        curr[row][column] = 1;

        // update k times
        for (int i = 0; i < k; i++) {
            // make and reset next board
            vector<vector<double>> next(n, vector<double>(n, 0.0));

            // loop through and populate next
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    // if knight has landed here
                    if (curr[r][c] != 0) {
                        // loop through 8 potential positions
                        for (int idx = 0; idx < 8; idx++) {
                            nextR = r + dr[idx];
                            nextC = c + dc[idx];
                            // if in bounds
                            if (0 <= nextR && nextR < n && 0 <= nextC && nextC < n)
                                next[nextR][nextC] += curr[r][c] / 8.0;
                        }
                    }
                }
            }

            // update curr to be next
            curr = next;
        }

        // calc answer and return
        double ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans += curr[i][j];
        return ans;
    }
};