class Solution {
  public:
    // helper for square number
    char smallest(char a, char b, char c) {
        if (a <= b && a <= c)
            return a;
        if (b <= a && b <= c)
            return b;
        return c;
    }

    int maximalSquare(vector<vector<char>> &matrix) {
        // dp: i,j is size of largest square
        for (int i = 1; i < matrix.size(); i++)
            for (int j = 1; j < matrix[i].size(); j++)
                // if not 0, update its size
                // top, left, and top-left
                if (matrix[i][j] == '1')
                    matrix[i][j] = smallest(matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]) + 1;

        // loop through, find answer, and return
        int ans = '0';
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (matrix[i][j] > ans)
                    ans = matrix[i][j];
        ans -= '0';
        return ans * ans;
    }
};