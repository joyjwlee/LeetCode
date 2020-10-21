class Solution {
  public:
    int maxDepth(string s) {
        int depth = 0, ans = 0;
        for (char c : s) {
            if (c == '(')
                depth++;
            else if (c == ')')
                depth--;
            if (depth > ans)
                ans = depth;
        }
        return ans;
    }
};