class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        // unordered for const retrieval time
        unordered_set<int> s;
        for (int i : nums)
            s.insert(i);

        // find and return
        int ans = 0, len = 0;
        for (int i : nums) {
            // if start of sequence
            if (s.find(i - 1) == s.end()) {
                len = 0;
                while (s.find(i + len) != s.end())
                    len++;
                ans = max(ans, len);
            }
        }
        return ans;
    }
};