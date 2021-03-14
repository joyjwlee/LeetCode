class Solution {
  public:
    int thirdMax(vector<int> &nums) {
        // make each value unique (sort and erase)
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // edge
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return (nums[0] > nums[1]) ? nums[0] : nums[1];

        // 3 vals to keep track
        int high = INT_MIN, mid = INT_MIN, low = INT_MIN;

        // loop thru each number
        for (int i : nums) {
            // curr is highest
            if (i > high) {
                low = mid;
                mid = high;
                high = i;
            }
            // curr is second
            else if (i > mid && i != high) {
                low = mid;
                mid = i;
            }
            // curr is third
            else if (i > low && i != mid && i != high) {
                low = i;
            }
        }

        // return ans
        if (low == INT_MIN) {
            for (int i : nums)
                if (i == INT_MIN)
                    return low;
            return high;
        }
        return low;
    }
};