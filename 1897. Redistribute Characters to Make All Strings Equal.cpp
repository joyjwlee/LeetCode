class Solution {
  public:
    bool makeEqual(vector<string> &words) {
        // init
        map<char, int> freq;
        for (string s : words)
            for (char c : s)
                freq[c]++;

        // solve and return
        for (auto i : freq)
            if (i.second % words.size() != 0)
                return false;
        return true;
    }
};