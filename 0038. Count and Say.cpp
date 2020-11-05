class Solution {
  public:
    // helper method to update
    string update(string s) {
        // str is return, n is number, and curr is curr
        vector<pair<char, int>> vec;
        int n = 1;
        for (int i = 0; i < s.size() - 1; i++) {
            // if same, increase
            if (s[i] == s[i + 1])
                n++;
            // otherwise add to vector and reset
            else {
                vec.push_back({s[i], n});
                n = 1;
            }
        }
        vec.push_back({s[s.size() - 1], n});

        // concatenate
        string str = "";
        for (int i = 0; i < vec.size(); i++) {
            str += vec[i].second + '0';
            str += vec[i].first;
        }
        return str;
    }

    string countAndSay(int n) {
        // edge
        if (n == 1)
            return "1";
        string ans = "11";
        for (int i = 0; i < n - 2; i++) {
            cout << ans << endl;
            ans = update(ans);
        }
        return ans;
    }
};