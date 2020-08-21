class Solution {
  public:
    int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    int update(int r, int c, vector<vector<int>> &board) {
        int cnt = 0;
        // loop through each neighbor
        for (int i = 0; i < 8; i++)
            // in bounds
            if (0 <= r + dr[i] && r + dr[i] < board.size())
                if (0 <= c + dc[i] && c + dc[i] < board[0].size())
                    if (board[r + dr[i]][c + dc[i]])
                        cnt++;
        // with count, return state
        if (board[r][c]) {
            if (cnt < 2)
                return 0;
            if (cnt == 2 || cnt == 3)
                return 1;
            else
                return 0;
        }
        if (cnt == 3)
            return 1;
        // just put return here
        return 0;
    }

    void gameOfLife(vector<vector<int>> &board) {
        // create aux
        vector<vector<int>> nextState(board.size(), vector<int>(board[0].size(), 0));
        // simulate
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++)
                nextState[i][j] = update(i, j, board);
        // set board
        board = nextState;
    }
};