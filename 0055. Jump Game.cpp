class Solution {
  public:
    bool canJump(vector<int> &nums) {
        // init
        int maxPos = 0;

        // loop through
        for (int i = 0; i < nums.size(); i++)
            if (maxPos >= i)
                maxPos = max(maxPos, i + nums[i]);
        return maxPos >= nums.size() - 1;
    }
};