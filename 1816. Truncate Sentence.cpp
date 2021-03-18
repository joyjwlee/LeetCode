class Solution {
  public:
    string truncateSentence(string s, int k) {
        int idx = 0, numWords = 0;
        while (numWords < k && idx < s.size()) {
            if (s[idx] == ' ')
                numWords++;
            idx++;
        }
        return (numWords + 1 == k) ? s.substr(0, idx) : s.substr(0, idx - 1);
    }
};