class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0, psum = 0;
        unordered_map<int, int> mp;

        // O(n), single sweep
        for (int i = 0; i < nums.size(); i++) {
            // update psum
            psum += nums[i];
            // if psum same
            if (psum == k)
                ans++;
            // if diff of psum same
            if (mp[psum - k])
                ans += mp[psum - k];
            mp[psum]++;
        }
        return ans;
    }
};