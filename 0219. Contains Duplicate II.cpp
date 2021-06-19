class Solution {
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        // init
        unordered_map<int, int> m;

        // loop through and solve
        for (int i = 0; i < nums.size(); i++) {
            // if seen before and within k
            if (m.find(nums[i]) != m.end() && k >= abs(m[nums[i]] - i))
                return true;
            // otherwise index
            m[nums[i]] = i;
        }
        return false;
    }
};