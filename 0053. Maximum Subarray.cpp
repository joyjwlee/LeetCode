class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int max = INT_MIN, temp = INT_MIN;
        // Kadane's Algorithm
        for (int i = 0; i < nums.size(); i++) {
            if (temp < 0)
                temp = 0;
            temp += nums[i];
            if (temp > max)
                max = temp;
        }
        return max;
    }
};