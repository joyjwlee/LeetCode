class Solution {
  public:
    string reorderSpaces(string text) {
        // get spaces
        int spaces = 0;
        for (char c : text)
            if (c == ' ')
                spaces++;

        // parse text, put into vector
        vector<string> words;
        stringstream s(text);
        string word;
        while (s >> word)
            words.push_back(word);

        // edge
        if (words.size() == 1) {
            for (int i = 0; i < spaces; i++)
                words[0] += " ";
            return words[0];
        }

        // make strings for between and end
        string between = "", end = "";
        for (int i = 0; i < spaces / (words.size() - 1); i++)
            between += " ";
        for (int i = 0; i < spaces % (words.size() - 1); i++)
            end += " ";

        // concatenate and return; -1 for end
        string ans = "";
        for (int i = 0; i < words.size() - 1; i++) {
            ans += words[i];
            ans += between;
        }
        ans += words[words.size() - 1];
        ans += end;
        return ans;
    }
};