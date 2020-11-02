class Solution {
  public:
    int findLengthOfLCIS(vector<int> &nums) {
        // edge
        if (nums.size() == 0)
            return 0;

        // loop through and find
        int ans = 1, temp = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                temp++;
                if (temp > ans)
                    ans = temp;
            } else {
                temp = 1;
            }
        }
        return ans;
    }
};