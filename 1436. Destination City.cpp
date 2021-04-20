class Solution {
  public:
    string destCity(vector<vector<string>> &paths) {
        // put into map
        map<string, string> mp;
        for (int i = 0; i < paths.size(); i++)
            mp[paths[i][0]] = paths[i][1];

        // iterate through
        string curr = paths[0][0];
        while (mp[curr] != "")
            curr = mp[curr];
        return curr;
    }
};