class Solution {
  public:
    // consts
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    // true if in bounds, false otherwise
    bool inBounds(vector<vector<char>> &board, int r, int c) {
        int n = board.size(), m = board[0].size();
        if (0 <= r && r < n && 0 <= c && c < m)
            return true;
        return false;
    }

    // flood-fill region from orig to val
    void dfs(vector<vector<char>> &board, int r, int c, char orig, char val) {
        // if not orig, just return
        if (board[r][c] != orig)
            return;
        // otherwise, set to val and flood-fill in all directions
        board[r][c] = val;
        for (int i = 0; i < 4; i++)
            if (inBounds(board, r + dr[i], c + dc[i]))
                dfs(board, r + dr[i], c + dc[i], orig, val);
    }

    // set O-regions at boarder to space-regions
    void init(vector<vector<char>> &board) {
        int n = board.size();
        int m = board[0].size();

        // border: check left and right columns
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0, 'O', ' ');
            if (board[i][m - 1] == 'O')
                dfs(board, i, m - 1, 'O', ' ');
        }
        // border: check top and bottom rows
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(board, 0, i, 'O', ' ');
            if (board[n - 1][i] == 'O')
                dfs(board, n - 1, i, 'O', ' ');
        }
    }

    // convert regions from orig to val
    void setRegions(vector<vector<char>> &board, char orig, char val) {
        int n = board.size();
        int m = board[0].size();

        // loop thorugh all
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (board[i][j] == orig)
                    dfs(board, i, j, orig, val);
    }

    void solve(vector<vector<char>> &board) {
        // if O-regions at a border, impossible to be surrounded
        // therefore flood-fill those as ' ' (temporary marking)
        init(board);

        // then flood-fill all other O-regions as X
        setRegions(board, 'O', 'X');

        // revert ' ' back to O
        setRegions(board, ' ', 'O');
    }
};