class Solution {
  public:
    bool isSub(string s, string sub) {
        int i = 0, j = 0;
        for (; i < s.size(); i++) {
            if (s[i] == sub[j])
                j++;
            if (j == sub.size())
                return true;
        }
        return j == sub.size();
    }

    int numMatchingSubseq(string s, vector<string> &words) {
        int ans = 0;
        for (string str : words)
            if (isSub(s, str))
                ans++;
        return ans;
    }
};