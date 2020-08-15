class Solution {
  public:
    // helper function
    bool isVowel(char s) {
        if (s == 'a')
            return true;
        if (s == 'e')
            return true;
        if (s == 'i')
            return true;
        if (s == 'o')
            return true;
        if (s == 'u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int max = 0, window = 0;

        // get init window val
        for (int i = 0; i < k; i++)
            if (isVowel(s[i]))
                window++;
        max = window;

        // slide through
        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i - k]))
                window--;
            if (isVowel(s[i]))
                window++;
            if (window > max)
                max = window;
        }
        return max;
    }
};