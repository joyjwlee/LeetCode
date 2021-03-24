class Solution {
  public:
    bool isPalin(string s) {
        for (int i = 0; i < s.size() / 2; i++)
            if (s[i] != s[s.size() - i - 1])
                return false;
        return true;
    }

    bool validPalindrome(string s) {
        // return if s itself is palindrome
        if (isPalin(s))
            return true;

        // otherwise we have diff, make 2 strings
        int idx = 0;
        while (s[idx] == s[s.size() - idx - 1])
            idx++;
        string a = "", b = "";
        for (int i = 0; i < s.size(); i++) {
            if (i == idx)
                continue;
            a += s[i];
        }
        for (int i = 0; i < s.size(); i++) {
            if (i == s.size() - idx - 1)
                continue;
            b += s[i];
        }

        return isPalin(a) || isPalin(b);
    }
};