class Solution {
  public:
    string frequencySort(string s) {
        // create a umap
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;
        // set to vector, sort
        vector<pair<int, char>> v;
        for (auto i : mp)
            v.push_back({i.second, i.first});
        sort(v.begin(), v.end());
        // concatenate
        string concat = "";
        for (pair<int, char> n : v)
            for (int i = 0; i < n.first; i++)
                concat += n.second;
        // reverse
        string ans = "";
        for (int i = concat.size() - 1; i >= 0; i--)
            ans += concat[i];
        return ans;
    }
};