class Solution {
  public:
    string tictactoe(vector<vector<int>> &moves) {
        // make 3x3 board
        vector<vector<string>> v(3, vector<string>(3, "0"));

        // get input
        for (int i = 0; i < moves.size(); i++) {
            if (i % 2 == 0)
                v[moves[i][0]][moves[i][1]] = "A";
            else
                v[moves[i][0]][moves[i][1]] = "B";
        }

        // check row/col
        for (int i = 0; i < 3; i++) {
            // no need to check for third, transitive
            if (v[i][0] != "0" && v[i][0] == v[i][1] && v[i][1] == v[i][2])
                return v[i][0];
            if (v[0][i] != "0" && v[0][i] == v[1][i] && v[1][i] == v[2][i])
                return v[0][i];
        }

        // check diagonals (no need for third, transitive property)
        if (v[0][0] != "0" && v[0][0] == v[1][1] && v[1][1] == v[2][2])
            return v[0][0];
        if (v[0][2] != "0" && v[0][2] == v[1][1] && v[1][1] == v[2][0])
            return v[0][2];

        // otherwise draw or pending
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};