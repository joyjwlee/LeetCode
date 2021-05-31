class Solution {
  public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int ans = 0, temp = 0;
        for (int i = 0; i < accounts.size(); i++) {
            temp = 0;
            for (int j = 0; j < accounts[0].size(); j++)
                temp += accounts[i][j];
            ans = max(ans, temp);
        }
        return ans;
    }
};