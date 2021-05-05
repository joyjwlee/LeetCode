class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // solution coming soon...
    }
};

/*
// original solution (OLE, TLE)
// edge
        int cnt = 0;
        for (char c : s)
            if (c == '.')
                cnt++;
        if (cnt == s.size())
            return true;
        
        // loop and recur
        for (string word : wordDict) {
            // if word is in s
            // cout << s << " || " << word << endl;
            int startPosToErase = s.find(word);
            if (startPosToErase != -1) {
                // remove current word and add delim
                s.erase(startPosToErase, word.size());
                s.insert(startPosToErase, ".");
                // if possible return true
                if (wordBreak(s, wordDict))
                    return true;
                // otherwise delete delim and put it back
                s.erase(startPosToErase, 1);
                s.insert(startPosToErase, word);
            }
        }
        return false;
*/