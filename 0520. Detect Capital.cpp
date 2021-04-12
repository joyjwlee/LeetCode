class Solution {
  public:
    bool detectCapitalUse(string word) {
        // count number of capitals
        int cnt = 0;
        for (char c : word)
            if ('A' <= c && c <= 'Z')
                cnt++;

        // return ans
        if (cnt == 0 || cnt == word.size())
            return true;
        if (cnt == 1)
            return ('A' <= word[0] && word[0] <= 'Z') ? true : false;
        return false;
    }
};