class Solution {
  public:
    vector<int> sequentialDigits(int low, int high) {
        // init
        string s = "123456789";
        int n = s.size();
        vector<int> ans;

        // loop through, generate
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // get potential val
                int poten = stoi(s.substr(i, j - i + 1));
                // if between vals
                if (low <= poten && poten <= high)
                    ans.push_back(poten);
            }
        }

        // sort and return
        sort(ans.begin(), ans.end());
        return ans;
    }
};