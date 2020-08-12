class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        // keep track of digits
        int zeros[10];
        // horiz
        for (int i = 0; i < board.size(); i++) {
            memset(zeros, 0, sizeof(zeros));
            for (int j = 0; j < board[i].size(); j++) {
                if (isdigit(board[i][j])) {
                    zeros[(int)board[i][j] - '0']++;
                    if (zeros[(int)board[i][j] - '0'] > 1)
                        return false;
                }
            }
        }
        // vert
        for (int i = 0; i < board[0].size(); i++) {
            memset(zeros, 0, sizeof(zeros));
            for (int j = 0; j < board.size(); j++) {
                if (isdigit(board[j][i])) {
                    zeros[(int)board[j][i] - '0']++;
                    if (zeros[(int)board[j][i] - '0'] > 1)
                        return false;
                }
            }
        }
        // check each 3x3
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < board[i].size(); j += 3) {
                memset(zeros, 0, sizeof(zeros));
                // loop through 3x3
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (isdigit(board[i + k][j + l])) {
                            zeros[(int)board[i + k][j + l] - '0']++;
                            if (zeros[(int)board[i + k][j + l] - '0'] > 1)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};