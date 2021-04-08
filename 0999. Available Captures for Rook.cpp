class Solution {
  public:
    int numRookCaptures(vector<vector<char>> &board) {
        // init
        int n = board.size(), m = board[0].size();
        int ans = 0;

        // find rook and traverse
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // if at rook
                if (board[i][j] == 'R') {
                    // up
                    for (int k = i; k >= 0; k--) {
                        if (board[k][j] == 'B')
                            break;
                        else if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    // down
                    for (int k = i; k < 8; k++) {
                        if (board[k][j] == 'B')
                            break;
                        else if (board[k][j] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    // left
                    for (int k = j; k >= 0; k--) {
                        if (board[i][k] == 'B')
                            break;
                        else if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                    // right
                    for (int k = j; k < 8; k++) {
                        if (board[i][k] == 'B')
                            break;
                        else if (board[i][k] == 'p') {
                            ans++;
                            break;
                        }
                    }
                }
            }
        }

        // return
        return ans;
    }
};