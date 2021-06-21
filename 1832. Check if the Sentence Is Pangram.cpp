class Solution {
  public:
    bool checkIfPangram(string sentence) {
        int freq[26] = {0};
        for (char c : sentence)
            freq[c - 'a']++;
        for (int i : freq)
            if (i == 0)
                return false;
        return true;
    }
};