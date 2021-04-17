class Solution {
  public:
    string removeDuplicates(string s, int k) {
        // stack through
        stack<pair<char, int>> stk;
        int freq = 0;

        // loop through
        for (char c : s) {
            // if empty, add
            if (stk.empty())
                stk.push(make_pair(c, 1));
            // if same as previous, +1
            else if (c == stk.top().first)
                stk.push(make_pair(c, stk.top().second + 1));
            // otherwise restart
            else
                stk.push(make_pair(c, 1));
            // if top val is k
            if (stk.top().second == k)
                for (int i = 0; i < k; i++)
                    stk.pop();
        }

        // concatenate and return
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top().first;
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};