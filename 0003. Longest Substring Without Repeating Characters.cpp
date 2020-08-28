class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        // init
        unordered_map<char, int> mp;
        int lft = 0, ans = 0;

        // two pointer sliding window
        for (int rgt = 0; rgt < s.size(); rgt++) {
            // as long as there's duplicate
            // move left pointer and remove
            while (mp[s[rgt]] != 0)
                mp[s[lft++]]--;
            // update answer
            mp[s[rgt]]++;
            if (rgt - lft + 1 > ans)
                ans = rgt - lft + 1;
        }
        return ans;
    }
};