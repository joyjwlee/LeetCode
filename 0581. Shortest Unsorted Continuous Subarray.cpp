class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        // make lo & hi pointers and min & max
        int n = nums.size();
        int lo = -1, hi = -2; // vals for return without if
        int min = 0x3f3f3f3f, max = -0x3f3f3f3f;

        // single loop for both pointers and return
        for (int i = 0; i < n; i++) {
            // update min and max
            max = std::max(max, nums[i]);
            min = std::min(min, nums[n - i - 1]);

            // update pointers
            if (max > nums[i])
                hi = i;
            if (min < nums[n - i - 1])
                lo = n - i - 1;
        }
        return hi - lo + 1;
    }
};