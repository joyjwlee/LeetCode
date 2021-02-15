class Solution {
  public:
    int minOperations(vector<string> &logs) {
        int ans = 0;
        for (string s : logs) {
            // back
            if (s == "../") {
                if (ans > 0) {
                    ans--;
                }
            }
            // stay
            else if (s == "./")
                continue;
            // deeper
            else
                ans++;
        }
        return max(ans, 0);
    }
};