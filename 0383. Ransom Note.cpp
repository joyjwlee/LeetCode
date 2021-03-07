class Solution {
  public:
    bool canConstruct(string ransomNote, string magazine) {
        // vectors to keep track of frequencies
        vector<int> rFreq(26, 0);
        vector<int> mFreq(26, 0);

        // count frequencies
        for (char c : ransomNote)
            rFreq[c - 'a']++;
        for (char c : magazine)
            mFreq[c - 'a']++;

        // loop through both
        for (int i = 0; i < 26; i++)
            if (mFreq[i] < rFreq[i])
                return false;
        return true;
    }
};