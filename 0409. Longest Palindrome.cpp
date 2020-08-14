class Solution {
  public:
    int longestPalindrome(string s) {
        // get character frequency
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]]++;

        // calculate answer
        int ans = 0;
        bool hasOdd = false;
        for (auto itr : mp) {
            ans += itr.second;
            if (itr.second % 2 == 1) {
                ans--;
                hasOdd = true;
            }
        }
        return (hasOdd) ? ans + 1 : ans;
    }
};