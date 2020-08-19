class Solution {
  public:
    // helper method
    bool isValid(char c) {
        if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'))
            return true;
        return false;
    }

    bool isPalindrome(string s) {
        // s to lowercase
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // get only good ones
        vector<char> v;
        for (int i = 0; i < s.size(); i++)
            if (isValid(s[i]))
                v.push_back(s[i]);
        // compare with reverse and return
        string orig = "", rev = "";
        for (int i = 0; i < v.size(); i++)
            orig += v[i];
        for (int i = v.size() - 1; i >= 0; i--)
            rev += v[i];
        return orig.compare(rev) == 0;
    }
};