class Solution {
  public:
    int dominantIndex(vector<int> &nums) {
        // edge
        if (nums.size() < 2)
            return 0;

        // init
        int a = INT_MIN, b = INT_MIN, aIdx = 0;

        // find largest
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > a) {
                a = nums[i];
                aIdx = i;
            }
        }

        // find second largest
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != a && nums[i] > b)
                b = nums[i];

        // return ans
        return (a >= 2 * b) ? aIdx : -1;
    }
};