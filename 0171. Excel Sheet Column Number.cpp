class Solution {
  public:
    int titleToNumber(string s) {
        // loop backwards and return answer
        long int ans = 0, pwr = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            ans += pwr * (s[i] - 'A' + 1);
            pwr *= 26;
        }
        return ans;
    }
};