class Solution {
  public:
    int maxLengthBetweenEqualCharacters(string s) {
        // keep track of first and last indices and set to -1
        vector<int> lft(30, -1);
        vector<int> rgt(30, -1);

        // get left
        for (int i = 0; i < s.size(); i++) {
            int idx = s[i] - 'a';
            if (lft[idx] == -1)
                lft[idx] = i;
        }

        // get right
        for (int i = s.size() - 1; i >= 0; i--) {
            int idx = s[i] - 'a';
            if (rgt[idx] == -1)
                rgt[idx] = i;
        }

        // get max diff and return
        int ans = -1, diff;
        for (int i = 0; i < 26; i++) {
            if (lft[i] == -1 || rgt[i] == -1)
                continue;
            diff = rgt[i] - lft[i] - 1;
            if (diff > ans)
                ans = diff;
        }
        return ans;
    }
};