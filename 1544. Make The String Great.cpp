class Solution {
  public:
    string makeGood(string s) {
        // stack and loop through
        stack<char> stk;
        for (char c : s) {
            // if empty, just add
            if (stk.empty()) {
                stk.push(c);
                continue;
            }
            // if upper and lower, remove
            else if (abs(c - stk.top()) == 32)
                stk.pop();
            // otherwise just add
            else
                stk.push(c);
        }

        // make string, reverse, and return
        s = "";
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};