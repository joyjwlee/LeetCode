class Solution {
public:
    int full = (1 << 9) - 1;
    vector<int> rs = vector<int>(9, full);
    vector<int> cs = vector<int>(9, full);
    vector<int> bs = vector<int>(9, full);

    vector<vector<int>> bd = vector<vector<int>>(9, vector<int>(9));

    void flip(int r, int c, int bit) {
        rs[r] ^= bit;
        cs[c] ^= bit;
        bs[r / 3 * 3 + c / 3] ^= bit;
        bd[r][c] ^= bit;
    }

    bool aux(int id = 0) {
        if (id == 81)
            return true;
        int r = id / 9, c = id % 9;
        int b = r / 3 * 3 + c / 3;
        if (bd[r][c] != 0)
            return aux(id + 1);
        int opt = (rs[r] & cs[c] & bs[b]);
        while (opt) {
            int low = ((opt - 1) ^ opt) & opt;
            opt ^= low;
            flip(r, c, low);
            if (aux(id + 1))
                return true;
            flip(r, c, low);
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int bit = 1 << (board[i][j] - '1');
                    flip(i, j, bit);
                }
            }
        }
        aux();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int k = 0;
                while ((bd[i][j] >> k) > 0) {
                    k++;
                }
                board[i][j] = (char)('0' + k);
            }
        }
    }
};