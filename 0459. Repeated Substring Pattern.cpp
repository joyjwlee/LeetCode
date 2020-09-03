class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        // double the string, remove first and last char
        // if a pattern exists, s should exist in this new string
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};