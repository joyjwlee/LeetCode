class Solution {
  public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int max = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            // increase count if 1, otherwise reset
            if (nums[i] == 1)
                cnt++;
            else
                cnt = 0;
            if (cnt > max)
                max = cnt;
        }
        return max;
    }
};