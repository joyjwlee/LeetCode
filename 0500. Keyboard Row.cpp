class Solution {
  public:
    // helper function
    bool valid(string &s) {
        string topRow = "qwertyuiop";
        string midRow = "asdfghjkl";
        string botRow = "zxcvbnm";

        bool top = false, mid = false, bot = false;

        for (int i = 0; i < s.size(); i++) {
            // top
            if (topRow.find(s[i]) < topRow.length())
                top = true;
            // mid
            if (midRow.find(s[i]) < midRow.length())
                mid = true;
            // bot
            if (botRow.find(s[i]) < botRow.length())
                bot = true;
        }

        int cnt = 0;
        if (top)
            cnt++;
        if (mid)
            cnt++;
        if (bot)
            cnt++;
        return cnt == 1;
    }

    vector<string> findWords(vector<string> &words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            // make it lowercase
            string test = words[i];
            transform(test.begin(), test.end(), test.begin(), ::tolower);
            // check word
            if (valid(test))
                ans.push_back(words[i]);
        }
        return ans;
    }
};