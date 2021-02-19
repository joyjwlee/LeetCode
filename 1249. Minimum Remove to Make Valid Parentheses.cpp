class Solution {
  public:
    string minRemoveToMakeValid(string s) {
        // stack to keep track of indices of paren
        stack<int> idx;
        for (int i = 0; i < s.size(); i++) {
            // keep track of open
            if (s[i] == '(') {
                idx.push(i);
            }
            // with closed, cancel or mark
            else if (s[i] == ')') {
                if (!idx.empty())
                    idx.pop();
                else
                    s[i] = '#';
            }
        }
        // set markings for remaining open
        while (!idx.empty()) {
            s[idx.top()] = '#';
            idx.pop();
        }

        // create ans and return
        string ans = "";
        for (char c : s)
            if (c != '#')
                ans += c;
        return ans;
    }
};