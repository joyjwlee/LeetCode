class Solution {
  public:
    string sortSentence(string s) {
        string temp = "";
        vector<string> words;

        // parse and add
        for (char c : s) {
            // add and reset string
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            }
            // otherwise add
            if (isalpha(c))
                temp += c;
            else
                temp = c + temp;
        }
        words.push_back(temp);
        sort(words.begin(), words.end());

        string ans = "";
        for (string str : words) {
            for (char c : str)
                if (isalpha(c))
                    ans += c;
            ans += " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};