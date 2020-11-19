class Solution {
  public:
    int countSegments(string s) {
        // just loop through
        int ans = 0, i = 0;
        bool atStart = true;
        while (i < s.size()) {
            if (s[i] != ' ') {
                i++;
                if (atStart)
                    ans++;
                atStart = false;
            } else {
                i++;
                atStart = true;
            }
        }
        return ans;
    }
};