class Solution {
  public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        // populate vector and sort
        vector<pair<int, int>> vec;
        int sum = 0;
        for (int i = 0; i < mat.size(); i++) {
            sum = 0;
            for (int j = 0; j < mat[i].size(); j++)
                sum += mat[i][j];
            vec.push_back(make_pair(sum, i));
        }
        sort(vec.begin(), vec.end());

        // create answer and return
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(vec[i].second);
        return ans;
    }
};