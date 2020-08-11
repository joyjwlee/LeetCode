class Solution {
  public:
    bool isValid(string s) {
        // stack solution
        stack<char> S;
        for (int i = 0; i < s.size(); i++) {
            if (S.empty())
                S.push(s[i]);
            else if (s[i] == ')' && S.top() == '(')
                S.pop();
            else if (s[i] == '}' && S.top() == '{')
                S.pop();
            else if (s[i] == ']' && S.top() == '[')
                S.pop();
            else
                S.push(s[i]);
        }
        return S.size() == 0;
    }
};