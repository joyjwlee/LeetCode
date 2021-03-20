class Solution {
  public:
    string mergeAlternately(string word1, string word2) {
        // init
        string ans = "";
        int i = 0;
        // alternate
        while (i < word1.size() && i < word2.size()) {
            ans += word1[i];
            ans += word2[i];
            i++;
        }
        // add remaining and return
        while (i < word1.size())
            ans += word1[i++];
        while (i < word2.size())
            ans += word2[i++];
        return ans;
    }
};