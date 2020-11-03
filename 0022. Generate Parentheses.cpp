class Solution {
  public:
    vector<string> ans;

    // helper method to generate recursively
    void generate(int open, int close, int n, string s) {
        // always must have more open than close at any time
        if (close > open)
            return;
        // if more than n
        if (open > n)
            return;
        // add if reach n
        if (open == n && open == close) {
            ans.push_back(s);
            return;
        }
        // otherwise, generate
        generate(open + 1, close, n, s + "(");
        generate(open, close + 1, n, s + ")");
    }

    vector<string> generateParenthesis(int n) {
        generate(0, 0, n, "");
        return ans;
    }
};