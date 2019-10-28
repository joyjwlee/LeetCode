class Solution {
  public:
    string modifyString(string s) {
        int n = s.size();

        // edge
        if (n == 1)
            return (s[0] == '?') ? "a" : s;

        // first char
        if (s[0] == '?') {
            s[0] = 'a';
            if (s[1] != '?')
                while (s[0] == s[1])
                    s[0]++;
        }

        // loop through, look for '?'
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '?') {
                // set to 'a', loop until ok
                s[i] = 'a';
                while (s[i] == s[i - 1] || s[i] == s[i + 1])
                    s[i]++;
            }
        }

        // last char
        if (s[n - 1] == '?') {
            s[n - 1] = 'a';
            while (s[n - 1] == s[n - 2])
                s[n - 1]++;
        }

        return s;
    }
};