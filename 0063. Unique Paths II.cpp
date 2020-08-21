class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // edge
        if (obstacleGrid[0][0] == 1)
            return 0;

        // init horiz and vert
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        for (int i = 1; i < n; i++)
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        for (int i = 1; i < m; i++)
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;

        // dp through
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                // if we come aacross obstacle
                if (obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                // otherwise dp it
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }

        // return
        return obstacleGrid[n - 1][m - 1];
    }
};