class Solution {
  public:
    int numSpecial(vector<vector<int>> &mat) {
        // just loop through and count
        int ans = 0, horiz = 0, vert = 0;
        // loop to each point
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                // get horiz and voert
                horiz = 0, vert = 0;
                for (int k = 0; k < mat[i].size(); k++)
                    horiz += mat[i][k];
                for (int k = 0; k < mat.size(); k++)
                    vert += mat[k][j];
                if (mat[i][j] == 1 && horiz == 1 && vert == 1)
                    ans++;
            }
        }
        return ans;
    }
};