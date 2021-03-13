class Solution {
  public:
    string reverseOnlyLetters(string S) {
        // stack
        stack<char> stk;
        for (char c : S)
            if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
                stk.push(c);
        // replace and return
        for (int i = 0; i < S.size(); i++) {
            if (('a' <= S[i] && S[i] <= 'z') || ('A' <= S[i] && S[i] <= 'Z')) {
                S[i] = stk.top();
                stk.pop();
            }
        }
        return S;
    }
};