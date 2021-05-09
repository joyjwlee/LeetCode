class Solution {
  public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        // init
        int row = grid.size(), col = grid[0].size(), tot = row * col;
        vector<vector<int>> ans(row, vector<int>(col));
        int index, newR, newC;

        // copy over to new array and return
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // get "index" as if it's stretched
                index = (i * col + j + k) % tot;
                // get new r and c
                newR = index / col;
                newC = index % col;
                ans[newR][newC] = grid[i][j];
            }
        }
        return ans;
    }
};