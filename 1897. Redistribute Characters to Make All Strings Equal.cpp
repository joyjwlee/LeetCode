class Solution {
  public:
    bool makeEqual(vector<string> &words) {
        // init
        int freq[26] = {0};
        for (string s : words)
            for (char c : s)
                freq[c - 'a']++;

        // solve and return
        for (int i : freq)
            if (i != 0 && i % words.size() != 0)
                return false;
        return true;
    }
};

/*
// orig solution with map
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
*/