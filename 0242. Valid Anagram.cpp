class Solution {
  public:
    bool isAnagram(string s, string t) {
        // quick check with size
        if (s.size() != t.size())
            return false;
        // sort string
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        // compare
        for (int i = 0; i < s.size(); i++)
            if (s[i] != t[i])
                return false;
        return true;
    }
};