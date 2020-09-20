class Solution {
  public:
    string reverseWords(string s) {
        // stack to keep track
        stack<string> stk;

        // stringstream, add to stack
        stringstream stream(s);
        string word;
        while (stream >> word)
            stk.push(word);

        // concat, remove last whitespace, return
        string ans = "";
        while (!stk.empty()) {
            ans += stk.top();
            ans += " ";
            stk.pop();
        }
        return ans.substr(0, ans.size() - 1);
    }
};