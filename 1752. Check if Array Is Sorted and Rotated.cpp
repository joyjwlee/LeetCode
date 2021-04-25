class Solution {
  public:
    bool check(vector<int> &nums) {
        // init
        int n = nums.size(), j;
        bool decrease = false;

        // loop through
        for (int i = 0; i < n; i++) {
            // j is the index to the right
            j = (i + 1) % n;
            // in order, continue
            if (nums[i] <= nums[j])
                continue;
            // otherwise return or set bool
            if (decrease)
                return false;
            decrease = true;
        }
        return true;
    }
};