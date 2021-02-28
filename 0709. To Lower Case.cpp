class Solution {
  public:
    string toLowerCase(string str) {
        string ans = "";
        for (char c : str) {
            if (65 <= c && c <= 90)
                ans += (char)(c + 32);
            else
                ans += c;
        }
        return ans;
    }
};