class Solution {
  public:
    int firstUniqChar(string s) {
        // get frequencies
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        // get all the ones with only 1
        vector<char> v;
        for (auto i : mp)
            if (i.second == 1)
                v.push_back(i.first);
        // if none
        if (v.size() == 0)
            return -1;
        // otherwise find first
        int ans = INT_MAX, idx;
        for (char c : v) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == c) {
                    if (i < ans)
                        ans = i;
                    break;
                }
            }
        }
        return ans;
    }
};