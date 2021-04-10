class Solution {
  public:
    string restoreString(string s, vector<int> &indices) {
        // init
        vector<pair<int, char>> shuffled;
        string ans = "";

        // loop through and sort
        for (int i = 0; i < s.size(); i++)
            shuffled.push_back(make_pair(indices[i], s[i]));
        sort(shuffled.begin(), shuffled.end());

        // concatenate and return
        for (int i = 0; i < shuffled.size(); i++)
            ans += shuffled[i].second;
        return ans;
    }
};