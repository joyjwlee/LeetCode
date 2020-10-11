class Solution {
  public:
    vector<string> getFolderNames(vector<string> &names) {
        // vector of names, map for existing
        vector<string> ans;
        unordered_map<string, int> mp;

        // loop thru each name
        string temp;
        int i;
        for (string n : names) {
            temp = n, i = mp[temp];
            while (mp[temp] > 0) {
                temp = n + "(" + to_string(i++) + ")";
                mp[n] = i;
            }
            mp[temp]++;
            ans.push_back(temp);
        }
        return ans;
    }
};