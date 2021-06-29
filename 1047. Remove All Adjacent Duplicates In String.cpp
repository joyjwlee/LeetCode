class Solution {
  public:
    string removeDuplicates(string S) {
        // stack solution
        stack<char> s;
        for (char c : S) {
            // if empty or not same, add
            if (s.empty() || s.top() != c)
                s.push(c);
            // if same, remove from stack
            else
                s.pop();
        }

        // return stack as string
        string ans = "";
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};