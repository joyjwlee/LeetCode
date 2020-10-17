class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        // answer
        vector<string> sequences;

        // edge case
        if (s.size() <= 10)
            return sequences;

        // create frequency
        unordered_map<string, int> freq;
        for (int i = 0; i <= s.size() - 10; i++)
            freq[s.substr(i, 10)]++;

        // loop and return
        for (auto i : freq)
            if (i.second >= 2)
                sequences.push_back(i.first);
        return sequences;
    }
};