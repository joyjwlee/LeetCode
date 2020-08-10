class Solution {
  public:
    string removeDuplicates(string S) {
        // stack solution
        stack<char> s;
        for (int i = 0; i < S.size(); i++) {
            // if empty or not same, add
            if (s.empty() || s.top() != S[i])
                s.push(S[i]);
            // if same, remove from stack
            else
                s.pop();
        }
        // return stack as string
        string ans = "";
        while (!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        return ans;
    }
};