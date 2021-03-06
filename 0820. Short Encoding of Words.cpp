class Solution {
  public:
    int minimumLengthEncoding(vector<string> &words) {
        // sort by size
        sort(words.begin(), words.end(), [](string a, string g) {
            return a.size() > g.size();
        });

        // make encoded string amd return size
        string code = "";
        for (string s : words) {
            // if cannot be found in encoded, add
            if (code.find(s + '#') == -1)
                code += (s + '#');
        }
        return code.size();
    }
};