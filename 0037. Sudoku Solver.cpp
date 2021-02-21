class Solution {
  public:
    // see if n can be placed in board[r][c]
    bool possible(vector<vector<char>> &board, int r, int c, char n) {
        // loop through row and column
        for (int i = 0; i < 9; i++) {
            // same row
            if (board[r][i] == n)
                return false;
            // same column
            if (board[i][c] == n)
                return false;
        }

        // loop through the 3x3, take floor
        int r0 = (r / 3) * 3;
        int c0 = (c / 3) * 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[r0 + i][c0 + j] == n)
                    return false;

        // otherwise return true
        return true;
    }

    void solveSudoku(vector<vector<char>> &board) {
        // Computerphile Video:
        // https://www.youtube.com/watch?v=G_UYXzGuqvM

        // if we're full, finish
        int blanks = 0;
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    blanks++;
        if (blanks == 0)
            return;

        // recursively loop through all
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                // if not taken
                if (board[i][j] == '.') {
                    // loop through all numbers
                    for (int i = 1; i < 9; i++) {
                        if (possible(board, i, j, (char)(i + '0'))) {
                            board[i][j] = (char)(i + '0');
                            solveSudoku(board);
                            board[i][j] = '.';
                        }
                    }
                    return;
                }
            }
        }
    }
};