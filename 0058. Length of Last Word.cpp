class Solution {
  public:
    int lengthOfLastWord(string s) {
        // remove whitespace at the end
        int end = s.size() - 1;
        while (end > 0 && s[end] == ' ')
            end--;
        end++;

        // if a space, reset; otherwise, add
        int ans = 0;
        for (int i = 0; i < end; i++) {
            if (s[i] == ' ')
                ans = 0;
            else
                ans++;
        }
        return ans;
    }
};