class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        // create 2D vector
        vector<vector<int>> v(n, vector<int>(n));

        // populate vector
        int cnt = 1, i = 0, j = 0;
        while (cnt <= n * n) {
            // right
            while (j < n && v[i][j] == 0)
                v[i][j++] = cnt++;
            j--;
            i++;
            // down
            while (i < n && v[i][j] == 0)
                v[i++][j] = cnt++;
            i--;
            j--;
            // left
            while (j >= 0 && v[i][j] == 0)
                v[i][j--] = cnt++;
            j++;
            i--;
            // up
            while (i >= 0 && v[i][j] == 0)
                v[i--][j] = cnt++;
            i++;
            j++;
        }

        return v;
    }
};