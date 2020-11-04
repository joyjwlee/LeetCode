class Solution {
  public:
    string convert(string s, int numRows) {
        // edge
        if (numRows == 1)
            return s;

        // create a vector to actually make zig zag, set all to period
        vector<vector<char>> zigzag(numRows, vector<char>(s.size()));

        // put into zig zag
        int i = 0, j = 0, cnt = 0;
        while (cnt < s.size()) {
            // go down first
            while (i < numRows && cnt < s.size()) {
                zigzag[i][j] = s[cnt];
                cnt++;
                i++;
            }
            i -= 2;
            j++;
            // go up right
            while (i >= 0 && cnt < s.size()) {
                zigzag[i][j] = s[cnt];
                cnt++;
                i--;
                j++;
            }
            i += 2;
            j--;
        }

        // take zig zag, concatenate
        string ans = "";
        for (int i = 0; i < numRows; i++)
            for (int j = 0; j < s.size(); j++)
                if (zigzag[i][j] != NULL)
                    ans += zigzag[i][j];
        return ans;
    }
};