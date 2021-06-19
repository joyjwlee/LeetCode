class Solution {
  public:
    string licenseKeyFormatting(string s, int k) {
        // init
        string ans = "";
        int n = 0;

        // loop through and build
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != '-') {
                n++;
                if (isalpha(s[i]))
                    ans += (char)toupper(s[i]);
                else
                    ans += s[i];
                if (n % k == 0)
                    ans += '-';
            }
        }

        // reverse and return
        reverse(ans.begin(), ans.end());
        return (ans[0] != '-') ? ans : ans.substr(1);
    }
};