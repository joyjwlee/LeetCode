class Solution {
  public:
    // vars
    int i, j, ans;
    unordered_map<string, int> st;

    bool isSub(string s, string sub) {
        i = 0, j = 0;
        for (; i < s.size(); i++) {
            if (s[i] == sub[j])
                j++;
            if (j == sub.size())
                return true;
        }
        return j == sub.size();
    }

    int numMatchingSubseq(string s, vector<string> &words) {
        // init
        ans = 0;
        for (string str : words)
            st[str]++;

        // loop through and return
        for (auto i : st)
            if (isSub(s, i.first))
                ans += i.second;
        return ans;
    }
};

    /*
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
    */