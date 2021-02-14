class Solution {
  public:
    string makeString(string str) {
        // make stack
        stack<char> stk;
        for (char c : str) {
            if (c == '#') {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else
                stk.push(c);
        }

        // make string and return
        str = "";
        while (!stk.empty()) {
            str += stk.top();
            stk.pop();
        }
        return str;
    }

    bool backspaceCompare(string S, string T) {
        return makeString(S) == makeString(T);
    }
};