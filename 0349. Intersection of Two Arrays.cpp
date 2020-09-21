class Solution {
  public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // umap to keep track of count
        unordered_map<int, int> cnt;

        // for nums 1, just keep it at 1
        for (int n : nums1)
            if (cnt[n] == 0)
                cnt[n]++;

        // for nums 2, just keep it at 2
        for (int n : nums2)
            if (cnt[n] == 1)
                cnt[n]++;

        // whatever is 2, add to vector
        vector<int> ans;
        for (auto i : cnt)
            if (i.second == 2)
                ans.push_back(i.first);
        return ans;
    }
};