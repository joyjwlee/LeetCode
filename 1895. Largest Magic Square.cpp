class Solution {
  public:
    // vars
    int n, m, sum, diag, r, c;
    vector<vector<int>> pSumR, pSumC;

    // helper
    bool isMagicSquare(vector<vector<int>> &grid, int len) {
        // loop through all poss squares
        for (int i = 1; i <= n - len + 1; i++) {
            for (int j = 1; j <= m - len + 1; j++) {
                // set bool
                bool works = true;

                // get first row
                sum = pSumR[i][j + len - 1] - pSumR[i][j - 1];

                // check rows
                for (int k = i + 1; k < i + len; k++)
                    if (pSumR[k][j + len - 1] - pSumR[k][j - 1] != sum)
                        works = false;

                // check columns
                for (int k = j; k < j + len; k++)
                    if (pSumC[i + len - 1][k] - pSumC[i - 1][k] != sum)
                        works = false;

                // check \ diagonal
                diag = 0, r = i, c = j;
                r--, c--;
                for (int k = 0; k < len; k++) {
                    diag += grid[r][c];
                    r++;
                    c++;
                }
                if (diag != sum)
                    works = false;

                // check / diagonal
                diag = 0, r = i + len - 1, c = j;
                r--, c--;
                for (int k = 0; k < len; k++) {
                    diag += grid[r][c];
                    r--;
                    c++;
                }
                if (diag != sum)
                    works = false;

                // return true if it works
                if (works)
                    return true;
            }
        }
        // otherwise false
        return false;
    }

    int largestMagicSquare(vector<vector<int>> &grid) {
        // init
        n = grid.size(), m = grid[0].size();
        pSumR = vector(n + 2, vector<int>(m + 2, 0)), pSumC = vector(n + 2, vector<int>(m + 2, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pSumR[i][j] += grid[i - 1][j - 1] + pSumR[i][j - 1];
                pSumC[i][j] += grid[i - 1][j - 1] + pSumC[i - 1][j];
            }
        }

        // first one that works is highest
        for (int i = min(n, m); i >= 2; i--)
            if (isMagicSquare(grid, i))
                return i;
        return 1;
    }
};