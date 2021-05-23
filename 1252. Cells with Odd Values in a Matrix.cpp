class Solution {
  public:
    int oddCells(int m, int n, vector<vector<int>> &indices) {
        // init
        map<int, int> row, col;
        for (int i = 0; i < indices.size(); i++) {
            row[indices[i][0]]++;
            col[indices[i][1]]++;
        }

        // solve and return
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if ((row[i] + col[j]) % 2)
                    ans++;
        return ans;
    }
};