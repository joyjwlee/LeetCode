class Solution {
  public:
    void reverseString(vector<char> &s) {
        // init
        int n = s.size();
        char temp;
        // loop to half, swap
        for (int i = 0; i < n / 2; i++) {
            temp = s[i];
            s[i] = s[n - i - 1];
            s[n - i - 1] = temp;
        }
    }
};