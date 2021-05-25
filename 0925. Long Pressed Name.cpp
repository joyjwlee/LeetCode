class Solution {
  public:
    // helper
    vector<pair<char, int>> charFreq(string name) {
        // init
        vector<pair<char, int>> vec;
        char curr = name[0];
        int freq = 1;

        // loop through
        for (int i = 1; i < name.size(); i++) {
            if (name[i] == curr)
                freq++;
            else {
                vec.push_back(make_pair(curr, freq));
                curr = name[i];
                freq = 1;
            }
        }

        // get last and return
        vec.push_back(make_pair(curr, freq));
        return vec;
    }

    bool isLongPressedName(string name, string typed) {
        // init
        vector<pair<char, int>> n, t;
        n = charFreq(name);
        t = charFreq(typed);
        int m = min(n.size(), t.size());

        // loop and return
        if (n.size() != t.size())
            return false;
        for (int i = 0; i < m; i++) {
            if (n[i].first != t[i].first)
                return false;
            if (n[i].second > t[i].second)
                return false;
        }
        return true;
    }
};